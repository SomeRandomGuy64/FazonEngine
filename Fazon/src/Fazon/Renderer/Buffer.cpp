#include "Buffer.h"
#include "Fazon/fzpch.h"

#ifdef FZ_PLATFORM_WINDOWS
#include "Fazon/Platform/OpenGL/OpenGLBuffer.h"
#elif FZ_PLATFORM_LINUX
#include "Fazon/Platform/OpenGL/OpenGLBuffer.h"
#endif

#include "Renderer.h"

namespace Fazon {

	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
#ifdef FZ_PLATFORM_WINDOWS
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer{ vertices, size };
#elif FZ_PLATFORM_LINUX
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer{ vertices, size };
#endif
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

	ElementBuffer* ElementBuffer::create(uint32_t* elements, uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
#ifdef FZ_PLATFORM_WINDOWS
			case RendererAPI::OpenGL:	return new OpenGLElementBuffer{ elements, size };
#elif FZ_PLATFORM_LINUX
			case RendererAPI::OpenGL:	return new OpenGLElementBuffer{ elements, size };
#endif
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}