#pragma once

#include "Event.h"

namespace Fazon {

	class WindowEvent : public Event {

	public:
		EVENT_CLASS_CATEGORY(EventCategoryWindow | EventCategoryApplication)

	protected:
		WindowEvent()
		{
		}
	};

	class WindowCloseEvent : public WindowEvent {

	public:
		WindowCloseEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
	};

	class WindowOpenEvent : public WindowEvent {

	public:
		WindowOpenEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "WindowOpenEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowOpen)
	};

	class WindowFocusEvent : public WindowEvent {

	public:
		WindowFocusEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "WindowFocusEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowFocus)
	};

	class WindowLostFocusEvent : public WindowEvent {

	public:
		WindowLostFocusEvent()
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "WindowLostFocusEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowLostFocus)
	};

	class WindowMovedEvent : public WindowEvent {

	public:
		WindowMovedEvent(int xPosition, int yPosition)
			: m_xPosition{ xPosition }
			, m_yPosition{ yPosition }
		{
		}

		inline int getXPosition() { return m_xPosition; }
		inline int getYPosition() { return m_yPosition; }

		std::string toString() const override {
			std::stringstream ss{};
			ss << "WindowMovedEvent: X: " << m_xPosition << ", Y: " << m_yPosition;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)

	private:

		int m_xPosition{};
		int m_yPosition{};
	};

	class WindowResizedEvent : public WindowEvent {

	public:
		WindowResizedEvent(int width, int height)
			: m_width{ width }
			, m_height{ height }
		{
		}

		inline int getWidth() { return m_width; }
		inline int getHeight() { return m_height; }

		std::string toString() const override {
			std::stringstream ss{};
			ss << "WindowResizedEvent: Width: " << m_width << ", Height: " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)

	private:

		int m_width{};
		int m_height{};

	};

}
