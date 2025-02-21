#pragma once

namespace Fazon {

	class VertexBuffer {

	public:

		virtual ~VertexBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static VertexBuffer* create(float* vertices, uint32_t size);

	};

	// Also known as the index buffer
	class ElementBuffer {

	public:

		virtual ~ElementBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getCount() const = 0;

		static ElementBuffer* create(uint32_t* elements, uint32_t size);

	};

}
