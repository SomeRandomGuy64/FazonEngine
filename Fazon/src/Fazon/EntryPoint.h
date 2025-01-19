#pragma once

#ifdef FZ_PLATFORM_WINDOWS

extern Fazon::Application* Fazon::createApplication();

void logTests() {

	printf("\n");
	FZ_CORE_CRITICAL("Core Critical");
	FZ_CORE_ERROR("Core Error");
	FZ_CORE_WARN("Core Warn");
	FZ_CORE_INFO("Core Info");
	FZ_CORE_TRACE("Core Trace");
	FZ_CORE_DEBUG("Core Debug\n");

	FZ_CRITICAL("App Critical");
	FZ_ERROR("App Error");
	FZ_WARN("App Warn");
	FZ_INFO("App Info");
	FZ_TRACE("App Trace");
	FZ_DEBUG("App Debug\n");

}

int main(int, char**) {
	Fazon::Log::init();
	auto app{ Fazon::createApplication() };

	logTests();

	app->run();
	delete app;
}

#endif