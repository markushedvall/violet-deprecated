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

  attach();
  imgui_.attach(surface_);

  while (running_) {
    events.clear();
    poll_events(events);

    imgui_.tick(events);
    for (auto&& layer : detail::reverse(layer_stack_)) {
      layer->tick(events);
    }
    tick(events);

    for (auto&& e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        running_ = false;
      }
    }

    render();
    for (auto&& layer : layer_stack_) {
      layer->render();
    }
    imgui_.render();

    surface_.swap_buffers();
  }

  detach();
  imgui_.detach();
}

void App::push_layer(Layer* layer) {
  layer_stack_.push(layer);
}

void App::set_imgui_layer(std::unique_ptr<Layer>&& layer) {
  imgui_.set_layer(std::move(layer));
}

void App::poll_events(EventQueue& events) {
  if (terminate_) {
    events.push(Event::AppWillTerminate());
  }
  surface_.poll_events(events);
}

}
