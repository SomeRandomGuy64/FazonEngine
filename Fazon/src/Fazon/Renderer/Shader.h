#pragma once
#include <glm/glm.hpp>

#include <string>

namespace Fazon {

	class Shader {

	public:
		//Shader(const char* vertexPath, const char* fragmentPath);
		virtual ~Shader() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setBool(bool value) const = 0;
		virtual void setInt(int value) const = 0;
		virtual void setInt2(glm::vec2 value) const = 0;
		virtual void setInt3(glm::vec3 value) const = 0;
		virtual void setInt4(glm::vec4 value) const = 0;

		virtual void setFloat(float value) const = 0;
		virtual void setFloat2(glm::vec2 value) const = 0;
		virtual void setFloat3(glm::vec3 value) const = 0;
		virtual void setFloat4(glm::vec4 value) const = 0;

		virtual void setMat2(glm::mat2 value) const = 0;
		virtual void setMat3(glm::mat3 value) const = 0;
		virtual void setMat4(glm::mat4 value) const = 0;

		static Shader* create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);

	};

}
