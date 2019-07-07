#include "pch.h"

#include "app.h"

namespace violet {

void App::run() {
  running_ = true;
  while (running_) {
    surface_.poll_events();
    tick();
    surface_.swap_buffers();
  }
}

}
