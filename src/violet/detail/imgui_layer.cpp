#include "imgui_layer.h"

#include "imgui_impl.h"

#include <imgui.h>

namespace violet {
namespace detail {

void ImGuiLayer::attach(const Surface& surface) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

  ImGui::StyleColorsDark();

  ImGuiImpl::init(surface);

  if (layer_ != nullptr) {
    layer_->attach();
  }
}

void ImGuiLayer::detach() {
  if (layer_ != nullptr) {
    layer_->detach();
  }
  ImGuiImpl::shutdown();
  ImGui::DestroyContext();
}

void ImGuiLayer::tick(EventQueue& events) {
  if (layer_ != nullptr) {
    layer_->tick(events);
  }
}

void ImGuiLayer::render() {
  if (layer_ != nullptr) {
    ImGuiImpl::new_frame();
    ImGui::NewFrame();

    layer_->render();

    ImGui::Render();
    ImGuiImpl::render(ImGui::GetDrawData());
  }
}

} // namespace detail
} // namespace violet
