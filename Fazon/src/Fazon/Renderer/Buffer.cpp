#include "Buffer.h"
#include "Fazon/fzpch.h"

#ifdef FZ_PLATFORM_WINDOWS
#include "Fazon/Platform/OpenGL/OpenGLBuffer.h"
#elif FZ_PLATFORM_LINUX
#include "Fazon/Platform/OpenGL/OpenGLBuffer.h"
#endif

#include "Renderer.h"

namespace Fazon {

	std::shared_ptr<VertexBuffer> VertexBuffer::create(std::vector<float>&& vertices, uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
#ifdef FZ_PLATFORM_WINDOWS
			case RendererAPI::OpenGL:	return std::make_shared<OpenGLVertexBuffer>(std::move(vertices), size);
#elif FZ_PLATFORM_LINUX
			case RendererAPI::OpenGL:	return std::make_shared<OpenGLVertexBuffer>(std::move(vertices), size);
#endif
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

	std::shared_ptr<ElementBuffer> ElementBuffer::create(std::vector<uint32_t>&& elements, uint32_t size) {
		
		switch (Renderer::getRendererAPI()) {
			case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
#ifdef FZ_PLATFORM_WINDOWS
			case RendererAPI::OpenGL:	return std::make_shared<OpenGLElementBuffer>(std::move(elements), size);
#elif FZ_PLATFORM_LINUX
			case RendererAPI::OpenGL:	return std::make_shared<OpenGLElementBuffer>(std::move(elements), size);
#endif
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}