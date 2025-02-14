#pragma once

#include "Event.h"
#include "Fazon/InputState.h"
#include "Fazon/MouseCodes.h"

namespace Fazon {

	class MouseButtonEvent : public Event {

	public:
		inline MouseCode getMouseButtonCode() const { return m_mouseButtonCode - 1; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput);
	protected:
		MouseButtonEvent(MouseCode mouseButtonCode)
			: m_mouseButtonCode(mouseButtonCode)
		{
		}

		MouseCode m_mouseButtonCode{};
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(MouseCode mouseButtonCode)
			: MouseButtonEvent(mouseButtonCode)
		{
			InputState::setMouseButtonState(mouseButtonCode, true);
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseButtonPressedEvent: " << m_mouseButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(MouseCode mouseButtonCode)
			: MouseButtonEvent(mouseButtonCode)
		{
			InputState::setMouseButtonState(mouseButtonCode, false);
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseButtonReleasedEvent: " << m_mouseButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(float xPosition, float yPosition)
			: m_xPosition(xPosition)
			, m_yPosition(yPosition)
		{
		}

		inline float getXPosition() const { return m_xPosition; }
		inline float getYPosition() const { return m_yPosition; }

		std::string toString() const override {
			std::stringstream ss{};
			ss << "MouseMovedEvent: X: " << m_xPosition << ", Y: " << m_yPosition;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved)
	private:

		float m_xPosition{};
		float m_yPosition{};
	};

	struct MouseScrollDirection {
		
		MouseScrollDirection() = default;

		MouseScrollDirection(float yOffset, float xOffset = 0.0f)
			: m_yOffset{ yOffset }
			, m_xOffset{ xOffset }
		{}

		// a positive value shows upwards scrolling, a negative value shows downwards scrolling
		float m_yOffset{};
		// a positive value show scrolling to the right, a negative value shows scrolling to the left
		float m_xOffset{};

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
			ss << "MouseScrolledEvent: Vertical: " << m_scrollDirection.m_yOffset 
			   << ", Horizontal: " << m_scrollDirection.m_xOffset;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		MouseScrollDirection m_scrollDirection{};
	};
}