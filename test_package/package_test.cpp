#include <violet.h>

#include <imgui.h>

#include <chrono>
#include <thread>

using violet::Log;
using violet::App;
using violet::Layer;
using violet::Event;
using violet::EventQueue;

class TestLayer final : public Layer {
public:

  TestLayer(const std::string& name) : name_(std::move(name)) {}

  void attach() override {
    Log::info("{} attached", name_);
  }

  void detach() override {
    Log::info("{} detached", name_);
  }

  void tick(EventQueue& events) override {
    for (auto&& e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        Log::info("{}: Terminate event", name_);
      }
    }
  }

private:

  std::string name_;

};

class ImGuiLayer final : public Layer {
public:

  void attach() override {
    Log::info("ImGuiLayer attached");
  }

  void detach() override {
    Log::info("ImGuiLayer detached");
  }

  void tick(EventQueue& events) override {
    for (auto&& e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        Log::info("ImGuiLayer: Terminate event");
      }
    }
  }

  void render() override {
    static bool showing = true;
    ImGui::ShowDemoWindow(&showing);
  }

};

class PackageTest final : public App {
public:

  void attach() override {
    Log::info("PackageTest attached");
    push_layer(new TestLayer("Layer1"));
    push_layer(new TestLayer("Layer2"));
    set_imgui_layer(std::unique_ptr<ImGuiLayer>(new ImGuiLayer()));
    remove_layer();
  }

  void detach() override {
    Log::info("PackageTest detached");
  }

  void tick(EventQueue& events) override {
    for (auto&& e : events) {
      if (e.is<Event::AppWillTerminate>()) {
        Log::info("PackageTest: Terminate event");
        return;
      }
      if (e.is<Event::MouseMoved>()) {
        auto mve = e.as<Event::MouseMoved>();
        Log::info("Mouse moved x:{} y:{}", mve.x(), mve.y());
        return;
      }
    }

    static auto t1 = std::chrono::steady_clock::now();
    auto t2 = std::chrono::steady_clock::now();
    auto d = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1);
    if (d >= std::chrono::seconds(10)) {
      Log::info("{} seconds passed. Terminating application...", d.count());
      App::terminate();
    }
  }

  virtual ~PackageTest() {}

};

VIOLET_APP(PackageTest, "PackageTest App")
