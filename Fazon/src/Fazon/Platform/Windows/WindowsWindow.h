#pragma once

#include "Fazon/fzpch.h"
#include "Fazon/Window.h"

#include <SDL3/SDL_video.h>

namespace Fazon {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline uint32_t getWidth() const override { return m_data.width; }
		inline uint32_t getHeight() const override { return m_data.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

	private:
		SDL_Window* m_window;
		
		struct WindowData {

			std::string title;
			uint32_t width;
			uint32_t height;
			bool vSync;
			SDL_GLContext context;

			EventCallbackFn EventCallback;

		};

		WindowData m_data{};

	};

}