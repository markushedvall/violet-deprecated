#include "imgui_impl.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace violet {
namespace detail {

void ImGuiImpl::init(const Surface& surface) {
  ImGui_ImplGlfw_InitForOpenGL(surface.window_.get(), true);
  ImGui_ImplOpenGL3_Init("#version 330 core");
}

void ImGuiImpl::shutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
}

void ImGuiImpl::new_frame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
}

void ImGuiImpl::render(ImDrawData* draw_data) {
  ImGui_ImplOpenGL3_RenderDrawData(draw_data);
}

} // namespace detail
} // namespace violet
