#pragma once

#ifdef FZ_PLATFORM_WINDOWS

extern Fazon::Application* Fazon::createApplication();

int main(int, char**) {
	Fazon::Log::init();
	auto app{ Fazon::createApplication() };
	app->run();
	delete app;
}

#endif