#include "KeyCodes.h"

char Fazon::convertFazonKeyToASCII(KeyCode key) {
	switch (key) {
	case Key::A:	return 'A';		break;
	case Key::B:	return 'B';		break;
	case Key::C:	return 'C';		break;
	case Key::D:	return 'D';		break;
	case Key::E:	return 'E';		break;
	case Key::F:	return 'F';		break;
	case Key::G:	return 'G';		break;
	case Key::H:	return 'H';		break;
	case Key::I:	return 'I';		break;
	case Key::J:	return 'J';		break;
	case Key::K:	return 'K';		break;
	case Key::L:	return 'L';		break;
	case Key::M:	return 'M';		break;
	case Key::N:	return 'N';		break;
	case Key::O:	return 'O';		break;
	case Key::P:	return 'P';		break;
	case Key::Q:	return 'Q';		break;
	case Key::R:	return 'R';		break;
	case Key::S:	return 'S';		break;
	case Key::T:	return 'T';		break;
	case Key::U:	return 'U';		break;
	case Key::V:	return 'V';		break;
	case Key::W:	return 'W';		break;
	case Key::X:	return 'X';		break;
	case Key::Y:	return 'Y';		break;
	case Key::Z:	return 'Z';		break;

	default:		return ' ';		break;
	}
}