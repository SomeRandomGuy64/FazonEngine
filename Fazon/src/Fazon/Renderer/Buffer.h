#pragma once

namespace Fazon {

	struct VertexBuffer {

		virtual ~VertexBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static std::unique_ptr<VertexBuffer> create(float* vertices, uint32_t size);

	};

	// Also known as the index buffer
	struct ElementBuffer {

		virtual ~ElementBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getCount() const = 0;

		static std::unique_ptr<ElementBuffer> create(uint32_t* elements, uint32_t size);

	};

}
