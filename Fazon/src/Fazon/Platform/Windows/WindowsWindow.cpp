#include "Fazon/fzpch.h"
#include "WindowsWindow.h"

#include "Fazon/Events/ApplicationEvent.h"
#include "Fazon/Events/WindowEvent.h"
#include "Fazon/Events/KeyEvent.h"
#include "Fazon/Events/MouseEvent.h"

#include <glad/glad.h>

// update later to remove OpenGL specific stuff

namespace Fazon {

	static bool s_SDLInitialised{ false };

	Window* Window::create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		m_init(props);
	}

	WindowsWindow::~WindowsWindow() {
		m_shutdown();
	}

	void WindowsWindow::m_printError(const char* error) {
		// done to check if error is an empty string to prevent empty errors from printing
		if (error[0] == '\0') {
			return;
		}
		else {
			FZ_CORE_ERROR("SDL Error: {0}", error);
		}
	}

	void WindowsWindow::m_init(const WindowProps& props) {

		m_data.title = props.m_title;
		m_data.width = props.m_width;
		m_data.height = props.m_height;

		FZ_CORE_INFO("Creating window {0} ({1}, {2})", props.m_title, props.m_width, props.m_height);

		if (!s_SDLInitialised) {
			[[maybe_unused]]bool success{ SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) };
			FZ_CORE_ASSERT(success, "Could not initialise SDL!");
			m_printError(SDL_GetError());
			s_SDLInitialised = true;
		}

		m_window = SDL_CreateWindow(
			props.m_title, 
			static_cast<int>(props.m_width), 
			static_cast<int>(props.m_height), 
			SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
		);

		
		
		// OpenGL specific
		m_glContext = SDL_GL_CreateContext(m_window);
		SDL_GL_MakeCurrent(m_window, m_glContext);

		int status{ gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress) };
		FZ_CORE_ASSERT(status, "Failed to initialise GLAD!");

		m_printError(SDL_GetError());
		setVSync(true);

	}

	void WindowsWindow::m_shutdown() {
		SDL_GL_DestroyContext(m_glContext);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void WindowsWindow::onUpdate() {

		SDL_PollEvent(&m_sdlEvent);

		// Set SDL events
		m_resizeWindowEvent();
		m_closeWindowEvent();
		m_windowMovedEvent();
		m_windowFocusEvent();
		m_windowLostFocusEvent();
		m_keyPressEvent();
		m_keyTypeEvent();
		m_mouseButtonPressEvent();
		m_mouseScrollEvent();
		m_mouseMoveEvent();

		// OpenGL specific
		SDL_GL_SwapWindow(m_window);
		glClear(GL_COLOR_BUFFER_BIT);

	}

	void WindowsWindow::setVSync(bool enabled) {

		if (enabled) {
			SDL_GL_SetSwapInterval(1);
		}
		else {
			SDL_GL_SetSwapInterval(0);
		}

		m_data.vSync = enabled;

	}

	bool WindowsWindow::isVSync() const {
		return m_data.vSync;
	}

	void WindowsWindow::m_resizeWindowEvent() {

		if (m_sdlEvent.type == SDL_EVENT_WINDOW_RESIZED) {
			int width{};
			int height{};

			// OpenGL
			SDL_GetWindowSizeInPixels(m_window, &width, &height);
			m_printError(SDL_GetError());

			m_data.width = width;
			m_data.height = height;

			WindowResizedEvent event{ width, height };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_closeWindowEvent() {
		
		if (m_sdlEvent.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
			WindowCloseEvent event{};
			m_data.EventCallback(event);	
		}

	}

	void WindowsWindow::m_windowMovedEvent() {

		if (m_sdlEvent.type == SDL_EVENT_WINDOW_MOVED) {
			int xPos{};
			int yPos{};
			SDL_GetWindowPosition(m_window, &xPos, &yPos);
			WindowMovedEvent event{ xPos, yPos };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_windowFocusEvent() {

		if (m_sdlEvent.type == SDL_EVENT_WINDOW_FOCUS_GAINED) {
			WindowFocusEvent event{};
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_windowLostFocusEvent() {

		if (m_sdlEvent.type == SDL_EVENT_WINDOW_FOCUS_LOST) {
			WindowLostFocusEvent event{};
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_keyPressEvent() {

		if (m_sdlEvent.type == SDL_EVENT_KEY_DOWN) {
			if (m_sdlEvent.key.repeat) {
				KeyPressedEvent event{ m_convertSDLToFazonKeyCode(m_sdlEvent.key.key), 1 };
				m_data.EventCallback(event);
			}
			else {
				KeyPressedEvent event{ m_convertSDLToFazonKeyCode(m_sdlEvent.key.key), 0 };
				m_data.EventCallback(event);
			}
		}
		else if (m_sdlEvent.type == SDL_EVENT_KEY_UP) {
			KeyReleasedEvent event{ m_convertSDLToFazonKeyCode(m_sdlEvent.key.key) };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_keyTypeEvent() {
		
		if (m_sdlEvent.type == SDL_EVENT_KEY_DOWN) {
			KeyTypedEvent event{ m_convertSDLToFazonKeyCode(m_sdlEvent.key.key) };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_mouseButtonPressEvent() {

		if (m_sdlEvent.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			MouseButtonPressedEvent event{ static_cast<uint32_t>(m_sdlEvent.button.button) };
			m_data.EventCallback(event);
		}
		else if (m_sdlEvent.type == SDL_EVENT_MOUSE_BUTTON_UP) {
			MouseButtonReleasedEvent event{ static_cast<uint32_t>(m_sdlEvent.button.button) };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_mouseScrollEvent() {

		if (m_sdlEvent.type == SDL_EVENT_MOUSE_WHEEL) {
			MouseScrolledEvent event{ MouseScrollDirection{ m_sdlEvent.wheel.y, m_sdlEvent.wheel.x } };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_mouseMoveEvent() {

		float xPos{};
		float yPos{};
		if (m_sdlEvent.type == SDL_EVENT_MOUSE_MOTION) {
			SDL_GetMouseState(&xPos, &yPos);
			m_printError(SDL_GetError());

			MouseMovedEvent event{ xPos, yPos };
			m_data.EventCallback(event);
		}

	}

	KeyCode WindowsWindow::m_convertSDLToFazonKeyCode(SDL_Keycode sdlKeyCode) {

		switch (sdlKeyCode)
		{
		case SDLK_TAB: return Key::Tab;
		case SDLK_LEFT: return Key::Left;
		case SDLK_RIGHT: return Key::Right;
		case SDLK_UP: return Key::Up;
		case SDLK_DOWN: return Key::Down;
		case SDLK_PAGEUP: return Key::PageUp;
		case SDLK_PAGEDOWN: return Key::PageDown;
		case SDLK_HOME: return Key::Home;
		case SDLK_END: return Key::End;
		case SDLK_INSERT: return Key::Insert;
		case SDLK_DELETE: return Key::Delete;
		case SDLK_BACKSPACE: return Key::Backspace;
		case SDLK_SPACE: return Key::Space;
		case SDLK_RETURN: return Key::Return;
		case SDLK_ESCAPE: return Key::Escape;
		case SDLK_APOSTROPHE: return Key::Apostrophe;
		case SDLK_COMMA: return Key::Comma;
		case SDLK_MINUS: return Key::Minus;
		case SDLK_PERIOD: return Key::Period;
		case SDLK_SLASH: return Key::Slash;
		case SDLK_SEMICOLON: return Key::Semicolon;
		case SDLK_EQUALS: return Key::Equals;
		case SDLK_LEFTBRACKET: return Key::LeftBracket;
		case SDLK_BACKSLASH: return Key::Backslash;
		case SDLK_RIGHTBRACKET: return Key::RightBracket;
		case SDLK_GRAVE: return Key::Grave;
		case SDLK_CAPSLOCK: return Key::CapsLock;
		case SDLK_SCROLLLOCK: return Key::ScrollLock;
		case SDLK_NUMLOCKCLEAR: return Key::NumLock;
		case SDLK_PRINTSCREEN: return Key::PrintScreen;
		case SDLK_PAUSE: return Key::Pause;
		case SDLK_LCTRL: return Key::KpLeftCtrl;
		case SDLK_LSHIFT: return Key::KpLeftShift;
		case SDLK_LALT: return Key::KpLeftAlt;
		case SDLK_LGUI: return Key::KpLeftGUI;
		case SDLK_RCTRL: return Key::KpRightCtrl;
		case SDLK_RSHIFT: return Key::KpRightShift;
		case SDLK_RALT: return Key::KpRightAlt;
		case SDLK_RGUI: return Key::KpRightGUI;
		case SDLK_APPLICATION: return Key::Application;
		case SDLK_0: return Key::Zero;
		case SDLK_1: return Key::One;
		case SDLK_2: return Key::Two;
		case SDLK_3: return Key::Three;
		case SDLK_4: return Key::Four;
		case SDLK_5: return Key::Five;
		case SDLK_6: return Key::Six;
		case SDLK_7: return Key::Seven;
		case SDLK_8: return Key::Eight;
		case SDLK_9: return Key::Nine;
		case SDLK_A: return Key::A;
		case SDLK_B: return Key::B;
		case SDLK_C: return Key::C;
		case SDLK_D: return Key::D;
		case SDLK_E: return Key::E;
		case SDLK_F: return Key::F;
		case SDLK_G: return Key::G;
		case SDLK_H: return Key::H;
		case SDLK_I: return Key::I;
		case SDLK_J: return Key::J;
		case SDLK_K: return Key::K;
		case SDLK_L: return Key::L;
		case SDLK_M: return Key::M;
		case SDLK_N: return Key::N;
		case SDLK_O: return Key::O;
		case SDLK_P: return Key::P;
		case SDLK_Q: return Key::Q;
		case SDLK_R: return Key::R;
		case SDLK_S: return Key::S;
		case SDLK_T: return Key::T;
		case SDLK_U: return Key::U;
		case SDLK_V: return Key::V;
		case SDLK_W: return Key::W;
		case SDLK_X: return Key::X;
		case SDLK_Y: return Key::Y;
		case SDLK_Z: return Key::Z;
		case SDLK_F1: return Key::F1;
		case SDLK_F2: return Key::F2;
		case SDLK_F3: return Key::F3;
		case SDLK_F4: return Key::F4;
		case SDLK_F5: return Key::F5;
		case SDLK_F6: return Key::F6;
		case SDLK_F7: return Key::F7;
		case SDLK_F8: return Key::F8;
		case SDLK_F9: return Key::F9;
		case SDLK_F10: return Key::F10;
		case SDLK_F11: return Key::F11;
		case SDLK_F12: return Key::F12;
		case SDLK_F13: return Key::F13;
		case SDLK_F14: return Key::F14;
		case SDLK_F15: return Key::F15;
		case SDLK_F16: return Key::F16;
		case SDLK_F17: return Key::F17;
		case SDLK_F18: return Key::F18;
		case SDLK_F19: return Key::F19;
		case SDLK_F20: return Key::F20;
		case SDLK_F21: return Key::F21;
		case SDLK_F22: return Key::F22;
		case SDLK_F23: return Key::F23;
		case SDLK_F24: return Key::F24;
		case SDLK_AC_BACK: return Key::AcBack;
		case SDLK_AC_FORWARD: return Key::AcForward;
		default: break;
		}
		return Key::Unknown;

	}

}