#ifndef VIOLET_EVENT_H
#define VIOLET_EVENT_H

#include <mpark/variant.hpp>

#include "detail/events/app_events.h"
#include "detail/events/key_events.h"
#include "detail/events/mouse_events.h"
#include "detail/event_category.h"

namespace violet {

class Event final {
public:

  using AppWillTerminate = detail::AppWillTerminateEvent;
  using KeyPressed = detail::KeyPressedEvent;
  using KeyReleased = detail::KeyReleasedEvent;
  using KeyTyped = detail::KeyTypedEvent;
  using MouseMoved = detail::MouseMovedEvent;
  using MouseScrolled = detail::MouseScrolledEvent;
  using MouseButtonPressed = detail::MouseButtonPressedEvent;
  using MouseButtonReleased = detail::MouseButtonReleasedEvent;

  using Category = detail::EventCategory;
  using CategoryFlags = detail::CategoryFlags;

  constexpr Event(const Event& other) noexcept : event_(other.event_) {}

  constexpr Event(Event& other) noexcept : event_(other.event_) {}

  constexpr Event(Event&& other) noexcept : event_(std::move(other.event_)) {}

  template<typename E>
  constexpr Event(E&& event) noexcept : event_(std::move(event)) {}

  template<typename E>
  constexpr Event& operator=(E&& e) noexcept {
    return Event(e);
  }

  template<typename E>
  constexpr bool is() {
    return mpark::holds_alternative<E>(event_);
  }

  template<typename E>
  constexpr const E& as() {
    return mpark::get<E>(event_);
  }

  constexpr const char* name() const noexcept {
    return mpark::visit(NameVisitor(), event_);
  }

  constexpr bool in_category(Category category) {
    return mpark::visit(CategoryFlagsVisitor(), event_) & category;
  }

private:

  using EventVariant = mpark::variant<
    AppWillTerminate,
    KeyPressed,
    KeyReleased,
    KeyTyped,
    MouseMoved,
    MouseScrolled,
    MouseButtonPressed,
    MouseButtonReleased
  >;

  struct NameVisitor {
    template<typename E>
    constexpr const char* operator()(const E&) { return E::name(); }
  };

  struct CategoryFlagsVisitor {
    template<typename E>
    constexpr CategoryFlags operator()(const E&) { return E::category_flags(); }
  };

  EventVariant event_;

};

}

#endif
