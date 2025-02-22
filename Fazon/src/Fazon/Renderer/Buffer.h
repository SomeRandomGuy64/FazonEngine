#pragma once

namespace Fazon {

	struct VertexBuffer {

		virtual ~VertexBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getSize() const = 0;
		virtual std::vector<float>& getVertices() const = 0;

		static std::shared_ptr<VertexBuffer> create(std::vector<float>&& vertices, uint32_t size);

	};

	// Also known as the index buffer
	struct ElementBuffer {

		virtual ~ElementBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getCount() const = 0;	
		virtual std::vector<uint32_t>& getElements() const = 0;

		static std::shared_ptr<ElementBuffer> create(std::vector<uint32_t>&& elements, uint32_t size);

	};

}
