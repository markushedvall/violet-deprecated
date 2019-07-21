#include "pch.h"

#include "app.h"
#include "event_queue.h"
#include "event.h"

namespace violet {

volatile bool App::terminate_;

void App::run() {
  EventQueue events;
  running_ = true;
  while (running_) {
    events.clear();
    poll_events(events);
    tick(events);
    for (auto e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        running_ = false;
      }
    }
    surface_.swap_buffers();
  }
}

void App::poll_events(EventQueue& events) {
  if (terminate_) {
    events.push(Event::AppWillTerminate());
  }
  surface_.poll_events(events);
}

}
