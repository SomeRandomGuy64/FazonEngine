#include "Shader.h"

#include "Fazon/fzpch.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>

namespace Fazon {

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		// 1. retrieve the vertex/fragment source code from file path
		std::string vertexCode{};
		std::string fragmentCode{};
		std::ifstream vShaderFile{};
		std::ifstream fShaderFile{};

		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {

			// open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream{};
			std::stringstream fShaderStream{};

			// read the file's buffer contents into stream
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			// close file handlers
			vShaderFile.close();
			fShaderFile.close();

			// convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();

		}
		catch (std::ifstream::failure e) {
			FZ_CORE_ASSERT(false, "Shader file not successfully read!");
		}

		const char* vShaderCode{ vertexCode.c_str() };
		const char* fShaderCode{ fragmentCode.c_str() };

		// 2. compile shaders
		// vertex shader
		uint32_t vertex{ glCreateShader(GL_VERTEX_SHADER) };
		glShaderSource(vertex, 1, &vShaderCode, nullptr);
		glCompileShader(vertex);

		// print compile errors if any
		int32_t success{};
		char infoLog[512]{};

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
			FZ_CORE_ASSERT(false, "Vertex shader compilation failed: {0}", infoLog);
		}

		// fragment shader
		uint32_t fragment{ glCreateShader(GL_FRAGMENT_SHADER) };
		glShaderSource(fragment, 1, &fShaderCode, nullptr);
		glCompileShader(fragment);

		// print compile errors if any
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
			FZ_CORE_ASSERT(false, "Fragment shader compilation failed: {0}", infoLog);
		}

		// shader program
		m_rendererID = glCreateProgram();
		glAttachShader(m_rendererID, vertex);
		glAttachShader(m_rendererID, fragment);
		glLinkProgram(m_rendererID);

		// print linking errors if any
		glGetProgramiv(m_rendererID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_rendererID, 512, nullptr, infoLog);
			FZ_CORE_ASSERT(false, "Shader program linking failed: {0}", infoLog);
		}
		
		// delete shaders, they're linked to the program and no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);

	}

	Shader::~Shader()
	{
		glDeleteProgram(m_rendererID);
	}

	void Shader::bind() const {
		glUseProgram(m_rendererID);
	}

	void Shader::unbind() const {
		glUseProgram(0);
	}

}