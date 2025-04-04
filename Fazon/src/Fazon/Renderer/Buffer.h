#pragma once

#include "Shader.h"
#include <glm/vec3.hpp>

namespace Fazon {

	static uint32_t shaderDataTypeSize(Shader::DataType type) {

		switch (type) {
			case Fazon::Shader::DataType::None:		return 0;
			case Fazon::Shader::DataType::Float:	return 4;
			case Fazon::Shader::DataType::Float2:	return 4 * 2;
			case Fazon::Shader::DataType::Float3:	return 4 * 3;
			case Fazon::Shader::DataType::Float4:	return 4 * 4;
			case Fazon::Shader::DataType::Int:		return 4;
			case Fazon::Shader::DataType::Int2:		return 4 * 2;
			case Fazon::Shader::DataType::Int3:		return 4 * 3;
			case Fazon::Shader::DataType::Int4:		return 4 * 4;
			case Fazon::Shader::DataType::Bool:		return 4;
			case Fazon::Shader::DataType::Mat2:		return 4 * 2 * 2;
			case Fazon::Shader::DataType::Mat3:		return 4 * 3 * 3;
			case Fazon::Shader::DataType::Mat4:		return 4 * 4 * 4;
			default:								break;
		}

		FZ_CORE_ASSERT(false, "Unknown Shader Data Type!");
		return 0;

	}

	struct BufferElement {

		std::string name{};
		Shader::DataType type{};
		uint32_t size{};
		uint32_t offset{};
		bool normalised{ false };

		BufferElement(Shader::DataType type, const std::string& name, bool normalised = false)
			: type{ type }
			, name{ name }
			, size{ shaderDataTypeSize(type) }
			, normalised{ normalised }
		{
		}

		BufferElement() {}

		uint32_t getComponentCount() const {

			switch (type) {
				case Fazon::Shader::DataType::None:		return 0;
				case Fazon::Shader::DataType::Float:	return 1;
				case Fazon::Shader::DataType::Float2:	return 2;
				case Fazon::Shader::DataType::Float3:	return 3;
				case Fazon::Shader::DataType::Float4:	return 4;
				case Fazon::Shader::DataType::Int:		return 1;
				case Fazon::Shader::DataType::Int2:		return 2;
				case Fazon::Shader::DataType::Int3:		return 3;
				case Fazon::Shader::DataType::Int4:		return 4;
				case Fazon::Shader::DataType::Bool:		return 1;
				case Fazon::Shader::DataType::Mat2:		return 2 * 2;
				case Fazon::Shader::DataType::Mat3:		return 3 * 3;
				case Fazon::Shader::DataType::Mat4:		return 4 * 4;
				default:								break;
			}

			FZ_CORE_ASSERT(false, "Unknown Shader Data Type!");
			return 0;

		}

	};

	class BufferLayout {

	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements)
			: m_elements{ elements }
		{
			calculateOffsetsAndStride();
		}

		BufferLayout() {}

		inline const std::vector<BufferElement>& getElements() const { return m_elements; }

		std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }

		uint32_t getStride() const { return m_stride; }

	private:

		void calculateOffsetsAndStride() {

			uint32_t offset{ 0 };
			m_stride = 0;
			for (auto& element : m_elements) {
				element.offset = offset;
				offset += element.size;
				m_stride += element.size;
			}

		}

	private:

		std::vector<BufferElement> m_elements;
		uint32_t m_stride{ 0 };

	};

	class VertexBuffer {

	public:
		virtual ~VertexBuffer() = default;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& getLayout() const = 0;

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
