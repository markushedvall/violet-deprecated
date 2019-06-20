#ifndef VIOLET_DETAIL_EVENT_CATEGORY_H
#define VIOLET_DETAIL_EVENT_CATEGORY_H

namespace violet {
namespace detail {

enum EventCategory {
  None      = 0,
  Input     = 1 << 0,
  Keyboard  = 1 << 1,
  Mouse     = 1 << 2
};

using CategoryFlags = int;

}
}

#endif
