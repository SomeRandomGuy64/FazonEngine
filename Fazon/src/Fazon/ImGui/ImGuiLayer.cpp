#include "ImGuiLayer.h"
#include "Fazon/fzpch.h"

#include <SDL3/SDL.h>

#include <Fazon/Platform/OpenGL/ImGuiOpenGLRenderer.h>
#include <imgui/imgui.h>
#include "Fazon/Application.h"

namespace Fazon {

    ImGuiKey convertFazonKeyToImguiKeyCode(KeyCode keycode);

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
		//io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		//io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;

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