#pragma once

#include "Fazon/Renderer/Buffer.h"

namespace Fazon {

	// ------------------------------------------------------------------------
	// Vertex Buffer ----------------------------------------------------------
	// ------------------------------------------------------------------------

	class OpenGLVertexBuffer : public VertexBuffer {

	public:
		OpenGLVertexBuffer(std::vector<float>&& vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer() override;

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual uint32_t getSize() const override { return m_size; }
		virtual std::vector<float>& getVertices() const override { return m_vertices; }

	private:

		uint32_t m_rendererID;
		std::vector<float>& m_vertices;
		uint32_t m_size;

	};

	// ------------------------------------------------------------------------
	// Element Buffer ---------------------------------------------------------
	// ------------------------------------------------------------------------

	class OpenGLElementBuffer : public ElementBuffer {

	public:
		OpenGLElementBuffer(std::vector<uint32_t>&& elements, uint32_t size);
		virtual ~OpenGLElementBuffer() override;

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual uint32_t getCount() const override { return m_count; }
		virtual std::vector<uint32_t>& getElements() const override { return m_elements; }

	private:

		uint32_t m_rendererID;
		uint32_t m_count;
		std::vector<uint32_t>& m_elements;

	};

}
