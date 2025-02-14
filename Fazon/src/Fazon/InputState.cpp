#include "InputState.h"

#include "fzpch.h"

namespace Fazon {

	InputState* InputState::s_instance = nullptr;
	bool InputState::s_keyboardState[512] = { true };
	bool InputState::s_mouseButtonState[512] = { false };

	void InputState::setKeyboardState(KeyCode keycode, bool state) {
		s_keyboardState[keycode] = state;
	}

	void InputState::setMouseButtonState(MouseCode mousecode, bool state) {
		s_mouseButtonState[mousecode] = state;
	}

	const bool* InputState::getKeyboardState(KeyCode keycode) {
		return &s_keyboardState[keycode];
	}

	const bool* InputState::getMouseButtonState(MouseCode mousecode) {
		return &s_mouseButtonState[mousecode];
	}

}