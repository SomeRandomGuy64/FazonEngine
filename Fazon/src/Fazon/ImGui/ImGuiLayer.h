#pragma once

#include "Fazon/Layer.h"

namespace Fazon {

	class ImGuiLayer : public Layer {
		
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& event) override;

	private:

	};

}