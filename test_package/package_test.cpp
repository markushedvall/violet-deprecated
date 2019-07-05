#include <violet.h>

using violet::Log;
using violet::Logger;

class PackageTest : public violet::App {
public:
  void run() override {
    Log::trace("Hello World!");
    Log::info("{}", App::info().name());
    Logger logger("Custom");
    logger.warn("hello");
  }
};

VIOLET_APP(PackageTest, "PackageTest App")
