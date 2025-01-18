#include "Application.h"
#include "Fazon/fzpch.h"

#include "Fazon/Events/WindowEvent.h"

#include <SDL3/SDL_opengl.h>

namespace Fazon {

	Application::Application() {
		m_window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application() {

	}

	void Application::run() {

		while (m_running) {
			
			m_window->onUpdate();

		}

	}

}