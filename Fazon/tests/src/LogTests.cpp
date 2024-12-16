#include <catch2/catch_all.hpp>
#include <Fazon/Log.h>

TEST_CASE("Logging System", "[logging]") {

	SECTION("Testing Core Log Functions") {
		
		Fazon::Log mockLogger{};
		mockLogger.init();

#ifndef FZ_BUILD_DIST

		FZ_CORE_CRITICAL("Critical");

#endif // !FZ_BUILD_DIST


	}

}
