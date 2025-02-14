#pragma once

#include "Fazon/Input.h"

namespace Fazon {

	class WindowsInput : public Input {

	protected:

		virtual bool isKeyPressedImpl(KeyCode keycode);
		virtual bool isMouseButtonPressedImpl(MouseCode mousecode);
		virtual float getMouseXImpl();
		virtual float getMouseYImpl();
		virtual std::pair<float, float> getMousePosImpl();

	};

}
