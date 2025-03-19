#pragma once

#include "Fazon/Renderer/Buffer.h"
#include <glm/vec3.hpp>

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

		virtual const BufferLayout& getLayout() const override { return m_layout; }
		virtual void setLayout(const BufferLayout& layout) override { m_layout = layout; }

		virtual uint32_t getSize() const override { return m_size; }
		virtual std::vector<float>& getVertices() const override { return m_vertices; }

	private:

		uint32_t m_rendererID;
		std::vector<float>& m_vertices;
		uint32_t m_size;
		BufferLayout m_layout;

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

	// ------------------------------------------------------------------------
	// Shader Storage Buffer --------------------------------------------------
	// ------------------------------------------------------------------------

	class OpenGLShaderStorageBuffer : public ShaderStorageBuffer {

	public:
		OpenGLShaderStorageBuffer(uint32_t size);
		virtual ~OpenGLShaderStorageBuffer() override;

		virtual void bind() const override;
		virtual void unbind() const override;
		virtual void read(glm::vec3 workGroupSize, const std::function<void(uint32_t*)>& func) const override;
		virtual void read(uint32_t numGroupX, uint32_t numGroupY, uint32_t numGroupZ, const std::function<void(uint32_t*)>& func) const override;

	private:

		uint32_t m_rendererID;
		uint32_t m_size;

	};

}
