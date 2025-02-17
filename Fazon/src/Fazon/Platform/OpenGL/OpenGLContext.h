#pragma once

#include "Fazon/Renderer/RenderContext.h"
#include <SDL3/SDL.h>

namespace Fazon {

	class OpenGLContext : public RenderContext {

	public:
		OpenGLContext(SDL_Window* windowHandle);

		virtual void init() override;
		virtual void swapBuffers() override;
		virtual void destroyContext() override;

	private:

		SDL_Window* m_windowHandle;
		SDL_GLContext m_glContext;

	};

}