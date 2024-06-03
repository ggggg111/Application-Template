#pragma once

#include "YuHuiVEngine/Layers/Layer.h"

namespace Yuhui
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void Begin();
		void End();
	};
}