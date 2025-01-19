#pragma once

#include "Fazon/Core.h"
#include "Fazon/Events/Event.h"

namespace Fazon {

	class Layer {

	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event&) {}

		inline const std::string& getName() const { return m_debugName; }

	protected:
		std::string m_debugName{};

	};

}