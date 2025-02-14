#include "WindowsInput.h"

#include "Fazon/fzpch.h"
#include "Fazon/InputState.h"

#include "Fazon/Platform/Windows/WindowsWindow.h"

#include <SDL3/SDL.h>

namespace Fazon {

	Input* Input::s_instance = new WindowsInput{};

	bool WindowsInput::isKeyPressedImpl(KeyCode keycode) {
		return *InputState::getKeyboardState(keycode);
	}

	bool WindowsInput::isMouseButtonPressedImpl(MouseCode mousecode) {
		return *InputState::getMouseButtonState(mousecode);
	}

	float WindowsInput::getMouseXImpl() {
		auto [x, y] { getMousePosImpl() };
		return x;
	}

	float WindowsInput::getMouseYImpl() {
		auto [x, y] { getMousePosImpl() };
		return y;
	}

	std::pair<float, float> WindowsInput::getMousePosImpl() {
		float x, y;
		SDL_GetMouseState(&x, &y);

		return std::pair<float, float>(x, y);
	}

}