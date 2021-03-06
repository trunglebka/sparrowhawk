from typing import Any, Dict, Tuple, TypedDict, Union
from datetime import datetime
from asyncio import CancelledError, Future
import asyncio
import time
import json
import uuid
import logging

from redis import asyncio as aioredis
from fastapi import FastAPI
import uvicorn


logging.basicConfig(format='%(asctime)s.%(msecs)03d %(levelname)s - %(funcName)s: %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S', level=logging.DEBUG)
app = FastAPI()


class PubNormRequest(TypedDict):
    text: str


class InternalNormRequest(TypedDict):
    req_id: str
    text: str
    deadline: int


class InternalNormResponse(TypedDict):
    normalized_text: str


class RedisResponseManager:
    _is_closed = False
    _managed_futures: Dict[
        str, Tuple[InternalNormRequest, Future[InternalNormResponse]]
    ] = {}

    def __init__(self, redis_client: aioredis.Redis) -> None:
        self.redis_client = redis_client

    def register_resp_future(
        self, norm_req: InternalNormRequest, resp_future: Future
    ) -> None:
        req_id = norm_req["req_id"]
        if req_id in self._managed_futures:
            raise ValueError("Redis response key existed")
        self._managed_futures[req_id] = (norm_req, resp_future)

    async def run_manager(self):
        while not self._is_closed:
            await self._find_and_fill_resp()
        for norm_req, resp_future in self._managed_futures.values():
            resp_future.set_exception(CancelledError("Response manager closed"))
        self._managed_futures.clear()

    async def _find_and_fill_resp(self):
        completed_keys = []
        for k in self._managed_futures:
            norm_req, resp_future = self._managed_futures[k]
            curr_time = _get_current_millis()
            # timeout check
            if norm_req["deadline"] > 0 and curr_time > norm_req["deadline"]:
                resp_future.set_exception(TimeoutError())
                completed_keys.append(k)
                continue
            # result check
            resp = await self._get_and_remove_redis_resp(k)
            if resp is not None:
                norm_result: InternalNormResponse = {"normalized_text":resp}
                resp_future.set_result(norm_result)
                completed_keys.append(k)
        if completed_keys:
            for k in completed_keys:
                del self._managed_futures[k]
        else:
            await asyncio.sleep(0.2)

    def close(self):
        self._is_closed = True

    async def _get_and_remove_redis_resp(self, redis_key: str) -> Union[str, None]:
        resp = await self.redis_client.get(redis_key)
        if resp is not None:
            await self.redis_client.delete(redis_key)
        return resp


class Normalizer:
    def __init__(self, redis_client: aioredis.Redis, resp_manager:RedisResponseManager) -> None:
        self._redis_client = redis_client
        self._resp_manager = resp_manager

    async def normalize(self, norm_req: InternalNormRequest) -> InternalNormResponse:
        req_id = norm_req["req_id"]
        redis_key = req_id
        resp_future = asyncio.get_running_loop().create_future()
        await self._send_redis_req(redis_key, norm_req)
        self._resp_manager.register_resp_future(norm_req, resp_future)
        return await resp_future

    async def _send_redis_req(self, redis_key: str, norm_req: InternalNormRequest):
        # TODO: not sure what happen if set is fail
        norm_req_queue="tts::en::norm_text"
        await self._redis_client.lpush(norm_req_queue, f"{redis_key} {norm_req['text']}")


def _generate_req_id():
    now_str = datetime.now().strftime("%Y%m%d-%H:%M:%S")
    uuid_str = str(uuid.uuid4()).replace("-", "")
    return f"{now_str}::{uuid_str}"


def _dump_json_utf8(obj: Any) -> str:
    return json.dumps(obj, ensure_ascii=False)


def _get_current_millis() -> int:
    return round(time.time() * 1000)


### Service stubs
_redis_client = aioredis.from_url("redis://localhost")
_resp_manager = RedisResponseManager(_redis_client)
_normalizer = Normalizer(_redis_client, _resp_manager)
_default_timeout_ms = 5000
asyncio.create_task(_resp_manager.run_manager())

@app.post("/norm")
async def normalize(norm_req: PubNormRequest):
    logging.debug(f"Received norm request: {_dump_json_utf8(norm_req)}")
    deadline = _get_current_millis() + _default_timeout_ms
    internal_norm_req: InternalNormRequest = {
        "req_id": _generate_req_id(),
        "text": norm_req["text"],
        "deadline": deadline,
    }
    norm_resp = await _normalizer.normalize(internal_norm_req)
    return norm_resp["normalized_text"]
