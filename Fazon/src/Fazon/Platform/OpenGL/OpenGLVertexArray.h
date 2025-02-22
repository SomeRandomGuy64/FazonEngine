#pragma once

#include "Fazon/Renderer/VertexArray.h"
#include "OpenGLBuffer.h"

namespace Fazon {

	class OpenGLVertexArray : public VertexArray {

	public:
		OpenGLVertexArray(uint32_t size);
		virtual ~OpenGLVertexArray() override;

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void setBuffers(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<ElementBuffer> elementBuffer) override;

	private:

		void enableAttribArrays();

	private:

		uint32_t m_rendererID;
		uint32_t m_size;
		std::shared_ptr<OpenGLVertexBuffer> m_vertexBuffer;
		std::shared_ptr<OpenGLElementBuffer> m_elementBuffer;

	};

}