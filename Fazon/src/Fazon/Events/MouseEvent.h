#pragma once

#include "Event.h"

namespace Fazon {

	class MouseButtonEvent : public Event {

	public:
		inline int getMouseButtonCode() const { return m_mouseButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput);
	protected:
		MouseButtonEvent(int mouseButtonCode)
			: m_mouseButtonCode(mouseButtonCode)
		{
		}

		int m_mouseButtonCode{};
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int mouseButtonCode)
			: MouseButtonEvent(mouseButtonCode)
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseButtonPressedEvent: " << m_mouseButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int mouseButtonCode)
			: MouseButtonEvent(mouseButtonCode)
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseButtonReleasedEvent: " << m_mouseButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};

	class MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(int xPosition, int yPosition)
			: m_xPosition(xPosition)
			, m_yPosition(yPosition)
		{
		}

		inline int getXPosition() const { return m_xPosition; }
		inline int getYPosition() const { return m_yPosition; }

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseMovedEvent: X: " << m_xPosition << ", Y: " << m_yPosition;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved)
	private:

		int m_xPosition{};
		int m_yPosition{};
	};

	struct MouseScrollDirection {
		// a positive value shows upwards scrolling, a negative value shows downwards scrolling
		float vertical{};
		// a positive value show scrolling to the right, a negative value shows scrolling to the left
		float horizontal{};
	};

	class MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(MouseScrollDirection scrollDirection)
			: m_scrollDirection(scrollDirection)
		{
		}

		inline MouseScrollDirection getScrollDirection() const { return m_scrollDirection; }

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseScrolledEvent: Vertical: " << m_scrollDirection.vertical 
			   << ", Horizontal: " << m_scrollDirection.horizontal;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseScrolled);

	private:
		MouseScrollDirection m_scrollDirection{};
	};
}