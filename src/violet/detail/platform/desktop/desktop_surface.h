#ifndef VIOLET_DETAIL_DESKTOP_SURFACE_H
#define VIOLET_DETAIL_DESKTOP_SURFACE_H

#include <memory>

struct GLFWwindow;

namespace violet {
namespace detail {

class DesktopSurface final {
public:

  DesktopSurface() noexcept;

  void poll_events() const noexcept;

  void swap_buffers() const noexcept;

private:

  class GlfwWindowDeleter final {
  public:
    void operator()(GLFWwindow* window);
  };

  using GlfwWindowPtr = std::unique_ptr<GLFWwindow, GlfwWindowDeleter>;

  static GlfwWindowPtr create_window() noexcept;

  void set_vsync(bool enabled) const noexcept;

  GlfwWindowPtr window_;

};

}
}

#endif
