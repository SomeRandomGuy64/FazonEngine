#include "OpenGLShader.h"
#include "Fazon/fzpch.h"

#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace Fazon {

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
		: m_name{ name }
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

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_rendererID);
	}

	void OpenGLShader::bind() const {
		glUseProgram(m_rendererID);
	}

	void OpenGLShader::unbind() const {
		glUseProgram(0);
	}

	void OpenGLShader::setBool(bool value) const {
		glUniform1i(glGetUniformLocation(m_rendererID, m_name.c_str()), static_cast<int>(value));
	}

	void OpenGLShader::setInt(int value) const {
		glUniform1i(glGetUniformLocation(m_rendererID, m_name.c_str()), value);
	}

	void OpenGLShader::setInt2(glm::vec2 value) const {
		glUniform2i(glGetUniformLocation(m_rendererID, m_name.c_str()), static_cast<GLint>(value.x), static_cast<GLint>(value.y));
	}

	void OpenGLShader::setInt3(glm::vec3 value) const {
		glUniform3i(glGetUniformLocation(m_rendererID, m_name.c_str()), static_cast<GLint>(value.x), static_cast<GLint>(value.y), static_cast<GLint>(value.z));
	}

	void OpenGLShader::setInt4(glm::vec4 value) const {
		glUniform4i(glGetUniformLocation(m_rendererID, m_name.c_str()), static_cast<GLint>(value.x), static_cast<GLint>(value.y), static_cast<GLint>(value.z), static_cast<GLint>(value.w));
	}

	void OpenGLShader::setFloat(float value) const {
		glUniform1f(glGetUniformLocation(m_rendererID, m_name.c_str()), value);
	}

	void OpenGLShader::setFloat2(glm::vec2 value) const {
		glUniform2f(glGetUniformLocation(m_rendererID, m_name.c_str()), value.x, value.y);
	}

	void OpenGLShader::setFloat3(glm::vec3 value) const {
		glUniform3f(glGetUniformLocation(m_rendererID, m_name.c_str()), value.x, value.y, value.z);
	}

	void OpenGLShader::setFloat4(glm::vec4 value) const {
		glUniform4f(glGetUniformLocation(m_rendererID, m_name.c_str()), value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::setMat2(glm::mat2 value) const {
		glUniformMatrix2fv(glGetUniformLocation(m_rendererID, m_name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShader::setMat3(glm::mat3 value) const {
		glUniformMatrix3fv(glGetUniformLocation(m_rendererID, m_name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShader::setMat4(glm::mat4 value) const {
		glUniformMatrix4fv(glGetUniformLocation(m_rendererID, m_name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

}