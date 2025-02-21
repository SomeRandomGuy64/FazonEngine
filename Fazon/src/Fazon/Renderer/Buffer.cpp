#include "Buffer.h"
#include "Fazon/fzpch.h"

#include "Fazon/Platform/OpenGL/OpenGLBuffer.h"

#include "Renderer.h"

namespace Fazon {

	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer{ vertices, size };
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

	ElementBuffer* ElementBuffer::create(uint32_t* elements, uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLElementBuffer{ elements, size };
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}