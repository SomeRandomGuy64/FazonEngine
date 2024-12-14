#pragma once

#include "Fazon/fzpch.h"

#include <spdlog/fmt/fmt.h>

#ifdef FZ_PLATFORM_WINDOWS
	#pragma message("FZ_PLATFORM_WINDOWS is defined")
#else
	#error "Fazon only supports Windows!"
#endif

#define BIT(x) (1 << x)