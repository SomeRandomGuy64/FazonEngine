#pragma once

#include "Core.h"

namespace Fazon {

	class Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// TO BE DEFINED IN CLIENT
	Application* createApplication();

}