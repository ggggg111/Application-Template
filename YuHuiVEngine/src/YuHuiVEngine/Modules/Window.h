#pragma once

#include "YuHuiVEngine/Modules/Module.h"

namespace Yuhui
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string &title = "YuHuiVEngine",
					uint32_t width = 1600,
					uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window : public Module
	{
	public:
		Window();
		~Window();

		void Start() override;
	};
}