#pragma once

#include "YuHuiVEngine/Core/Base.h"

namespace Yuhui
{
	class Layer
	{
	public:
		Layer(const std::string &name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}

		const std::string &GetName() const { return m_Name; }

	protected:
		std::string m_Name;
	};

}