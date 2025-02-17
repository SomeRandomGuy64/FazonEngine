#pragma once

#include "Fazon/fzpch.h"
#include "Fazon/Window.h"

#include "Fazon/Renderer/RenderContext.h"

#include <SDL3/SDL.h>

namespace Fazon {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline const char* getTitle() const override { return m_data.title.c_str(); }
		inline uint32_t getWidth() const override { return m_data.width; }
		inline uint32_t getHeight() const override { return m_data.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline virtual void* getNativeWindow() const override { return m_window; }

	private:
		void m_init(const WindowProps& props);
		void m_shutdown();

		void m_resizeWindowEvent() override;
		void m_closeWindowEvent() override;
		void m_windowMovedEvent() override;
		void m_windowFocusEvent() override;
		void m_windowLostFocusEvent() override;
		void m_keyPressEvent() override;
		void m_keyTypeEvent() override;
		void m_mouseButtonPressEvent() override;
		void m_mouseScrollEvent() override;
		void m_mouseMoveEvent() override;
		void m_printError(const char* error) override;

	private:

		SDL_Window* m_window;
		RenderContext* m_context;
		
		struct WindowData {

			std::string title;
			int32_t width;
			int32_t height;
			bool vSync;

			EventCallbackFn EventCallback;

		};

		WindowData m_data{};
		SDL_Event m_sdlEvent;

	};

}