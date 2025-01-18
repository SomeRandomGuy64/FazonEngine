#include "Application.h"
#include "Fazon/fzpch.h"

#include "Fazon/Events/WindowEvent.h"

#include <SDL3/SDL_opengl.h>

namespace Fazon {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() {

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

	}

	Application::~Application() {

	}

	void Application::onEvent([[maybe_unused]]Event& event) {

		EventDispatcher dispatcher{ event };
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClosed));

		FZ_CORE_INFO("{0}", event);

	}

	void Application::run() {

		while (m_running) {
			
			m_window->onUpdate();

		}

	}

	bool Application::onWindowClosed(WindowCloseEvent&) {

		m_running = false;
		return true;

	}

}