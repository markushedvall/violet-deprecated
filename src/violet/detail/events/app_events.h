#ifndef VIOLET_DETAIL_APP_EVENTS_H
#define VIOLET_DETAIL_APP_EVENTS_H

#include "../event_category.h"

namespace violet {
namespace detail {

class AppWillTerminateEvent final {
public:
  static constexpr const char* name() noexcept {
    return "AppWillTerminate";
  }

  static constexpr CategoryFlags category_flags() noexcept {
    return EventCategory::App;
  }
};

} // namespace detail
} // namespace violet

#endif
