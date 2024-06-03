#pragma once

#include <Windows.h>
#include <string>
#include <list>
#include "YuHuiVEngine/Core/Base.h"
#include "YuHuiVEngine/Core/LayerStack.h"
#include "YuHuiVEngine/Modules/Module.h"
#include "YuHuiVEngine/Modules/Window.h"
#include "YuHuiVEngine/Modules/Renderer.h"
#include "YuHuiVEngine/Layers/ImGuiLayer.h"

namespace Yuhui
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void Start();
		void Update();
		void CleanUp();

		Window &GetWindow() const { return *m_Window; }
		Renderer &GetRenderer() const { return *m_Renderer; }

	private:
		void AddModule(Module *module);
		void AddLayer(Layer *layer);
		void AddOverlay(Layer *layer);

	private:
		std::list<Module *> m_Modules;

		LayerStack m_LayerStack;
		Scope<ImGuiLayer> m_ImGuiLayer;

		Scope<Window> m_Window;
		Scope<Renderer> m_Renderer;

		bool m_Running = true;
	};
}

extern Yuhui::Application *App;