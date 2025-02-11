#pragma once	

#include "Fazon/fzpch.h"

#include <spdlog/fmt/bundled/format.h>

#ifdef FZ_PLATFORM_WINDOWS
	#pragma message("FZ_PLATFORM_WINDOWS is defined")
	#define DEBUG_BREAK() __debugbreak()

#elif FZ_PLATFORM_LINUX
	#pragma message("FZ_PLATFORM_LINUX is defined")
	#include <signal.h>
	#define DEBUG_BREAK() raise(SIGTRAP)

#elif FZ_PLATFORM_MACOS
	#pragma message("FZ_PLATFORM_MACOS is defined")
	#include <signal.h>
	#define DEBUG_BREAK() raise(SIGTRAP)

#else
	#error "Fazon only supports Windows!"
#endif

#ifdef FZ_DEBUG
	#define FZ_ENABLE_ASSERTS
#endif

#if FZ_ENABLE_ASSERTS
	#define FZ_ASSERT(x, ...) { if(!(x)) { FZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK(); } }
	#define FZ_CORE_ASSERT(x, ...) { if(!(x)) { FZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK(); } }
#else
	#define FZ_ASSERT(x, ...)
	#define FZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define FZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)