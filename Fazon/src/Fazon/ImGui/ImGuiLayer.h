#pragma once

#include "Fazon/Layer.h"

#include "Fazon/Events/MouseEvent.h"
#include "Fazon/Events/KeyEvent.h"
#include "Fazon/Events/WindowEvent.h"

namespace Fazon {

	class ImGuiLayer : public Layer {
		
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& event) override;

	private:
		bool m_onMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool m_onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool m_onMouseMovedEvent(MouseMovedEvent& event);
		bool m_onMouseScrolledEvent(MouseScrolledEvent& event);
		bool m_onKeyPressedEvent(KeyPressedEvent& event);
		//bool m_onKeyTypedEvent(KeyTypedEvent& event);
		bool m_onKeyReleasedEvent(KeyReleasedEvent& event);
		bool m_onWindowResizedEvent(WindowResizedEvent& event);

	};

}