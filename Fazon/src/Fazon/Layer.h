#pragma once

#include "Fazon/Core.h"
#include "Fazon/Events/Event.h"

namespace Fazon {

	class Layer {

	public:
		Layer(const std::string_view debugName = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event&) {}

		inline const std::string_view getName() const { return m_debugName; }

	protected:
		std::string m_debugName{};

	};

}