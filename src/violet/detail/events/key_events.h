#ifndef VIOLET_DETAIL_KEY_EVENTS_H
#define VIOLET_DETAIL_KEY_EVENTS_H

#include "../event_category.h"

namespace violet {
namespace detail {

class KeyEvent {
public:

  int key() const noexcept {
    return key_;
  }

protected:

  KeyEvent(int key) : key_(key) {}

private:

  int key_;

};

class KeyPressedEvent final : public KeyEvent {
public:

  KeyPressedEvent(int key) : KeyEvent(key) {}

  static constexpr const char* name() noexcept {
    return "KeyPressed";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Keyboard;
  }

};

class KeyReleasedEvent final : public KeyEvent {
public:

  KeyReleasedEvent(int key) : KeyEvent(key) {}

  static constexpr const char* name() noexcept {
    return "KeyReleased";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Keyboard;
  }

};

}
}

#endif
