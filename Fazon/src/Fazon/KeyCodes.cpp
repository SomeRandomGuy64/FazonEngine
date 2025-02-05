#include "KeyCodes.h"
#include "InputState.h"

namespace Fazon {

	char convertFazonKeyToChar(KeyCode key) {

		switch (InputState::getInstance().isShiftHeld()) {
			case false: {
				switch (key) {
					case Key::A:
					case Key::KpA:					return 'a';
					case Key::B:
					case Key::KpB:					return 'b';
					case Key::C:
					case Key::KpC:					return 'c';
					case Key::D:
					case Key::KpD:					return 'd';
					case Key::E:
					case Key::KpE:					return 'e';
					case Key::F:
					case Key::KpF:					return 'f';
					case Key::G:					return 'g';
					case Key::H:					return 'h';
					case Key::I:					return 'i';
					case Key::J:					return 'j';
					case Key::K:					return 'k';
					case Key::L:					return 'l';
					case Key::M:					return 'm';
					case Key::N:					return 'n';
					case Key::O:					return 'o';
					case Key::P:					return 'p';
					case Key::Q:					return 'q';
					case Key::R:					return 'r';
					case Key::S:					return 's';
					case Key::T:					return 't';
					case Key::U:					return 'u';
					case Key::V:					return 'v';
					case Key::W:					return 'w';
					case Key::X:					return 'x';
					case Key::Y:					return 'y';
					case Key::Z:					return 'z';

					case Key::One:
					case Key::KpOne:				return '1';
					case Key::Two:
					case Key::KpTwo:				return '2';
					case Key::Three:
					case Key::KpThree:				return '3';
					case Key::Four:
					case Key::KpFour:				return '4';
					case Key::Five:
					case Key::KpFive:				return '5';
					case Key::Six:
					case Key::KpSix:				return '6';
					case Key::Seven:
					case Key::KpSeven:				return '7';
					case Key::Eight:
					case Key::KpEight:				return '8';
					case Key::Nine:
					case Key::KpNine:				return '9';
					case Key::Zero:
					case Key::KpZero:				return '0';

					case Key::Space:
					case Key::KpSpace:				return ' ';
					case Key::Minus:
					case Key::KpMinus:				return '-';
					case Key::Equals:
					case Key::KpEquals:				return '=';
					case Key::LeftBracket:			return '[';
					case Key::RightBracket:			return ']';
					case Key::KpLeftParenthesis:	return '(';
					case Key::KpRightParenthesis:	return ')';
					case Key::KpLeftBrace:			return '{';
					case Key::KpRightBrace:			return '}';
					case Key::Slash:				return '/';
					case Key::Backslash:
					case Key::NonUSBackslash:		return '\\';
					case Key::KpHash:
					case Key::NonUSHash:			return '#';
					case Key::Semicolon:			return ';';
					case Key::KpColon:				return ':';
					case Key::Apostrophe:			return '\'';
					case Key::Grave:				return '`';
					case Key::Comma:
					case Key::KpComma:				return ',';
					case Key::Period:
					case Key::KpPeriod:
					case Key::KpFullStop:			return '.';
					case Key::KpDivide:				return '/';
					case Key::KpMultiply:			return '*';
					case Key::KpPlus:				return '+';
					case Key::KpPercent:			return '%';
					case Key::KpLess:				return '<';
					case Key::KpGreater:			return '>';
					case Key::KpAmpersand:			return '&';
					case Key::KpVerticalBar:		return '|';
					case Key::KpAt:					return '@';
					case Key::KpExclam:				return '!';

					default:						return ' ';
				}

			}
			case true: {
				switch (key) {
					case Key::A:
					case Key::KpA:					return 'A';
					case Key::B:
					case Key::KpB:					return 'B';
					case Key::C:
					case Key::KpC:					return 'C';
					case Key::D:
					case Key::KpD:					return 'D';
					case Key::E:
					case Key::KpE:					return 'E';
					case Key::F:
					case Key::KpF:					return 'F';
					case Key::G:					return 'G';
					case Key::H:					return 'H';
					case Key::I:					return 'I';
					case Key::J:					return 'J';
					case Key::K:					return 'K';
					case Key::L:					return 'L';
					case Key::M:					return 'M';
					case Key::N:					return 'N';
					case Key::O:					return 'O';
					case Key::P:					return 'P';
					case Key::Q:					return 'Q';
					case Key::R:					return 'R';
					case Key::S:					return 'S';
					case Key::T:					return 'T';
					case Key::U:					return 'U';
					case Key::V:					return 'V';
					case Key::W:					return 'W';
					case Key::X:					return 'X';
					case Key::Y:					return 'Y';
					case Key::Z:					return 'Z';

					case Key::One:					return '!';
					case Key::KpOne:				return '1';
					case Key::Two:					return '@';
					case Key::KpTwo:				return '2';
					case Key::Three:				return '#';
					case Key::KpThree:				return '3';
					case Key::Four:					return '$';
					case Key::KpFour:				return '4';
					case Key::Five:					return '%';
					case Key::KpFive:				return '5';
					case Key::Six:					return '^';
					case Key::KpSix:				return '6';
					case Key::Seven:				return '&';
					case Key::KpSeven:				return '7';
					case Key::Eight:				return '*';
					case Key::KpEight:				return '8';
					case Key::Nine:					return '(';
					case Key::KpNine:				return '9';
					case Key::Zero:					return ')';
					case Key::KpZero:				return '0';

					case Key::Space:
					case Key::KpSpace:				return ' ';
					case Key::Minus:				return '_';
					case Key::KpMinus:				return '-';
					case Key::Equals:				return '+';
					case Key::KpEquals:				return '=';
					case Key::LeftBracket:			return '{';
					case Key::RightBracket:			return '}';
					case Key::KpLeftParenthesis:	return '(';
					case Key::KpRightParenthesis:	return ')';
					case Key::KpLeftBrace:			return '{';
					case Key::KpRightBrace:			return '}';
					case Key::Slash:				return '/';
					case Key::Backslash:
					case Key::NonUSBackslash:		return '\\';
					case Key::KpHash:
					case Key::NonUSHash:			return '#';
					case Key::Semicolon:			return ':';
					case Key::KpColon:				return ':';
					case Key::Apostrophe:			return '"';
					case Key::Grave:				return '~';
					case Key::Comma:				return '<';
					case Key::KpComma:				return ',';
					case Key::Period:				return '>';
					case Key::KpPeriod:
					case Key::KpFullStop:			return '.';
					case Key::KpDivide:				return '/';
					case Key::KpMultiply:			return '*';
					case Key::KpPlus:				return '+';
					case Key::KpPercent:			return '%';
					case Key::KpLess:				return '<';
					case Key::KpGreater:			return '>';
					case Key::KpAmpersand:			return '&';
					case Key::KpVerticalBar:		return '|';
					case Key::KpAt:					return '@';
					case Key::KpExclam:				return '!';

					default:						return ' ';
				}

			}
		}

		return ' ';
	}

