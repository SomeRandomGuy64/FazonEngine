#pragma once
#include "Fazon/Renderer/Shader.h"

namespace Fazon {

	class OpenGLShader : public Shader {

	public:
		OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
		virtual ~OpenGLShader() override;

		std::string_view getName() { return m_name; }

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void setBool(bool value) const override;
		virtual void setInt(int value) const  override;
		virtual void setInt2(glm::vec2 value) const override;
		virtual void setInt3(glm::vec3 value) const override;
		virtual void setInt4(glm::vec4 value) const override;

		virtual void setFloat(float value) const override;
		virtual void setFloat2(glm::vec2 value) const override;
		virtual void setFloat3(glm::vec3 value) const override;
		virtual void setFloat4(glm::vec4 value) const override;

		virtual void setMat2(glm::mat2 value) const override;
		virtual void setMat3(glm::mat3 value) const override;
		virtual void setMat4(glm::mat4 value) const override;


	private:

		std::string m_name;
		uint32_t m_rendererID;

	};

}
