#ifndef VIOLET_DETAIL_EVENTS_H
#define VIOLET_DETAIL_EVENTS_H

#include "event_category.h"

namespace violet {
namespace detail {

class KeyPressedEvent final {
public:

  static constexpr const char* name() noexcept {
    return "KeyPressedEvent";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Keyboard;
  }

};

class MouseMovedEvent final {
public:

  static constexpr const char* name() noexcept {
    return "MouseMovedEvent";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Mouse;
  }

};

}
}

#endif
