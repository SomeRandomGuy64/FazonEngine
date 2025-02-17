#include "OpenGLContext.h"

#include "Fazon/fzpch.h"

#include <glad/glad.h>

namespace Fazon {

	OpenGLContext::OpenGLContext(SDL_Window* windowHandle)
		: m_windowHandle{ windowHandle }
		, m_glContext{ SDL_GL_CreateContext(windowHandle) }
	{
		FZ_CORE_ASSERT(m_windowHandle, "Window handle is null!");
		FZ_CORE_ASSERT(m_glContext, "GL Context is null!");
	}

	void OpenGLContext::init() {

		SDL_GL_MakeCurrent(m_windowHandle, m_glContext);
		int status{ gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress) };
		FZ_CORE_ASSERT(status, "Failed to initialise GLAD!");

		FZ_CORE_INFO("  Vendor:\t{0}", (char*)glGetString(GL_VENDOR));
		FZ_CORE_INFO("  Renderer:\t{0}", (char*)glGetString(GL_RENDERER));
		FZ_CORE_INFO("  Version:\t{0}", (char*)glGetString(GL_VERSION));

	}

	void OpenGLContext::swapBuffers() {

		SDL_GL_SwapWindow(m_windowHandle);
		//glClear(GL_COLOR_BUFFER_BIT);

	}

	void OpenGLContext::destroyContext() {
		SDL_GL_DestroyContext(m_glContext);
	}

}