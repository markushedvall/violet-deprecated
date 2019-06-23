#ifndef VIOLET_DETAIL_EVENT_CATEGORY_H
#define VIOLET_DETAIL_EVENT_CATEGORY_H

namespace violet {
namespace detail {

enum EventCategory {
  None      = 0,
  App       = 1 << 0,
  Input     = 1 << 1,
  Keyboard  = 1 << 2,
  Mouse     = 1 << 3
};

using CategoryFlags = int;

}
}

#endif
