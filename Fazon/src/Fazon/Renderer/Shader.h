#pragma once

#include <string>

namespace Fazon {

	class Shader {

	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void bind() const;
		void unbind() const;

	private:

		uint32_t m_rendererID{};

	};

}
