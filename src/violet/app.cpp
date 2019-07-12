#include "pch.h"

#include "app.h"

namespace violet {

void App::run() {
  running_ = true;
  while (running_) {
    tick();
  }
}

}
