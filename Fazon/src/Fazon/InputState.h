#pragma once

#include "Fazon/Core.h"
#include "Fazon/KeyCodes.h"
#include "Fazon/MouseCodes.h"

namespace Fazon {

	class InputState {

	public:

		static InputState* getInstance() { return s_instance; }

		static const bool* getKeyboardState(KeyCode keycode);
		static const bool* getMouseButtonState(MouseCode mousecode);
		static void setKeyboardState(KeyCode keycode, bool state);
		static void setMouseButtonState(MouseCode mousecode, bool state);

	private:

		static InputState* s_instance;

		static bool s_keyboardState[512];
		static bool s_mouseButtonState[512];

	};

}
