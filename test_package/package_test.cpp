#include <chrono>

#include <violet.h>

#include <chrono>
#include <thread>

using violet::Log;
using violet::App;
using violet::Event;
using violet::EventQueue;

class PackageTest : public App {
public:

  PackageTest() {
    Log::info("Starting {}", App::info().name());
  }

  void tick(EventQueue& events) override {
    for (auto e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        Log::info("App will terminate");
        return;
      }
    }

    static auto t1 = std::chrono::steady_clock::now();
    auto t2 = std::chrono::steady_clock::now();
    auto d = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1);
    if (d >= std::chrono::seconds(3)) {
      Log::info("{} seconds passed. Terminating application...", d.count());
      App::terminate();
    }
  }

  virtual ~PackageTest() {}

};

VIOLET_APP(PackageTest, "PackageTest App")
