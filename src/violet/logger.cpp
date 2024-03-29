#include "pch.h"

#include "logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

using spdlog::sinks::stdout_color_sink_mt;

namespace violet {

Logger::Logger(const std::string& name) noexcept :
    logger_(name, std::make_shared<stdout_color_sink_mt>()) {
  logger_.set_level(spdlog::level::trace);
}

} // namespace violet
