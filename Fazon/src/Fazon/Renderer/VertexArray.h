#pragma once

#include "Buffer.h"

namespace Fazon {

	struct VertexArray {

		virtual ~VertexArray() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setBuffers(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<ElementBuffer> elementBuffer) = 0;

		static std::unique_ptr<VertexArray> create();

	};

}
