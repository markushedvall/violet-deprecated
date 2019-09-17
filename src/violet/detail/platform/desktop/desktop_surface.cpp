#include "pch.h"

#include "desktop_surface.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../engine_log.h"
#include "../../../assert.h"
#include "../../../app.h"

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
  glfwSetInputMode(window_.get(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

  glfwSetWindowCloseCallback(window_.get(), [](GLFWwindow* window) {
    EngineLog::trace("GLFW Window close callback");
    App::terminate();
	});

  glfwMakeContextCurrent(window_.get());
  auto loaded = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  Assert::is_true<EngineLog>(loaded, "Glad failed to load OpenGL");

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

void DesktopSurface::poll_events() const noexcept {
  glfwPollEvents();
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