#pragma once

#include "Event.h"

namespace Fazon {

	class KeyEvent : public Event {

	public:
		inline int getKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_keyCode(keycode)
		{
		}

		int m_keyCode{};
	};

	class KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(uint32_t keycode, uint32_t repeatCount)
			: KeyEvent(keycode)
			, m_repeatCount(repeatCount)
		{
		}

		inline int getRepeatCount() const { return m_repeatCount; }

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
		KeyReleasedEvent(uint32_t keycode)
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

}