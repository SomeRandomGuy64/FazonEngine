#include "Shader.h"
#include "Fazon/fzpch.h"
#include "Renderer.h"

#include "Fazon/Platform/OpenGL/OpenGLShader.h"

#include <fstream>
#include <sstream>

namespace Fazon {

	Shader* Shader::create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) {

		switch (Renderer::getRendererAPI()) {
		case RendererAPI::None:		FZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
		case RendererAPI::OpenGL:	return new OpenGLShader{ name, vertexPath, fragmentPath };
		};

		FZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}

}