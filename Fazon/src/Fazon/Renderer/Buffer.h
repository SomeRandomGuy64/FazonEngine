#pragma once

#include <glm/vec3.hpp>

namespace Fazon {

	class VertexBuffer {

	public:
		virtual ~VertexBuffer() = default;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getSize() const = 0;
		virtual std::vector<float>& getVertices() const = 0;

		static std::shared_ptr<VertexBuffer> create(std::vector<float>&& vertices, uint32_t size);

	};

	// Also known as the index buffer
	class ElementBuffer {

	public:
		virtual ~ElementBuffer() = default;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getCount() const = 0;	
		virtual std::vector<uint32_t>& getElements() const = 0;

		static std::shared_ptr<ElementBuffer> create(std::vector<uint32_t>&& elements, uint32_t size);

	};

	class ShaderStorageBuffer {

	public:
		virtual ~ShaderStorageBuffer() = default;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		virtual void read(glm::vec3 workGroupSize, const std::function<void(uint32_t*)>& func) const = 0;
		virtual void read(uint32_t numGroupX, uint32_t numGroupY, uint32_t numGroupZ, const std::function<void(uint32_t*)>& func) const = 0;

		static std::shared_ptr<ShaderStorageBuffer> create(uint32_t size);
	};

}
