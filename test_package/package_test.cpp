#include <chrono>

#include <violet.h>

#include <chrono>
#include <thread>

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
    if (d >= std::chrono::seconds(3)) {
      Log::info("{} seconds passed. Closing application...", d.count());
      App::terminate();
    }
  }

  virtual ~PackageTest() {}

};

VIOLET_APP(PackageTest, "PackageTest App")
