#include "Application.h"
#include "fzpch.h"

#include "Fazon/Events/WindowEvent.h"

#include "Input.h"

namespace Fazon {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{
		FZ_CORE_ASSERT(s_Instance == nullptr, "Application already exists!");
		s_Instance = this;

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application() 
	{
	}

	void Application::pushLayer(Layer* layer) {

		m_layerStack.pushLayer(layer);
		layer->onAttach();

	}

	void Application::pushOverlay(Layer* overlay) {
		m_layerStack.pushOverlay(overlay);
	}

	void Application::onEvent(Event& event) {

		EventDispatcher dispatcher{ event };
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::m_onWindowClosed));

		FZ_CORE_DEBUG("{0}", event);

		for (auto it{ m_layerStack.end() }; it != m_layerStack.begin(); ) {
			(*--it)->onEvent(event);
			if (event.handled) {
				break;
			}
		}

	}

	void Application::run() {
		while (m_running) {

			for (Layer* layer : m_layerStack) {
				layer->onUpdate();
			}

			auto [x, y] { Input::getMousePos() };
			FZ_CORE_TRACE("{0}, {1}", x, y);
			
			m_window->onUpdate();

		}
	}

	bool Application::m_onWindowClosed(WindowCloseEvent&) {

		m_running = false;
		return true;

	}

}