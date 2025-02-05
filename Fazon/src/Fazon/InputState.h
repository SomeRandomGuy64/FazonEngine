#pragma once

class InputState {

public:

	static InputState& getInstance() {
		static InputState instance;
		return instance;
	}

	void setShiftHeld(bool held) { m_shiftHeld = held; }
	void setCtrlHeld(bool held) { m_ctrlHeld = held; }
	void setAltHeld(bool held) { m_altHeld = held; }

	bool isShiftHeld() const { return m_shiftHeld; }
	bool isCtrlHeld() const { return m_ctrlHeld; }
	bool isAltHeld() const { return m_altHeld; }

private:

	bool m_shiftHeld{ false };
	bool m_ctrlHeld{ false };
	bool m_altHeld{ false };

	InputState() {}
	~InputState() {}
	InputState(const InputState&) = delete;
	InputState& operator=(const InputState&) = delete;

};
