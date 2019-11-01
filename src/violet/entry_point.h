#ifndef VIOLET_ENTRY_H
#define VIOLET_ENTRY_H

namespace violet {

class EntryPoint final {
public:
  EntryPoint() = delete;

  static void enter();
};

} // namespace violet

#endif
