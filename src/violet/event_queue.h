#ifndef VIOLET_EVENT_QUEUE_H
#define VIOLET_EVENT_QUEUE_H

#include <deque>

#include "event.h"

namespace violet {

class EventQueue final {
public:
  using Iterator = std::deque<Event>::iterator;

  void push(Event&& event) {
    queue_.push_back(std::move(event));
  }

  void clear() noexcept {
    queue_.clear();
  }

  Event& front() {
    return queue_.front();
  }

  Iterator begin() noexcept {
    return queue_.begin();
  }

  Iterator end() noexcept {
    return queue_.end();
  }

private:
  std::deque<Event> queue_;
};

} // namespace violet

#endif
