#include "pch.h"

#include "app.h"
#include "log.h"

namespace violet {

Logger& Log::logger() {
  static Logger logger(App::info().name());
  return logger;
}

} // namespace violet
