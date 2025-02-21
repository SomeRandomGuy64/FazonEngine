#include "Shader.h"
#include "Fazon/fzpch.h"
#include "Renderer.h"

#ifdef FZ_PLATFORM_WINDOWS
	#include "Fazon/Platform/OpenGL/OpenGLShader.h"
#elif FZ_PLATFORM_LINUX
	#include "Fazon/Platform/OpenGL/OpenGLShader.h"
#endif

#include <fstream>
#include <sstream>

namespace Fazon {

	std::unique_ptr<Shader> Shader::create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) {

		switch (Renderer::getRendererAPI()) {
		case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
#ifdef FZ_PLATFORM_WINDOWS
		case RendererAPI::OpenGL:	return std::make_unique<OpenGLShader>( name, vertexPath, fragmentPath );
#elif FZ_PLATFORM_LINUX
		case RendererAPI::OpenGL:	return std::make_unique<OpenGLShader>( name, vertexPath, fragmentPath );
#endif
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}