#pragma once

#include "Fazon/fzpch.h"
#include "Fazon/Core.h"
#include "Events/WindowEvent.h"
#include "Window.h"

namespace Fazon {

	class Application {

	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

	private:
		bool onWindowClosed(WindowCloseEvent& event);

		std::unique_ptr<Window> m_window;
		bool m_running{ true };

	};

	// TO BE DEFINED IN CLIENT
	Application* createApplication();

}