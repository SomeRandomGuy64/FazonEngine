#include "Application.h"

#include "Fazon/Events/WindowEvent.h"
#include "Fazon/Log.h"

#include <iostream>

namespace Fazon {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowCloseEvent close{};
		WindowOpenEvent open{};
		WindowFocusEvent focus{};
		WindowLostFocusEvent lostFocus{};
		WindowMovedEvent moved{ 10, 10 };
		WindowResizedEvent resized{ 10, 10 };

		FZ_TRACE(focus);

		while (true) {

		}
	}

}