#include "pch.h"

#include "desktop_surface.h"

// #define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../../engine_log.h"
#include "../../../assert.h"
#include "../../../app.h"
#include "../../../event_queue.h"

namespace violet {
namespace detail {

struct Glfw {
  Glfw() noexcept {
    EngineLog::trace("Initializing GLFW");
    auto initialized = glfwInit();
    Assert::is_true<EngineLog>(initialized, "Failed to initialize GLFW");
    glfwSetErrorCallback([](int err, const char* msg) {
      EngineLog::error("GLFW error: {}", msg);
    });
  }

  ~Glfw() {
    EngineLog::trace("Terminating GLFW");
    glfwTerminate();
  }
};

void DesktopSurface::GlfwWindowDeleter::operator()(GLFWwindow* window) {
  glfwDestroyWindow(window);
}

DesktopSurface::DesktopSurface() noexcept : window_(create_window()) {
  glfwSetWindowUserPointer(window_.get(), &event_buffer_);

  glfwSetWindowCloseCallback(window_.get(), [](GLFWwindow* w) {
    EngineLog::trace("GLFW Window close callback");
    App::terminate();
	});

  glfwSetCursorPosCallback(window_.get(), [](GLFWwindow* w, double x, double y) {
    auto event_buffer = (std::vector<Event>*)glfwGetWindowUserPointer(w);
    event_buffer->push_back(Event::MouseMoved(x, y));
  });

  glfwSetScrollCallback(window_.get(), [](GLFWwindow* w, double x, double y) {
    auto event_buffer = (std::vector<Event>*)glfwGetWindowUserPointer(w);
    event_buffer->push_back(Event::MouseScrolled(x, y));
  });

  glfwSetMouseButtonCallback(window_.get(), [](GLFWwindow* w, int button, int action, int mods) {
    auto event_buffer = (std::vector<Event>*)glfwGetWindowUserPointer(w);
    switch (action) {
      case GLFW_PRESS:
        event_buffer->push_back(Event::MouseButtonPressed(button));
        break;
      case GLFW_RELEASE:
        event_buffer->push_back(Event::MouseButtonReleased(button));
        break;
      default:
        // Ignore
        break;
    }
  });

  glfwSetKeyCallback(window_.get(), [](GLFWwindow* w, int key, int code, int action, int mods) {
    auto event_buffer = (std::vector<Event>*)glfwGetWindowUserPointer(w);
    switch (action) {
      case GLFW_PRESS:
        event_buffer->push_back(Event::KeyPressed(key));
        break;
      case GLFW_RELEASE:
        event_buffer->push_back(Event::KeyReleased(key));
        break;
      default:
        // Ignore
        break;
    }
  });

  glfwSetCharCallback(window_.get(), [](GLFWwindow* w, unsigned int codepoint) {
    auto event_buffer = (std::vector<Event>*)glfwGetWindowUserPointer(w);
    event_buffer->push_back(Event::KeyTyped(codepoint));
  });

  glfwMakeContextCurrent(window_.get());

  set_vsync(true);
}

DesktopSurface::GlfwWindowPtr DesktopSurface::create_window() noexcept {
  static Glfw glfw;

  // 4x antialiasing
  glfwWindowHint(GLFW_SAMPLES, 4);

  // Use OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  const auto monitor = glfwGetPrimaryMonitor();
  Assert::not_null<EngineLog>(monitor, "Failed to get primary monitor");
  const auto mode = glfwGetVideoMode(monitor);
  Assert::not_null<EngineLog>(mode, "Failed to get video mode from primary monitor");

  const char* window_title = App::info().name().c_str();
  return std::unique_ptr<GLFWwindow, GlfwWindowDeleter>(
    glfwCreateWindow(mode->width, mode->height, window_title, monitor, nullptr));
}

void DesktopSurface::poll_events(EventQueue& events) noexcept {
  glfwPollEvents();
  for (auto event: event_buffer_) {
    events.push(std::move(event));
  }
  event_buffer_.clear();
}

void DesktopSurface::swap_buffers() const noexcept {
  glfwSwapBuffers(window_.get());
  glClearColor(0.3f, 0.0f, 0.6f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void DesktopSurface::set_vsync(bool enabled) const noexcept {
  if (enabled) {
    glfwSwapInterval(1);
  } else {
    glfwSwapInterval(0);
  }
}

}
}
