#include <catch2/catch_all.hpp>
#include <Fazon/Events/KeyEvent.h>

using namespace Fazon;

TEST_CASE("Key Event Basic Functionality", "[Key Events]") {

	SECTION("KeyPressedEvent") {

		KeyPressedEvent mockKeyPressedEvent{ 64, 7 };

		REQUIRE(mockKeyPressedEvent.getCategoryFlags() == EventCategoryKeyboard + EventCategoryInput);
		REQUIRE(mockKeyPressedEvent.isInCategory(EventCategoryKeyboard));
		REQUIRE(mockKeyPressedEvent.isInCategory(EventCategoryInput));

		REQUIRE_FALSE(mockKeyPressedEvent.isInCategory(EventCategoryApplication));
		REQUIRE_FALSE(mockKeyPressedEvent.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockKeyPressedEvent.isInCategory(EventCategoryMouseButton));
		REQUIRE_FALSE(mockKeyPressedEvent.isInCategory(EventCategoryWindow));

		REQUIRE(mockKeyPressedEvent.getEventType() == EventType::KeyPressed);

		REQUIRE(mockKeyPressedEvent.getRepeatCount() == 7);

		REQUIRE(mockKeyPressedEvent.toString() == "KeyPressedEvent: 64 (7 repeats)");

	}

	SECTION("KeyReleasedEvent") {

		KeyReleasedEvent mockKeyReleasedEvent{ 64 };

		REQUIRE(mockKeyReleasedEvent.getCategoryFlags() == EventCategoryKeyboard + EventCategoryInput);
		REQUIRE(mockKeyReleasedEvent.isInCategory(EventCategoryKeyboard));
		REQUIRE(mockKeyReleasedEvent.isInCategory(EventCategoryInput));

		REQUIRE_FALSE(mockKeyReleasedEvent.isInCategory(EventCategoryApplication));
		REQUIRE_FALSE(mockKeyReleasedEvent.isInCategory(EventCategoryWindow));
		REQUIRE_FALSE(mockKeyReleasedEvent.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockKeyReleasedEvent.isInCategory(EventCategoryMouseButton));

		REQUIRE(mockKeyReleasedEvent.getEventType() == EventType::KeyReleased);

		REQUIRE(mockKeyReleasedEvent.toString() == "KeyReleasedEvent: 64");

	}

}