from fastapi import APIRouter
from pydantic import BaseModel
from norm_update_manager import *

router = APIRouter()

class UpdateNormRequest(BaseModel):
    command: str
    words: Dict[str, str]
    case_sensitive: bool


@router.post("/update_norm")
def update_whitelist(update_norm_request: UpdateNormRequest):
    if update_norm_request.command == "update":
        return handle_update_command(
            update_norm_request.words, update_norm_request.case_sensitive
        )
