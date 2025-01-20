#include "ImGuiLayer.h"
#include "Fazon/fzpch.h"

#include <imgui/imgui.h>
#include <Fazon/Platform/OpenGL/ImGuiOpenGLRenderer.h>

#include "Fazon/Application.h"

namespace Fazon {

	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer() {
	
	}

	void ImGuiLayer::onAttach() {

		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io{ ImGui::GetIO() };
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 460");

	}

	void ImGuiLayer::onDetach() {

	}

	void ImGuiLayer::onUpdate() {
		
		ImGuiIO& io{ ImGui::GetIO() };
		Application& app{ Application::get() };
		io.DisplaySize = ImVec2{ 
			static_cast<float>(app.getWindow().getWidth()), 
			static_cast<float>(app.getWindow().getHeight()) 
		};

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show{ true };
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	void ImGuiLayer::onEvent(Event&) {

	}

}