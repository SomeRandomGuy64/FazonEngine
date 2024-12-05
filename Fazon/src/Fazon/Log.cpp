#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Fazon {

	std::shared_ptr<spdlog::logger> Log::s_coreLogger;
	std::shared_ptr<spdlog::logger> Log::s_clientLogger;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_coreLogger = spdlog::stderr_color_mt("FAZON");
		s_coreLogger->set_level(spdlog::level::trace);

		s_clientLogger = spdlog::stderr_color_mt("APP");
		s_clientLogger->set_level(spdlog::level::trace);
	}

}