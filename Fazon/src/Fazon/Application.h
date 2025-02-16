#pragma once

#include "Fazon/Core.h"

#include "Window.h"
#include "Fazon/LayerStack.h"
#include "Events/WindowEvent.h"

#include "Fazon/ImGui/ImGuiLayer.h"

namespace Fazon {

	class Application {

	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline Window& getWindow() { return *m_window; }

		inline static Application& get() { return *s_instance; }

	private:
		bool m_onWindowClosed(WindowCloseEvent& event);

		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_imGuiLayer;
		bool m_running{ true };
		LayerStack m_layerStack;

	private:
		static Application* s_instance;

	};

	// TO BE DEFINED IN CLIENT
	Application* createApplication();

}