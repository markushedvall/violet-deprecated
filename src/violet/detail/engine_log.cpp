#include "pch.h"

#include "engine_log.h"

namespace violet {
namespace detail {

Logger& EngineLog::logger() {
  static Logger logger("Violet Engine");
  return logger;
}

} // namespace detail
} // namespace violet
