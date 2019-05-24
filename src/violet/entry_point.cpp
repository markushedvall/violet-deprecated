#include "entry_point.h"
#include "app.h"

#ifndef VIOLET_NO_ENTRY

int main() {
  violet::EntryPoint::enter();
}

#endif

namespace violet {

void EntryPoint::enter() {
  App::launch();
}

}
