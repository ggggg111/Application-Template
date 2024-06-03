#pragma once

#include "YuHuiVEngine/Modules/Module.h"

namespace Yuhui
{
	class Renderer : public Module
	{
	public:
		Renderer();
		~Renderer();

		void Start() override;
		void Update() override;
		void CleanUp() override;
	};
}