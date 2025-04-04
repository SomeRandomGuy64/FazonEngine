#include "Fazon/fzpch.h"
#include "WindowsWindow.h"

#include "Fazon/Events/ApplicationEvent.h"
#include "Fazon/Events/WindowEvent.h"
#include "Fazon/Events/KeyEvent.h"
#include "Fazon/Events/MouseEvent.h"

#include "Fazon/Platform/OpenGL/OpenGLContext.h"

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
		m_context = new OpenGLContext{ m_window };

		m_context->init();
		
		m_printError(SDL_GetError());
		setVSync(true);

	}

	void WindowsWindow::m_shutdown() {
		m_context->destroyContext();
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

		m_context->swapBuffers();

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
				KeyPressedEvent event{ convertSDLKeyToFazonKey(m_sdlEvent.key), 1 };
				m_data.EventCallback(event);
			}
			else {
				KeyPressedEvent event{ convertSDLKeyToFazonKey(m_sdlEvent.key), 0 };
				m_data.EventCallback(event);
			}
		}
		else if (m_sdlEvent.type == SDL_EVENT_KEY_UP) {
			KeyReleasedEvent event{ convertSDLKeyToFazonKey(m_sdlEvent.key) };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_keyTypeEvent() {
		
		if (m_sdlEvent.type == SDL_EVENT_KEY_DOWN) {
			KeyTypedEvent event{ convertSDLKeyToFazonKey(m_sdlEvent.key) };
			m_data.EventCallback(event);
		}

	}

	void WindowsWindow::m_mouseButtonPressEvent() {

		if (m_sdlEvent.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			MouseButtonPressedEvent event{ static_cast<MouseCode>(m_sdlEvent.button.button) };
			m_data.EventCallback(event);
		}
		else if (m_sdlEvent.type == SDL_EVENT_MOUSE_BUTTON_UP) {
			MouseButtonReleasedEvent event{ static_cast<MouseCode>(m_sdlEvent.button.button) };
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

}