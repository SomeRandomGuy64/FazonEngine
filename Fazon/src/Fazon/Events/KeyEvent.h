#pragma once

#include "Event.h"

namespace Fazon {

	class KeyEvent : public Event {

	public:
		inline KeyCode getKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(KeyCode keycode)
			: m_keyCode(keycode)
		{
		}

		KeyCode m_keyCode{};
	};

	class KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(KeyCode keycode, uint32_t repeatCount)
			: KeyEvent(keycode)
			, m_repeatCount(repeatCount)
		{
		}

		inline uint32_t getRepeatCount() const { return m_repeatCount; }

		std::string toString() const override {
			std::stringstream ss{};
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_repeatCount{};

	};

	class KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(KeyCode keycode)
			: KeyEvent(keycode)
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent {

	public:
		KeyTypedEvent(KeyCode keycode)
			: KeyEvent(keycode)
		{
		}

		std::string toString() const override {
			std::stringstream ss{};
			ss << "KeyTypedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)

	};

}