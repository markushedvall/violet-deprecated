#include "pch.h"

#include "entry_point.h"

#include "app.h"
#include "detail/engine_log.h"

#ifndef VIOLET_NO_ENTRY

int main() {
  violet::EntryPoint::enter();
}

#endif

namespace violet {

using detail::EngineLog;

void EntryPoint::enter() {
  EngineLog::info("Initializing Violet Engine");
  App::launch();
}

}
