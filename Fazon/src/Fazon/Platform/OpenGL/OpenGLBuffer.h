#pragma once

#include "Fazon/Renderer/Buffer.h"

namespace Fazon {

	// ------------------------------------------------------------------------
	// Vertex Buffer ----------------------------------------------------------
	// ------------------------------------------------------------------------

	class OpenGLVertexBuffer : public VertexBuffer {

	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;

	private:

		uint32_t m_rendererID;

	};

	// ------------------------------------------------------------------------
	// Element Buffer ---------------------------------------------------------
	// ------------------------------------------------------------------------

	class OpenGLElementBuffer : public ElementBuffer {

	public:
		OpenGLElementBuffer(uint32_t* elements, uint32_t size);
		virtual ~OpenGLElementBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual uint32_t getCount() const override { return m_count; }

	private:

		uint32_t m_rendererID;
		uint32_t m_count;

	};

}
