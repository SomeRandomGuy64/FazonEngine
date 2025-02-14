#pragma once

#include "Fazon/Core.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace Fazon {

	class Input {

	public:

		static bool isKeyPressed(KeyCode keycode) { return s_instance->isKeyPressedImpl(keycode); }
		static bool isMouseButtonPressed(MouseCode mousecode) { return s_instance->isMouseButtonPressedImpl(mousecode); }
		static float getMouseX() { return s_instance->getMouseXImpl(); }
		static float getMouseY() { return s_instance->getMouseYImpl(); }
		static std::pair<float, float> getMousePos() { return s_instance->getMousePosImpl(); }

	protected:

		virtual bool isKeyPressedImpl(KeyCode keycode) = 0;
		virtual bool isMouseButtonPressedImpl(MouseCode mousecode) = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
		virtual std::pair<float, float> getMousePosImpl() = 0;

	private:

		static Input* s_instance;

	};

}
