#ifndef VIOLET_DETAIL_KEY_EVENTS_H
#define VIOLET_DETAIL_KEY_EVENTS_H

#include "../event_category.h"

namespace violet {
namespace detail {

class KeyPressedEvent final {
public:

  KeyPressedEvent(int key) : key_(key) {}

  static constexpr const char* name() noexcept {
    return "KeyPressed";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Keyboard;
  }

  int key() const noexcept {
    return key_;
  }

private:

  int key_;

};

class KeyReleasedEvent final {
public:

  KeyReleasedEvent(int key) : key_(key) {}

  static constexpr const char* name() noexcept {
    return "KeyReleased";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Keyboard;
  }

  int key() const noexcept {
    return key_;
  }

private:

  int key_;

};

class KeyTypedEvent final {
public:

  KeyTypedEvent(unsigned int codepoint) : codepoint_(codepoint) {}

  static constexpr const char* name() noexcept {
    return "KeyTyped";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Keyboard;
  }

  int codepoint() const noexcept {
    return codepoint_;
  }

private:

  int codepoint_;

};

}
}

#endif
