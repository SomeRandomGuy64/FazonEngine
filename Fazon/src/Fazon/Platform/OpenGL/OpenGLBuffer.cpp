#include "OpenGLBuffer.h"
#include "Fazon/fzpch.h"

#include <glad/glad.h>

namespace Fazon {

	// ------------------------------------------------------------------------
	// Vertex Buffer ----------------------------------------------------------
	// ------------------------------------------------------------------------

	OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<float>&& vertices, uint32_t size)
		: m_vertices{ vertices }
		, m_size{ size }
	{
		glCreateBuffers(1, &m_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_rendererID);
	}

	void OpenGLVertexBuffer::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
	}

	void OpenGLVertexBuffer::unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// ------------------------------------------------------------------------
	// Element Buffer ---------------------------------------------------------
	// ------------------------------------------------------------------------

	OpenGLElementBuffer::OpenGLElementBuffer(std::vector<uint32_t>&& elements, uint32_t count)
		: m_count{ count }
		, m_elements{ elements }
	{
		glCreateBuffers(1, &m_rendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), elements.data(), GL_STATIC_DRAW);
	}

	OpenGLElementBuffer::~OpenGLElementBuffer()
	{
		glDeleteBuffers(1, &m_rendererID);
	}

	void OpenGLElementBuffer::bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
	}

	void OpenGLElementBuffer::unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	// ------------------------------------------------------------------------
	// Shader Storage Buffer --------------------------------------------------
	// ------------------------------------------------------------------------

	OpenGLShaderStorageBuffer::OpenGLShaderStorageBuffer(uint32_t size)
		: m_size{ size }
	{
		glCreateBuffers(1, &m_rendererID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_rendererID);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size, nullptr, GL_DYNAMIC_READ);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, m_rendererID);
	}

	OpenGLShaderStorageBuffer::~OpenGLShaderStorageBuffer()
	{
		glDeleteBuffers(1, &m_rendererID);
	}

	void OpenGLShaderStorageBuffer::bind() const {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_rendererID);
	}

	void OpenGLShaderStorageBuffer::unbind() const {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	}

	void OpenGLShaderStorageBuffer::read(glm::vec3 workGroupSize, const std::function<void(uint32_t*)>& func) const {

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_rendererID);
		uint32_t* data{ static_cast<uint32_t*>(
			glMapBufferRange(
				GL_SHADER_STORAGE_BUFFER, 0, static_cast<GLsizeiptr>(workGroupSize.x * workGroupSize.y * workGroupSize.z) * sizeof(uint32_t), GL_MAP_READ_BIT)
			) 
		};
		
		if (data) {
			func(data);
			glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
		}
		else {
			FZ_CORE_ERROR("Failed to map buffer!");
		}

	}

	void OpenGLShaderStorageBuffer::read(uint32_t numGroupX, uint32_t numGroupY, uint32_t numGroupZ, const std::function<void(uint32_t*)>& func) const {

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_rendererID);
		uint32_t* data{ static_cast<uint32_t*>(
			glMapBufferRange(
				GL_SHADER_STORAGE_BUFFER, 0, numGroupX * numGroupY * numGroupZ * sizeof(uint32_t), GL_MAP_READ_BIT)
			)
		};

		if (data) {
			func(data);
			glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
		}
		else {
			FZ_CORE_ERROR("Failed to map buffer!");
		}

	}

}