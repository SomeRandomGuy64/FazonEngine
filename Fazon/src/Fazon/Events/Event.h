#pragma once

#include "Fazon/Core.h"

namespace Fazon {

	// events are currently blocking
	// later build an event bus to buffer events for the event part of the update stage

	enum class EventType {

		None = 0,
		WindowClose, WindowOpen, WindowFocus, WindowLostFocus, WindowMoved, WindowResized,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

	};

#define EVENT_CLASS_TYPE(type)	static EventType getStaticType() { return EventType::##type; }				\
								virtual EventType getEventType() const override { return getStaticType(); }	\
								virtual const char* getName() const override { return #type; }				\

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	enum EventCategory {

		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
		EventCategoryWindow			= BIT(5),

	};

	class Event {

		friend class EventDispatcher;

	public:

		bool handled{ false };

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const{ return getName(); }

		inline bool isInCategory(EventCategory category) { return getCategoryFlags() & category; }

	};

	class EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_event(event)
		{
		}

		template<typename T>
		bool dispatch(EventFn<T> func) {
			if (m_event.getEventType() == T::getStaticType()) {
				m_event.handled |= func(static_cast<T&>(m_event));
				return true;
			}
			return false;
		}

	private:
		Event& m_event;

	};

}

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<Fazon::Event, T>, char>> :
		fmt::formatter<std::string> {

	auto format(const Fazon::Event& event, format_context& ctx) const {
		return formatter<std::string>::format(event.toString(), ctx);
	}
};
