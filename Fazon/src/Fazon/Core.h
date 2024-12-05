#pragma once

#ifdef FZ_PLATFORM_WINDOWS
	#pragma message("FZ_PLATFORM_WINDOWS is defined")
#else
	#error "Fazon only supports Windows!"
#endif