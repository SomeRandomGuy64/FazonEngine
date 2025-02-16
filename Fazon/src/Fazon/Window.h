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
		
		virtual const char* getTitle() const = 0;
		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		// Window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProps& props = WindowProps());

	protected:
		virtual void m_resizeWindowEvent() = 0;
		virtual void m_closeWindowEvent() = 0;
		virtual void m_windowMovedEvent() = 0;
		virtual void m_windowFocusEvent() = 0;
		virtual void m_windowLostFocusEvent() = 0;
		virtual void m_keyPressEvent() = 0;
		virtual void m_keyTypeEvent() = 0;
		virtual void m_mouseButtonPressEvent() = 0;
		virtual void m_mouseScrollEvent() = 0;
		virtual void m_mouseMoveEvent() = 0;
		virtual void m_printError(const char* error) = 0;

	};

}