#pragma once

namespace Fazon {

	enum class RendererAPI {
		None = 0,
		OpenGL = 1,
		Vulkan = 2,
		Metal = 3,
		WebGPU = 4

		// Add more later if necessary
	};

	class Renderer {

	public:

		inline static RendererAPI getRendererAPI() { return s_rendererAPI; }

	private:

		static RendererAPI s_rendererAPI;

	};


}
