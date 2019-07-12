#include <chrono>

#include <violet.h>

using violet::Log;
using violet::App;

class PackageTest : public App {
public:

  PackageTest() {
    Log::info("Starting {}", App::info().name());
  }

  void tick() override {
    static auto t1 = std::chrono::steady_clock::now();
    auto t2 = std::chrono::steady_clock::now();
    auto d = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1);
    if (d >= std::chrono::seconds(5)) {
      Log::info("Five seconds passed. Closing application...");
      App::terminate();
    }
  }

  virtual ~PackageTest() {}

};

VIOLET_APP(PackageTest, "PackageTest App")
