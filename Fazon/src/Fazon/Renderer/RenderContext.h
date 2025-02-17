#pragma once

namespace Fazon {

	class RenderContext {
		
	public:

		virtual void init() = 0;
		virtual	void swapBuffers() = 0;
		virtual void destroyContext() = 0;

	};

}
