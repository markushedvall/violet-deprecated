#include "pch.h"

#include "log.h"
#include "app.h"

namespace violet {

Logger& Log::logger() {
  static Logger logger(App::info().name());
  return logger;
}

}
