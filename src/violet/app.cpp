#include "pch.h"

#include "app.h"
#include "event_queue.h"
#include "event.h"
#include "detail/util/range.h"

namespace violet {

volatile bool App::terminate_;

void App::run() {
  EventQueue events;
  running_ = true;

  this->attach();

  while (running_) {
    events.clear();
    poll_events(events);

    for (auto&& layer : detail::reverse(layer_stack_)) {
      layer->tick(events);
    }
    this->tick(events);

    for (auto&& e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        running_ = false;
      }
    }

    this->render();
    for (auto&& layer : layer_stack_) {
      layer->render();
    }

    surface_.swap_buffers();
  }

  this->detach();
}

void App::push_layer(Layer* layer) {
  layer_stack_.push(layer);
}

void App::poll_events(EventQueue& events) {
  if (terminate_) {
    events.push(Event::AppWillTerminate());
  }
  surface_.poll_events(events);
}

}
