#pragma once
#include "Fazon/Renderer/Shader.h"

#include <glad/glad.h>

namespace Fazon {

	class OpenGLShader : public virtual Shader {

	public:
		OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
		OpenGLShader(const std::string& name, const Type shaderType, const std::string& shaderPath);

		virtual ~OpenGLShader() override { glDeleteProgram(m_rendererID); };

		std::string_view getName() const { return m_name; }

		static GLenum shaderDataTypeToOpenGLBaseType(Shader::DataType type);

		virtual void bind() const override { glUseProgram(m_rendererID); }
		virtual void unbind() const override { glUseProgram(0); }

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

		virtual void dispatch(glm::vec3 elements) const override;
		virtual void dispatch(uint32_t elementOne, uint32_t elementTwo, uint32_t elementThree) const override;

	private:

		std::string m_name;
		uint32_t m_rendererID;
		Type m_type{ Type::VertFrag };

	};

}
