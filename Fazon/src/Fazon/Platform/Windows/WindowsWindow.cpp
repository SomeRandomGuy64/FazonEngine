#include "Fazon/fzpch.h"
#include "WindowsWindow.h"

#include <SDL3/SDL.h>

// update later to remove OpenGL specific stuff

namespace Fazon {

	static bool s_SDLInitialised{ false };

	Window* Window::create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		init(props);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props) {

		m_data.title = props.m_title;
		m_data.width = props.m_width;
		m_data.height = props.m_height;

		// OpenGL specific
		m_data.context = SDL_GL_CreateContext(m_window);

		FZ_CORE_INFO("Creating window {0} ({1}, {2})", props.m_title, props.m_width, props.m_height);

		if (!s_SDLInitialised) {
			// TODO: SDL_DestroyWindow on system shutdown
			[[maybe_unused]]bool success{ SDL_Init(SDL_INIT_VIDEO) };
			FZ_CORE_ASSERT(success, "Could not initialise SDL!");

			s_SDLInitialised = true;
		}

		m_window = SDL_CreateWindow(
			props.m_title, 
			static_cast<int>(props.m_width), 
			static_cast<int>(props.m_height), 
			SDL_WINDOW_MOUSE_FOCUS
		);
		
		// OpenGL specific
		SDL_GL_MakeCurrent(m_window, m_data.context);

		setVSync(true);

	}

	void WindowsWindow::shutdown() {
		SDL_GL_DestroyContext(m_data.context);
		SDL_DestroyWindow(m_window);
	}

	void WindowsWindow::onUpdate() {

		SDL_Event event;
		SDL_PollEvent(&event);

		// OpenGL specific
		SDL_GL_SwapWindow(m_window);

	}

	void WindowsWindow::setVSync(bool enabled) {

		if (enabled) {
			SDL_SetHintWithPriority(SDL_HINT_RENDER_VSYNC, "1", SDL_HINT_OVERRIDE);
		}
		else {
			SDL_SetHintWithPriority(SDL_HINT_RENDER_VSYNC, "0", SDL_HINT_OVERRIDE);
		}

		m_data.vSync = enabled;

	}

	bool WindowsWindow::isVSync() const {
		return m_data.vSync;
	}

}