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

}