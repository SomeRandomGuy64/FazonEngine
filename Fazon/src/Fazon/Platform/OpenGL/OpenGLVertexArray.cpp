#include "OpenGLVertexArray.h"
#include "Fazon/fzpch.h"

#include <glad/glad.h>

namespace Fazon {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_rendererID);
		glBindVertexArray(m_rendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_rendererID);
	}

	void OpenGLVertexArray::bind() const {
		glBindVertexArray(m_rendererID);
	}

	void OpenGLVertexArray::unbind() const {
		glBindVertexArray(0);
	}

	// create setVertexBuffer and setElementBuffer functions too
	void OpenGLVertexArray::setBuffers(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<ElementBuffer> elementBuffer) {

		auto glVertexBuffer{ std::dynamic_pointer_cast<OpenGLVertexBuffer>(vertexBuffer) };
		auto glElementBuffer{ std::dynamic_pointer_cast<OpenGLElementBuffer>(elementBuffer) };

		FZ_CORE_ASSERT(glVertexBuffer, "OpenGLVertexArray::setBuffers() vertexBuffer is not of type OpenGLVertexBuffer!");
		FZ_CORE_ASSERT(glElementBuffer, "OpenGLVertexArray::setBuffers() elementBuffer is not of type OpenGLElementBuffer!");

		m_vertexBuffer = glVertexBuffer;
		m_elementBuffer = glElementBuffer;

		enableAttribArrays();

	}

	void OpenGLVertexArray::enableAttribArrays() {

		for (uint32_t i{ 0 }; i < 2; ++i) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, 3, GL_FLOAT, GL_FALSE, sizeof(m_vertexBuffer->getVertices().data()) * 3, (void*)(i * 3 * sizeof(float)));
		}

	}

}
