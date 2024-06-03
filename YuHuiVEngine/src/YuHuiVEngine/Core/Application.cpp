#include "yhvpch.h"
#include "YuHuiVEngine/Core/Application.h"

namespace Yuhui
{
	Application::Application()
	{
		m_Window = CreateScope<Window>();
		m_Renderer = CreateScope<Renderer>();

		AddModule(m_Window.get());
		AddModule(m_Renderer.get());
	}

	Application::~Application()
	{}

	void Application::Run()
	{
		Start();

		while(m_Running)
		{
			Update();
		}

		CleanUp();
	}

	void Application::Start()
	{
		for(auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		{
			if((*it)->IsActive())
				(*it)->Start();
		}

		m_ImGuiLayer = CreateScope<ImGuiLayer>();
		AddOverlay(m_ImGuiLayer.get());
	}

	void Application::Update()
	{
		for(auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		{
			if((*it)->IsActive())
				(*it)->PreUpdate();
		}

		for(Layer *layer : m_LayerStack)
		{
			layer->OnUpdate();
		}

		m_ImGuiLayer->Begin();
		{
			for(Layer *layer : m_LayerStack)
				layer->OnImGuiRender();
		}
		m_ImGuiLayer->End();

		for(auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		{
			if((*it)->IsActive())
				(*it)->Update();
		}

		for(auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		{
			if((*it)->IsActive())
				(*it)->PostUpdate();
		}
	}

	void Application::CleanUp()
	{
		for(auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it)
		{
			if((*it)->IsActive())
				(*it)->CleanUp();
		}
	}

	void Application::AddLayer(Layer *layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::AddOverlay(Layer *layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::AddModule(Module *module)
	{
		module->Init();
		m_Modules.push_back(module);
	}
}