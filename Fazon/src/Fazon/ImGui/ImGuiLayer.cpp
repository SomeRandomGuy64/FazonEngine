#include "ImGuiLayer.h"
#include "Fazon/fzpch.h"

#include <SDL3/SDL.h>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.cpp>
#include "Fazon/Application.h"

namespace Fazon {

    ImGuiKey convertFazonKeyToImguiKeyCode(KeyCode keycode);

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer() {

	}

	void ImGuiLayer::onAttach() {

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io{ ImGui::GetIO() };
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;	// Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;		// Enable Docking

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init("#version 460");

	}

	void ImGuiLayer::onDetach() {
		
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();

	}

	void ImGuiLayer::begin() {

		ImGuiIO& io{ ImGui::GetIO() };
		Application& app{ Application::get() };
		io.DisplaySize = ImVec2{
			static_cast<float>(app.getWindow().getWidth()),
			static_cast<float>(app.getWindow().getHeight())
		};

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

	}

	void ImGuiLayer::end() {

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::onImGuiRender() {

		static bool show{ true };
		ImGui::ShowDemoWindow(&show);

	}


	void ImGuiLayer::onEvent(Event& event) {

		EventDispatcher dispatcher{ event };
		dispatcher.dispatch<MouseButtonPressedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onMouseButtonPressedEvent));
		dispatcher.dispatch<MouseButtonReleasedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onMouseButtonReleasedEvent));
		dispatcher.dispatch<MouseMovedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onMouseMovedEvent));
		dispatcher.dispatch<MouseScrolledEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onMouseScrolledEvent));
		dispatcher.dispatch<KeyPressedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onKeyPressedEvent));
		dispatcher.dispatch<KeyTypedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onKeyTypedEvent));
		dispatcher.dispatch<KeyReleasedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onKeyReleasedEvent));
		dispatcher.dispatch<WindowResizedEvent>(FZ_BIND_EVENT_FN(ImGuiLayer::m_onWindowResizedEvent));

	}

	bool ImGuiLayer::m_onMouseButtonPressedEvent(MouseButtonPressedEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		io.MouseDown[event.getMouseButtonCode()] = true;

		return false;

	}

	bool ImGuiLayer::m_onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		io.MouseDown[event.getMouseButtonCode()] = false;

		return false;

	}

	bool ImGuiLayer::m_onMouseMovedEvent(MouseMovedEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		io.MousePos = ImVec2(event.getXPosition(), event.getYPosition());

		return false;

	}

	bool ImGuiLayer::m_onMouseScrolledEvent(MouseScrolledEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		io.MouseWheel += event.getScrollDirection().m_yOffset;
		io.MouseWheel += event.getScrollDirection().m_xOffset;

		return false;

	}

	bool ImGuiLayer::m_onKeyPressedEvent(KeyPressedEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		io.AddKeyEvent(convertFazonKeyToImguiKeyCode(event.getKeyCode()), true);

		return false;

	}

	bool ImGuiLayer::m_onKeyReleasedEvent(KeyReleasedEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		io.AddKeyEvent(convertFazonKeyToImguiKeyCode(event.getKeyCode()), false);

		return false;

	}

	bool ImGuiLayer::m_onKeyTypedEvent(KeyTypedEvent& event) {

		ImGuiIO& io{ ImGui::GetIO() };
		KeyCode keycode{ event.getKeyCode() };
		if (keycode >= 4 && keycode < 128) {
			io.AddInputCharacter(convertFazonKeyToChar(event.getKeyCode()));
		}

		return false;

	}

	bool ImGuiLayer::m_onWindowResizedEvent(WindowResizedEvent& event) {
		ImGuiIO& io{ ImGui::GetIO() };
		io.DisplaySize = ImVec2{
			static_cast<float>(event.getWidth()),
			static_cast<float>(event.getHeight())
		};

		return false;
	}

}