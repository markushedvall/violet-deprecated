#include <violet.h>

using violet::Log;
using violet::Logger;
using violet::Assert;

class PackageTest : public violet::App {
public:
  void run() override {
    Log::trace("Hello World!");
    Log::info("{}", App::info().name());
    Logger logger("Custom");
    logger.warn("hello");

    Assert::not_reached("Unexpectedly reached {}", "the end");
  }
};

VIOLET_APP(PackageTest, "PackageTest App")
