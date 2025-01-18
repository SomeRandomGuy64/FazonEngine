#pragma once

#include "fzpch.h"

#include "Fazon/Core.h"
#include "Fazon/Events/Event.h"

namespace Fazon {

	struct WindowProps {

		WindowProps(const char* title = "Fazon Engine", uint32_t width = 1280, uint32_t height = 720)
			: m_title{ title }
			, m_width{ width }
			, m_height{ height }
		{
		}

		const char* m_title;
		uint32_t m_width;
		uint32_t m_height;

	};

	// Interface representing a desktop system based Window
	class Window {

	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		// Window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());

	};

}