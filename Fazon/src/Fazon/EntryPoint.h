#pragma once

#ifdef FZ_PLATFORM_WINDOWS

extern Fazon::Application* Fazon::createApplication();

int main(int, char**) {
	Fazon::Log::init();
	FZ_CORE_WARN("Initialised Logger!");
	int test{ 99 };
	FZ_DEBUG("Hello! Var={0}", test);

	auto app{ Fazon::createApplication() };
	app->run();
	delete app;
}

#endif