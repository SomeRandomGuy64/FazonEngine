#include <catch2/catch_all.hpp>
#include <Fazon/Events/MouseEvent.h>

using namespace Fazon;

TEST_CASE("Mouse Event Basic Functionality", "[Mouse Events]") {

	SECTION("MouseButtonPressed") {

		MouseButtonPressedEvent mockPress{ 2 };

		REQUIRE(
			mockPress.getCategoryFlags() == 
				EventCategoryMouse			+
				EventCategoryMouseButton	+
				EventCategoryInput
		);
		REQUIRE(mockPress.isInCategory(EventCategoryMouse));
		REQUIRE(mockPress.isInCategory(EventCategoryMouseButton));
		REQUIRE(mockPress.isInCategory(EventCategoryInput));

		REQUIRE_FALSE(mockPress.isInCategory(EventCategoryApplication));
		REQUIRE_FALSE(mockPress.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockPress.isInCategory(EventCategoryWindow));

		REQUIRE(mockPress.getEventType() == EventType::MouseButtonPressed);

		REQUIRE(mockPress.toString() == "MouseButtonPressedEvent: 2");

	}

	SECTION("MouseButtonReleased") {

		MouseButtonReleasedEvent mockRelease{ 2 };

		REQUIRE(
			mockRelease.getCategoryFlags() ==
			EventCategoryMouse			+
			EventCategoryMouseButton	+
			EventCategoryInput
		);
		REQUIRE(mockRelease.isInCategory(EventCategoryMouse));
		REQUIRE(mockRelease.isInCategory(EventCategoryMouseButton));
		REQUIRE(mockRelease.isInCategory(EventCategoryInput));

		REQUIRE_FALSE(mockRelease.isInCategory(EventCategoryApplication));
		REQUIRE_FALSE(mockRelease.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockRelease.isInCategory(EventCategoryWindow));

		REQUIRE(mockRelease.getEventType() == EventType::MouseButtonReleased);

		REQUIRE(mockRelease.toString() == "MouseButtonReleasedEvent: 2");

	}

	SECTION("MouseMoved") {

		MouseMovedEvent mockMove{ 674, 213 };

		REQUIRE(
			mockMove.getCategoryFlags() ==
			EventCategoryMouse +
			EventCategoryInput
		);
		REQUIRE(mockMove.isInCategory(EventCategoryMouse));
		REQUIRE(mockMove.isInCategory(EventCategoryInput));

		REQUIRE_FALSE(mockMove.isInCategory(EventCategoryMouseButton));
		REQUIRE_FALSE(mockMove.isInCategory(EventCategoryApplication));
		REQUIRE_FALSE(mockMove.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockMove.isInCategory(EventCategoryWindow));

		REQUIRE(mockMove.getEventType() == EventType::MouseMoved);

		REQUIRE(mockMove.toString() == "MouseMovedEvent: X: 674, Y: 213");

	}

	SECTION("MouseScrolled") {

		MouseScrollDirection scrollDirections{};
		scrollDirections.vertical = 10.0f;
		scrollDirections.horizontal = 0.0f;

		MouseScrolledEvent mockScroll{ scrollDirections };

		REQUIRE(
			mockScroll.getCategoryFlags() ==
			EventCategoryMouse +
			EventCategoryInput
		);
		REQUIRE(mockScroll.isInCategory(EventCategoryMouse));
		REQUIRE(mockScroll.isInCategory(EventCategoryInput));

		REQUIRE_FALSE(mockScroll.isInCategory(EventCategoryMouseButton));
		REQUIRE_FALSE(mockScroll.isInCategory(EventCategoryApplication));
		REQUIRE_FALSE(mockScroll.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockScroll.isInCategory(EventCategoryWindow));

		REQUIRE(mockScroll.getEventType() == EventType::MouseScrolled);

		REQUIRE(mockScroll.toString() == "MouseScrolledEvent: Vertical: 10, Horizontal: 0");

		MouseScrollDirection negativeDirections{};
		negativeDirections.vertical = -5.0f;
		negativeDirections.horizontal = -2.5f;

		MouseScrolledEvent mockNegativeScroll{ negativeDirections };

		REQUIRE(mockNegativeScroll.toString() == 
			"MouseScrolledEvent: Vertical: -5, Horizontal: -2.5"
		);

	}

}