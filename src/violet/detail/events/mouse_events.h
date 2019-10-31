#ifndef VIOLET_DETAIL_MOUSE_EVENTS_H
#define VIOLET_DETAIL_MOUSE_EVENTS_H

#include "../event_category.h"

namespace violet {
namespace detail {

class MouseMovedEvent final {
public:
  MouseMovedEvent(double x, double y) : x_(x), y_(y) {}

  double x() const noexcept {
    return x_;
  }

  double y() const noexcept {
    return y_;
  }

  static constexpr const char* name() noexcept {
    return "MouseMoved";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Mouse;
  }

private:
  double x_;
  double y_;
};

class MouseScrolledEvent final {
public:
  MouseScrolledEvent(double x, double y) : x_(x), y_(y) {}

  double x() const noexcept {
    return x_;
  }

  double y() const noexcept {
    return y_;
  }

  static constexpr const char* name() noexcept {
    return "MouseScrolled";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Mouse;
  }

private:
  double x_;
  double y_;
};

class MouseButtonEvent {
public:
  int button() const noexcept {
    return button_;
  }

protected:
  MouseButtonEvent(int button) : button_(button) {}

private:
  int button_;
};

class MouseButtonPressedEvent final : public MouseButtonEvent {
public:
  MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

  static constexpr const char* name() noexcept {
    return "MouseButtonPressed";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Mouse;
  }
};

class MouseButtonReleasedEvent final : public MouseButtonEvent {
public:
  MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

  static constexpr const char* name() noexcept {
    return "MouseButtonReleased";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::Input | EventCategory::Mouse;
  }
};

} // namespace detail
} // namespace violet

#endif
