#pragma once

#include "Fazon/fzpch.h"
#include "Fazon/Core.h"
#include "Window.h"

namespace Fazon {

	class Application {

	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> m_window;
		bool m_running{ true };

	};

	// TO BE DEFINED IN CLIENT
	Application* createApplication();

}