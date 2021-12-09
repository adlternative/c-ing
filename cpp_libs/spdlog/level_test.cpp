#define SPDLOG_FMT_EXTERNAL
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main(int, char **) {

  // spdlog::set_pattern("[source %s] [function %!] [line %#] %v");
  // spdlog::set_level(spdlog::level::trace);

  // SPDLOG_TRACE("This trace");
  // SPDLOG_DEBUG("This is debug..");
  // SPDLOG_INFO("This is info..");
  // SPDLOG_ERROR("This is error..");
  // SPDLOG_CRITICAL("This is critical..");

  auto console_logger = spdlog::stdout_color_mt("console");
  console_logger->set_pattern("[source %s] [function %!] [line %#] %v");
  console_logger->error("This is error..");
  return 0;
}
