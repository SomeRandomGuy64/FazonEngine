#include "OpenGLVertexArray.h"
#include "OpenGLShader.h"
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

	void OpenGLVertexArray::setBuffers(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<ElementBuffer> elementBuffer) {

		glBindVertexArray(m_rendererID);

		auto glVertexBuffer{ std::dynamic_pointer_cast<OpenGLVertexBuffer>(vertexBuffer) };
		auto glElementBuffer{ std::dynamic_pointer_cast<OpenGLElementBuffer>(elementBuffer) };

		FZ_CORE_ASSERT(glVertexBuffer, "OpenGLVertexArray::setBuffers() vertexBuffer is not of type OpenGLVertexBuffer!");
		FZ_CORE_ASSERT(glElementBuffer, "OpenGLVertexArray::setBuffers() elementBuffer is not of type OpenGLElementBuffer!");

		m_vertexBuffer = glVertexBuffer;
		m_elementBuffer = glElementBuffer;

		const auto& layout{ m_vertexBuffer->getLayout() };
		for (uint32_t i{ 0 }; i < layout.getElements().size(); ++i) {
			BufferElement element{ layout.getElements().at(i) };
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i,
				element.getComponentCount(),
				OpenGLShader::shaderDataTypeToOpenGLBaseType(element.type),
				element.normalised ? GL_TRUE : GL_FALSE,
				layout.getStride(),
#pragma warning(push)
#pragma warning(disable : 4312)	// disable integer to pointer conversion warning
				(const void*)(element.offset)
#pragma warning(pop)
			);
		}

	}

	void OpenGLVertexArray::addVertexBuffer(std::shared_ptr<VertexBuffer> buffer) {

		auto glVertexBuffer{ std::dynamic_pointer_cast<OpenGLVertexBuffer>(buffer) };
		FZ_CORE_ASSERT(glVertexBuffer, "OpenGLVertexArray::setBuffers() vertexBuffer is not of type OpenGLVertexBuffer!");
		m_vertexBuffer = glVertexBuffer;

	}

	void OpenGLVertexArray::addElementBuffer(std::shared_ptr<ElementBuffer> buffer) {

		auto glElementBuffer{ std::dynamic_pointer_cast<OpenGLElementBuffer>(buffer) };
		FZ_CORE_ASSERT(glElementBuffer, "OpenGLVertexArray::setBuffers() elementBuffer is not of type OpenGLElementBuffer!");
		m_elementBuffer = glElementBuffer;

	}

}
