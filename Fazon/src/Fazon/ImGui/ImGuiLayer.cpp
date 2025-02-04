#include "ImGuiLayer.h"
#include "Fazon/fzpch.h"

#include <SDL3/SDL.h>

#include <Fazon/Platform/OpenGL/ImGuiOpenGLRenderer.h>
#include <imgui/imgui.h>
#include "Fazon/Application.h"

namespace Fazon {

    ImGuiKey convertFazonToImguiKeyCode(KeyCode keycode);

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
        io.AddKeyEvent(convertFazonToImguiKeyCode(event.getKeyCode()), true);

		return false;

	}

	bool ImGuiLayer::m_onKeyReleasedEvent(KeyReleasedEvent& event) {

        ImGuiIO& io{ ImGui::GetIO() };
        io.AddKeyEvent(convertFazonToImguiKeyCode(event.getKeyCode()), false);

		return false;

	}

    bool ImGuiLayer::m_onKeyTypedEvent(KeyTypedEvent& event) {
        
        ImGuiIO& io{ ImGui::GetIO() };
        KeyCode keycode{ event.getKeyCode() };
        if (keycode >= 4 && keycode < 150) {
            io.AddInputCharacter(convertFazonKeyToASCII(event.getKeyCode()));
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

	ImGuiKey convertFazonToImguiKeyCode(KeyCode keycode) {

        switch (keycode)
        {
        case Key::Tab: return ImGuiKey_Tab;
        case Key::Left: return ImGuiKey_LeftArrow;
        case Key::Right: return ImGuiKey_RightArrow;
        case Key::Up: return ImGuiKey_UpArrow;
        case Key::Down: return ImGuiKey_DownArrow;
        case Key::PageUp: return ImGuiKey_PageUp;
        case Key::PageDown: return ImGuiKey_PageDown;
        case Key::Home: return ImGuiKey_Home;
        case Key::End: return ImGuiKey_End;
        case Key::Insert: return ImGuiKey_Insert;
        case Key::Delete: return ImGuiKey_Delete;
        case Key::Backspace: return ImGuiKey_Backspace;
        case Key::Space: return ImGuiKey_Space;
        case Key::Return: return ImGuiKey_Enter;
        case Key::Escape: return ImGuiKey_Escape;
        case Key::Apostrophe: return ImGuiKey_Apostrophe;
        case Key::Comma: return ImGuiKey_Comma;
        case Key::Minus: return ImGuiKey_Minus;
        case Key::Period: return ImGuiKey_Period;
        case Key::Slash: return ImGuiKey_Slash;
        case Key::Semicolon: return ImGuiKey_Semicolon;
        case Key::Equals: return ImGuiKey_Equal;
        case Key::LeftBracket: return ImGuiKey_LeftBracket;
        case Key::Backslash: return ImGuiKey_Backslash;
        case Key::RightBracket: return ImGuiKey_RightBracket;
        case Key::Grave: return ImGuiKey_GraveAccent;
        case Key::CapsLock: return ImGuiKey_CapsLock;
        case Key::ScrollLock: return ImGuiKey_ScrollLock;
        case Key::NumLock: return ImGuiKey_NumLock;
        case Key::PrintScreen: return ImGuiKey_PrintScreen;
        case Key::Pause: return ImGuiKey_Pause;
        case Key::KpLeftCtrl: return ImGuiKey_LeftCtrl;
        case Key::KpLeftShift: return ImGuiKey_LeftShift;
        case Key::KpLeftAlt: return ImGuiKey_LeftAlt;
        case Key::KpLeftGUI: return ImGuiKey_LeftSuper;
        case Key::KpRightCtrl: return ImGuiKey_RightCtrl;
        case Key::KpRightShift: return ImGuiKey_RightShift;
        case Key::KpRightAlt: return ImGuiKey_RightAlt;
        case Key::KpRightGUI: return ImGuiKey_RightSuper;
        case Key::Application: return ImGuiKey_Menu;
        case Key::Zero: return ImGuiKey_0;
        case Key::One: return ImGuiKey_1;
        case Key::Two: return ImGuiKey_2;
        case Key::Three: return ImGuiKey_3;
        case Key::Four: return ImGuiKey_4;
        case Key::Five: return ImGuiKey_5;
        case Key::Six: return ImGuiKey_6;
        case Key::Seven: return ImGuiKey_7;
        case Key::Eight: return ImGuiKey_8;
        case Key::Nine: return ImGuiKey_9;
        case Key::A: return ImGuiKey_A;
        case Key::B: return ImGuiKey_B;
        case Key::C: return ImGuiKey_C;
        case Key::D: return ImGuiKey_D;
        case Key::E: return ImGuiKey_E;
        case Key::F: return ImGuiKey_F;
        case Key::G: return ImGuiKey_G;
        case Key::H: return ImGuiKey_H;
        case Key::I: return ImGuiKey_I;
        case Key::J: return ImGuiKey_J;
        case Key::K: return ImGuiKey_K;
        case Key::L: return ImGuiKey_L;
        case Key::M: return ImGuiKey_M;
        case Key::N: return ImGuiKey_N;
        case Key::O: return ImGuiKey_O;
        case Key::P: return ImGuiKey_P;
        case Key::Q: return ImGuiKey_Q;
        case Key::R: return ImGuiKey_R;
        case Key::S: return ImGuiKey_S;
        case Key::T: return ImGuiKey_T;
        case Key::U: return ImGuiKey_U;
        case Key::V: return ImGuiKey_V;
        case Key::W: return ImGuiKey_W;
        case Key::X: return ImGuiKey_X;
        case Key::Y: return ImGuiKey_Y;
        case Key::Z: return ImGuiKey_Z;
        case Key::F1: return ImGuiKey_F1;
        case Key::F2: return ImGuiKey_F2;
        case Key::F3: return ImGuiKey_F3;
        case Key::F4: return ImGuiKey_F4;
        case Key::F5: return ImGuiKey_F5;
        case Key::F6: return ImGuiKey_F6;
        case Key::F7: return ImGuiKey_F7;
        case Key::F8: return ImGuiKey_F8;
        case Key::F9: return ImGuiKey_F9;
        case Key::F10: return ImGuiKey_F10;
        case Key::F11: return ImGuiKey_F11;
        case Key::F12: return ImGuiKey_F12;
        case Key::F13: return ImGuiKey_F13;
        case Key::F14: return ImGuiKey_F14;
        case Key::F15: return ImGuiKey_F15;
        case Key::F16: return ImGuiKey_F16;
        case Key::F17: return ImGuiKey_F17;
        case Key::F18: return ImGuiKey_F18;
        case Key::F19: return ImGuiKey_F19;
        case Key::F20: return ImGuiKey_F20;
        case Key::F21: return ImGuiKey_F21;
        case Key::F22: return ImGuiKey_F22;
        case Key::F23: return ImGuiKey_F23;
        case Key::F24: return ImGuiKey_F24;
        case Key::AcBack: return ImGuiKey_AppBack;
        case Key::AcForward: return ImGuiKey_AppForward;
        default: break;
        }
        return ImGuiKey_None;

	}

}