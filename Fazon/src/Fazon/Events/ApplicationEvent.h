#pragma once

#include "Event.h"

namespace Fazon {

	class AppEvent : public Event {

	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	protected:
		AppEvent()
		{
		}

	};

	class AppTickEvent : public AppEvent {

	public:
		AppTickEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "AppTickEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppTick)
	};

	class AppUpdateEvent : public AppEvent {

	public:
		AppUpdateEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "AppUpdateEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppUpdate)
	};

	class AppRenderEvent : public AppEvent {

	public:
		AppRenderEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "AppRenderEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppRender)
	};


}
