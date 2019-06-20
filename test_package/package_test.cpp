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

  void test_events() {
    EventQueue queue;
    auto e1 = Event::KeyPressed();
    auto e2 = Event::MouseMoved();
    queue.push_back(e1);
    queue.push_back(e2);

    auto front = queue.front();
    if (front.is<Event::KeyPressed>()) {
      Log::info(front.name());
    }

    for (auto& e: queue) {
      if (e.in_category(Event::Category::Input)) {
        Log::info("Category Input: {}", e.name());
      }
      if (e.in_category(Event::Category::Mouse)) {
        Log::info("Category Mouse: {}", e.name());
      }
    }
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
