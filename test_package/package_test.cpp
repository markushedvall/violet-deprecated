#include <violet.h>

using violet::Log;
using violet::App;
using violet::Logger;

class PackageTest {
public:
  void launch() {
    Log::trace("Hello World!");
    Log::info("{}", App::info().name());
    Logger logger("Custom");
    logger.warn("hello");
  }
};

VIOLET_APP(PackageTest, "PackageTest App")
