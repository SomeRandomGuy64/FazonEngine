#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Fazon {

	class Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};

}

#ifndef FZ_BUILD_DIST
	// Core log macros
	#define FZ_CORE_CRITICAL(...)	::Fazon::Log::getCoreLogger()->critical(__VA_ARGS__)
	#define FZ_CORE_ERROR(...)		::Fazon::Log::getCoreLogger()->error(__VA_ARGS__)
	#define FZ_CORE_WARN(...)		::Fazon::Log::getCoreLogger()->warn(__VA_ARGS__)
	#define FZ_CORE_INFO(...)		::Fazon::Log::getCoreLogger()->info(__VA_ARGS__)
	#define FZ_CORE_TRACE(...)		::Fazon::Log::getCoreLogger()->trace(__VA_ARGS__)
	#define FZ_CORE_DEBUG(...)		::Fazon::Log::getCoreLogger()->debug(__VA_ARGS__)

	// Client log macros
	#define FZ_CRITICAL(...)		::Fazon::Log::getClientLogger()->critical(__VA_ARGS__)
	#define FZ_ERROR(...)			::Fazon::Log::getClientLogger()->error(__VA_ARGS__)
	#define FZ_WARN(...)			::Fazon::Log::getClientLogger()->warn(__VA_ARGS__)
	#define FZ_INFO(...)			::Fazon::Log::getClientLogger()->info(__VA_ARGS__)
	#define FZ_DEBUG(...)			::Fazon::Log::getClientLogger()->debug(__VA_ARGS__)

#else
	// Core log macros
	#define FZ_CORE_CRITICAL(...)
	#define FZ_CORE_ERROR(...)
	#define FZ_CORE_WARN(...)
	#define FZ_CORE_INFO(...)
	#define FZ_CORE_TRACE(...)
	#define FZ_CORE_DEBUG(...)

	// Client log macros
	#define FZ_CRITICAL(...)
	#define FZ_ERROR(...)
	#define FZ_WARN(...)
	#define FZ_INFO(...)
	#define FZ_DEBUG(...)
#endif // !FZ_BUILD_DIST

