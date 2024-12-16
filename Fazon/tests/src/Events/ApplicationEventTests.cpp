#include <catch2/catch_all.hpp>
#include <Fazon/Events/ApplicationEvent.h>

using namespace Fazon;

TEST_CASE("Application Event Basic Functionality", "[Application Events]") {

	SECTION("AppTickEvent") {

		AppTickEvent mockAppTickEvent{};

		REQUIRE(mockAppTickEvent.getCategoryFlags() == EventCategoryApplication);
		REQUIRE(mockAppTickEvent.isInCategory(EventCategoryApplication));
		REQUIRE(mockAppTickEvent.getEventType() == EventType::AppTick);

		REQUIRE_FALSE(mockAppTickEvent.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockAppTickEvent.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockAppTickEvent.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockAppTickEvent.isInCategory(EventCategoryMouseButton));
		REQUIRE_FALSE(mockAppTickEvent.isInCategory(EventCategoryWindow));

		REQUIRE(mockAppTickEvent.toString() == "AppTickEvent");

	}

	SECTION("AppUpdateEvent") {

		AppUpdateEvent mockAppUpdateEvent{};
		REQUIRE(mockAppUpdateEvent.getCategoryFlags() == EventCategoryApplication);
		REQUIRE(mockAppUpdateEvent.isInCategory(EventCategoryApplication));
		REQUIRE(mockAppUpdateEvent.getEventType() == EventType::AppUpdate);

		REQUIRE_FALSE(mockAppUpdateEvent.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockAppUpdateEvent.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockAppUpdateEvent.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockAppUpdateEvent.isInCategory(EventCategoryMouseButton));
		REQUIRE_FALSE(mockAppUpdateEvent.isInCategory(EventCategoryWindow));

		REQUIRE(mockAppUpdateEvent.toString() == "AppUpdateEvent");

	}

	SECTION("AppRenderEvent") {

		AppRenderEvent mockAppRenderEvent{};
		REQUIRE(mockAppRenderEvent.getCategoryFlags() == EventCategoryApplication);
		REQUIRE(mockAppRenderEvent.isInCategory(EventCategoryApplication));
		REQUIRE(mockAppRenderEvent.getEventType() == EventType::AppRender);

		REQUIRE_FALSE(mockAppRenderEvent.isInCategory(EventCategoryInput));
		REQUIRE_FALSE(mockAppRenderEvent.isInCategory(EventCategoryKeyboard));
		REQUIRE_FALSE(mockAppRenderEvent.isInCategory(EventCategoryMouse));
		REQUIRE_FALSE(mockAppRenderEvent.isInCategory(EventCategoryMouseButton));
		REQUIRE_FALSE(mockAppRenderEvent.isInCategory(EventCategoryWindow));

		REQUIRE(mockAppRenderEvent.toString() == "AppRenderEvent");

	}

}
