#pragma once

#include "Fazon/Renderer/VertexArray.h"
#include "OpenGLBuffer.h"

namespace Fazon {

	class OpenGLVertexArray : public VertexArray {

	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray() override;

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void setBuffers(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<ElementBuffer> elementBuffer) override;
		virtual void addVertexBuffer(std::shared_ptr<VertexBuffer> buffer) override;
		virtual void addElementBuffer(std::shared_ptr<ElementBuffer> buffer) override;

	private:

		uint32_t m_rendererID;
		std::shared_ptr<OpenGLVertexBuffer> m_vertexBuffer;
		std::shared_ptr<OpenGLElementBuffer> m_elementBuffer;

	};

}