	ImGuiKey convertFazonKeyToImguiKeyCode(KeyCode keycode) {

		switch (keycode) {
			case Key::Tab:			return ImGuiKey_Tab;
			case Key::Left:			return ImGuiKey_LeftArrow;
			case Key::Right:		return ImGuiKey_RightArrow;
			case Key::Up:			return ImGuiKey_UpArrow;
			case Key::Down:			return ImGuiKey_DownArrow;
			case Key::PageUp:		return ImGuiKey_PageUp;
			case Key::PageDown:		return ImGuiKey_PageDown;
			case Key::Home:			return ImGuiKey_Home;
			case Key::End:			return ImGuiKey_End;
			case Key::Insert:		return ImGuiKey_Insert;
			case Key::Delete:		return ImGuiKey_Delete;
			case Key::Backspace:	return ImGuiKey_Backspace;
			case Key::Space:		return ImGuiKey_Space;
			case Key::Return:		return ImGuiKey_Enter;
			case Key::Escape:		return ImGuiKey_Escape;
			case Key::Apostrophe:	return ImGuiKey_Apostrophe;
			case Key::Comma:		return ImGuiKey_Comma;
			case Key::Minus:		return ImGuiKey_Minus;
			case Key::Period:		return ImGuiKey_Period;
			case Key::Slash:		return ImGuiKey_Slash;
			case Key::Semicolon:	return ImGuiKey_Semicolon;
			case Key::Equals:		return ImGuiKey_Equal;
			case Key::LeftBracket:	return ImGuiKey_LeftBracket;
			case Key::Backslash:	return ImGuiKey_Backslash;
			case Key::RightBracket: return ImGuiKey_RightBracket;
			case Key::Grave:		return ImGuiKey_GraveAccent;
			case Key::CapsLock:		return ImGuiKey_CapsLock;
			case Key::ScrollLock:	return ImGuiKey_ScrollLock;
			case Key::NumLock:		return ImGuiKey_NumLock;
			case Key::PrintScreen:	return ImGuiKey_PrintScreen;
			case Key::Pause:		return ImGuiKey_Pause;
			case Key::KpLeftCtrl:	return ImGuiKey_LeftCtrl;
			case Key::KpLeftShift:	return ImGuiKey_LeftShift;
			case Key::KpLeftAlt:	return ImGuiKey_LeftAlt;
			case Key::KpLeftGUI:	return ImGuiKey_LeftSuper;
			case Key::KpRightCtrl:	return ImGuiKey_RightCtrl;
			case Key::KpRightShift: return ImGuiKey_RightShift;
			case Key::KpRightAlt:	return ImGuiKey_RightAlt;
			case Key::KpRightGUI:	return ImGuiKey_RightSuper;
			case Key::Application:	return ImGuiKey_Menu;
			case Key::Zero:			return ImGuiKey_0;
			case Key::One:			return ImGuiKey_1;
			case Key::Two:			return ImGuiKey_2;
			case Key::Three:		return ImGuiKey_3;
			case Key::Four:			return ImGuiKey_4;
			case Key::Five:			return ImGuiKey_5;
			case Key::Six:			return ImGuiKey_6;
			case Key::Seven:		return ImGuiKey_7;
			case Key::Eight:		return ImGuiKey_8;
			case Key::Nine:			return ImGuiKey_9;
			case Key::A:			return ImGuiKey_A;
			case Key::B:			return ImGuiKey_B;
			case Key::C:			return ImGuiKey_C;
			case Key::D:			return ImGuiKey_D;
			case Key::E:			return ImGuiKey_E;
			case Key::F:			return ImGuiKey_F;
			case Key::G:			return ImGuiKey_G;
			case Key::H:			return ImGuiKey_H;
			case Key::I:			return ImGuiKey_I;
			case Key::J:			return ImGuiKey_J;
			case Key::K:			return ImGuiKey_K;
			case Key::L:			return ImGuiKey_L;
			case Key::M:			return ImGuiKey_M;
			case Key::N:			return ImGuiKey_N;
			case Key::O:			return ImGuiKey_O;
			case Key::P:			return ImGuiKey_P;
			case Key::Q:			return ImGuiKey_Q;
			case Key::R:			return ImGuiKey_R;
			case Key::S:			return ImGuiKey_S;
			case Key::T:			return ImGuiKey_T;
			case Key::U:			return ImGuiKey_U;
			case Key::V:			return ImGuiKey_V;
			case Key::W:			return ImGuiKey_W;
			case Key::X:			return ImGuiKey_X;
			case Key::Y:			return ImGuiKey_Y;
			case Key::Z:			return ImGuiKey_Z;
			case Key::F1:			return ImGuiKey_F1;
			case Key::F2:			return ImGuiKey_F2;
			case Key::F3:			return ImGuiKey_F3;
			case Key::F4:			return ImGuiKey_F4;
			case Key::F5:			return ImGuiKey_F5;
			case Key::F6:			return ImGuiKey_F6;
			case Key::F7:			return ImGuiKey_F7;
			case Key::F8:			return ImGuiKey_F8;
			case Key::F9:			return ImGuiKey_F9;
			case Key::F10:			return ImGuiKey_F10;
			case Key::F11:			return ImGuiKey_F11;
			case Key::F12:			return ImGuiKey_F12;
			case Key::F13:			return ImGuiKey_F13;
			case Key::F14:			return ImGuiKey_F14;
			case Key::F15:			return ImGuiKey_F15;
			case Key::F16:			return ImGuiKey_F16;
			case Key::F17:			return ImGuiKey_F17;
			case Key::F18:			return ImGuiKey_F18;
			case Key::F19:			return ImGuiKey_F19;
			case Key::F20:			return ImGuiKey_F20;
			case Key::F21:			return ImGuiKey_F21;
			case Key::F22:			return ImGuiKey_F22;
			case Key::F23:			return ImGuiKey_F23;
			case Key::F24:			return ImGuiKey_F24;
			case Key::AcBack:		return ImGuiKey_AppBack;
			case Key::AcForward:	return ImGuiKey_AppForward;

			default:				return ImGuiKey_None;
		}

	}

