#include "VertexArray.h"
#include "Fazon/fzpch.h"

#ifdef FZ_PLATFORM_WINDOWS
#include "Fazon/Platform/OpenGL/OpenGLVertexArray.h"
#elif FZ_PLATFORM_LINUX
#include "Fazon/Platform/OpenGL/OpenGLVertexArray.h"
#endif

#include "Renderer.h"

namespace Fazon {

	std::unique_ptr<VertexArray> VertexArray::create(uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
#ifdef FZ_PLATFORM_WINDOWS
			case RendererAPI::OpenGL:	return std::make_unique<OpenGLVertexArray>(size);
#elif FZ_PLATFORM_LINUX
			case RendererAPI::OpenGL:	return std::make_unique<OpenGLVertexArray>(size);
#endif
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}