
// #include <absl/strings/str_join.h>
// #include <absl/strings/str_split.h>
#include <sparrowhawk/normalizer.h>
#include <sw/redis++/redis++.h>

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

DEFINE_bool(multi_line_text, false, "Text is spread across multiple lines.");
DEFINE_string(config, "", "Path to the configuration proto.");
DEFINE_string(path_prefix, "./", "Optional path prefix if not relative.");

std::string NormalizeInput(const string& input, speech::sparrowhawk::Normalizer& normalizer) {
  const std::vector<string> sentences = normalizer.SentenceSplitter(input);
  std::string normalized_text = "";
  for (const auto& sentence : sentences) {
    std::string output;
    normalizer.Normalize(sentence, &output);
    normalized_text += output + " ";
  }
  return normalized_text;
}

struct NormRequest {
  std::string req_id = "";
  std::string text = "";
};

struct NormResponse {
  std::string normalized_text = "";
};

NormRequest ParseRedisReq(const std::string& redis_req_str) {
  auto first_space_loc = redis_req_str.find(" ", 0);
  if (first_space_loc != string::npos) {
    // TODO: this code may have many hidden problem, fix it
    auto req_id = redis_req_str.substr(0, first_space_loc);
    auto text = redis_req_str.substr(first_space_loc + 1);
    return {.req_id = req_id, .text = text};
  } else {
    return {};
  }
}

void SetRedisResult(const NormResponse& norm_result, const NormRequest& norm_req, sw::redis::Redis& redis_client) {
  redis_client.set(norm_req.req_id, norm_result.normalized_text);
}

void RunRedisWorker(speech::sparrowhawk::Normalizer& normalizer) {
  auto conn_options = sw::redis::ConnectionOptions("tcp://localhost:6379");
  auto redis_client_ = std::make_unique<sw::redis::Redis>(conn_options);
  auto norm_request_queue = "tts::en::norm_text";
  while (true) {
    auto req_str_opt = redis_client_->rpop(norm_request_queue);
    if (!req_str_opt.has_value()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      continue;
    }
    std::cout<<"Processing request: "<<req_str_opt.value()<<std::endl;
    auto norm_req = ParseRedisReq(req_str_opt.value());
    if (norm_req.req_id.empty()) {
      continue;
    }
    if (norm_req.text.empty()) {
      SetRedisResult({}, norm_req, *redis_client_);
      continue;
    }
    auto normed_text = NormalizeInput(norm_req.text, normalizer);
    SetRedisResult({.normalized_text = normed_text}, norm_req, *redis_client_);
  }
}

int main(int argc, char** argv) {
  using speech::sparrowhawk::Normalizer;
  std::set_new_handler(FailedNewHandler);
  SET_FLAGS(argv[0], &argc, &argv, true);
  auto normalizer = std::make_unique<Normalizer>();
  CHECK(normalizer->Setup(FST_FLAGS_config, FST_FLAGS_path_prefix));
  RunRedisWorker(*normalizer);
  return 0;
}