	KeyCode convertSDLKeyToFazonKey(SDL_KeyboardEvent sdlKey) {

		switch (sdlKey.key) {
			case SDLK_TAB:			return Key::Tab;
			case SDLK_LEFT:			return Key::Left;
			case SDLK_RIGHT:		return Key::Right;
			case SDLK_UP:			return Key::Up;
			case SDLK_DOWN:			return Key::Down;
			case SDLK_PAGEUP:		return Key::PageUp;
			case SDLK_PAGEDOWN:		return Key::PageDown;
			case SDLK_HOME:			return Key::Home;
			case SDLK_END:			return Key::End;
			case SDLK_INSERT:		return Key::Insert;
			case SDLK_DELETE:		return Key::Delete;
			case SDLK_BACKSPACE:	return Key::Backspace;
			case SDLK_SPACE:		return Key::Space;
			case SDLK_RETURN:		return Key::Return;
			case SDLK_ESCAPE:		return Key::Escape;
			case SDLK_APOSTROPHE:	return Key::Apostrophe;
			case SDLK_COMMA:		return Key::Comma;
			case SDLK_MINUS:		return Key::Minus;
			case SDLK_PERIOD:		return Key::Period;
			case SDLK_SLASH:		return Key::Slash;
			case SDLK_SEMICOLON:	return Key::Semicolon;
			case SDLK_EQUALS:		return Key::Equals;
			case SDLK_LEFTBRACKET:	return Key::LeftBracket;
			case SDLK_BACKSLASH:	return Key::Backslash;
			case SDLK_RIGHTBRACKET: return Key::RightBracket;
			case SDLK_GRAVE:		return Key::Grave;
			case SDLK_CAPSLOCK:		return Key::CapsLock;
			case SDLK_SCROLLLOCK:	return Key::ScrollLock;
			case SDLK_NUMLOCKCLEAR: return Key::NumLock;
			case SDLK_PRINTSCREEN:	return Key::PrintScreen;
			case SDLK_PAUSE:		return Key::Pause;
			case SDLK_LCTRL:		return Key::KpLeftCtrl;
			case SDLK_LSHIFT:		return Key::KpLeftShift;
			case SDLK_LALT:			return Key::KpLeftAlt;
			case SDLK_LGUI:			return Key::KpLeftGUI;
			case SDLK_RCTRL:		return Key::KpRightCtrl;
			case SDLK_RSHIFT:		return Key::KpRightShift;
			case SDLK_RALT:			return Key::KpRightAlt;
			case SDLK_RGUI:			return Key::KpRightGUI;
			case SDLK_APPLICATION:	return Key::Application;
			case SDLK_0:			return Key::Zero;
			case SDLK_1:			return Key::One;
			case SDLK_2:			return Key::Two;
			case SDLK_3:			return Key::Three;
			case SDLK_4:			return Key::Four;
			case SDLK_5:			return Key::Five;
			case SDLK_6:			return Key::Six;
			case SDLK_7:			return Key::Seven;
			case SDLK_8:			return Key::Eight;
			case SDLK_9:			return Key::Nine;
			case SDLK_A:			return Key::A;
			case SDLK_B:			return Key::B;
			case SDLK_C:			return Key::C;
			case SDLK_D:			return Key::D;
			case SDLK_E:			return Key::E;
			case SDLK_F:			return Key::F;
			case SDLK_G:			return Key::G;
			case SDLK_H:			return Key::H;
			case SDLK_I:			return Key::I;
			case SDLK_J:			return Key::J;
			case SDLK_K:			return Key::K;
			case SDLK_L:			return Key::L;
			case SDLK_M:			return Key::M;
			case SDLK_N:			return Key::N;
			case SDLK_O:			return Key::O;
			case SDLK_P:			return Key::P;
			case SDLK_Q:			return Key::Q;
			case SDLK_R:			return Key::R;
			case SDLK_S:			return Key::S;
			case SDLK_T:			return Key::T;
			case SDLK_U:			return Key::U;
			case SDLK_V:			return Key::V;
			case SDLK_W:			return Key::W;
			case SDLK_X:			return Key::X;
			case SDLK_Y:			return Key::Y;
			case SDLK_Z:			return Key::Z;
			case SDLK_F1:			return Key::F1;
			case SDLK_F2:			return Key::F2;
			case SDLK_F3:			return Key::F3;
			case SDLK_F4:			return Key::F4;
			case SDLK_F5:			return Key::F5;
			case SDLK_F6:			return Key::F6;
			case SDLK_F7:			return Key::F7;
			case SDLK_F8:			return Key::F8;
			case SDLK_F9:			return Key::F9;
			case SDLK_F10:			return Key::F10;
			case SDLK_F11:			return Key::F11;
			case SDLK_F12:			return Key::F12;
			case SDLK_F13:			return Key::F13;
			case SDLK_F14:			return Key::F14;
			case SDLK_F15:			return Key::F15;
			case SDLK_F16:			return Key::F16;
			case SDLK_F17:			return Key::F17;
			case SDLK_F18:			return Key::F18;
			case SDLK_F19:			return Key::F19;
			case SDLK_F20:			return Key::F20;
			case SDLK_F21:			return Key::F21;
			case SDLK_F22:			return Key::F22;
			case SDLK_F23:			return Key::F23;
			case SDLK_F24:			return Key::F24;
			case SDLK_AC_BACK:		return Key::AcBack;
			case SDLK_AC_FORWARD:	return Key::AcForward;

			default:				return Key::Unknown;
		}
	}

}