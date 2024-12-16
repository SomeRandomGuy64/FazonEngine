#include <catch2/catch_all.hpp>
#include <Fazon/Events/WindowEvent.h>

using namespace Fazon;

TEST_CASE("Window Event Basic Functionality", "[Window Events]") {

	SECTION("WindowClose") {

		WindowCloseEvent mockClose{};

		REQUIRE(mockClose.getCategoryFlags() ==
			EventCategoryWindow	+
			EventCategoryApplication
		);
		REQUIRE(mockClose.isInCategory(EventCategoryWindow));
		REQUIRE(mockClose.isInCategory(EventCategoryApplication));

		REQUIRE_FALSE(mockClose.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockClose.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockClose.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockClose.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockClose.getEventType() == EventType::WindowClose);

		REQUIRE(mockClose.toString() == "WindowCloseEvent");

	}

	SECTION("WindowOpen") {

		WindowOpenEvent mockOpen{};

		REQUIRE(mockOpen.getCategoryFlags() ==
			EventCategoryWindow +
			EventCategoryApplication
		);
		REQUIRE(mockOpen.isInCategory(EventCategoryWindow));
		REQUIRE(mockOpen.isInCategory(EventCategoryApplication));

		REQUIRE_FALSE(mockOpen.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockOpen.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockOpen.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockOpen.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockOpen.getEventType() == EventType::WindowOpen);

		REQUIRE(mockOpen.toString() == "WindowOpenEvent");

	}

	SECTION("WindowFocus") {

		WindowFocusEvent mockFocus{};

		REQUIRE(mockFocus.getCategoryFlags() ==
			EventCategoryWindow +
			EventCategoryApplication
		);
		REQUIRE(mockFocus.isInCategory(EventCategoryWindow));
		REQUIRE(mockFocus.isInCategory(EventCategoryApplication));

		REQUIRE_FALSE(mockFocus.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockFocus.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockFocus.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockFocus.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockFocus.getEventType() == EventType::WindowFocus);

		REQUIRE(mockFocus.toString() == "WindowFocusEvent");

	}

	SECTION("WindowLostFocus") {

		WindowLostFocusEvent mockLostFocus{};

		REQUIRE(mockLostFocus.getCategoryFlags() ==
			EventCategoryWindow +
			EventCategoryApplication
		);
		REQUIRE(mockLostFocus.isInCategory(EventCategoryWindow));
		REQUIRE(mockLostFocus.isInCategory(EventCategoryApplication));

		REQUIRE_FALSE(mockLostFocus.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockLostFocus.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockLostFocus.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockLostFocus.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockLostFocus.getEventType() == EventType::WindowLostFocus);

		REQUIRE(mockLostFocus.toString() == "WindowLostFocusEvent");

	}

	SECTION("WindowMoved") {

		WindowMovedEvent mockMoved{ 80, 40 };

		REQUIRE(mockMoved.getCategoryFlags() ==
			EventCategoryWindow +
			EventCategoryApplication
		);
		REQUIRE(mockMoved.isInCategory(EventCategoryWindow));
		REQUIRE(mockMoved.isInCategory(EventCategoryApplication));

		REQUIRE_FALSE(mockMoved.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockMoved.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockMoved.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockMoved.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockMoved.getEventType() == EventType::WindowMoved);

		REQUIRE(mockMoved.toString() == "WindowMovedEvent: X: 80, Y: 40");

	}

	SECTION("WindowResized") {

		WindowResizedEvent mockResize{ 1280, 720 };

		REQUIRE(mockResize.getCategoryFlags() ==
			EventCategoryWindow +
			EventCategoryApplication
		);
		REQUIRE(mockResize.isInCategory(EventCategoryWindow));
		REQUIRE(mockResize.isInCategory(EventCategoryApplication));

		REQUIRE_FALSE(mockResize.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockResize.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockResize.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockResize.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockResize.getEventType() == EventType::WindowResized);

		REQUIRE(mockResize.toString() == 
			"WindowResizedEvent: Width: 1280, Height: 720"
		);

	}

}