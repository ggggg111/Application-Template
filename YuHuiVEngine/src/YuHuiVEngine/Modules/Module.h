#pragma once

#include <string>

namespace Yuhui
{
	class Module
	{
	public:

		Module() : m_Active(true)
		{}

		virtual ~Module()
		{}

		virtual void Init()
		{}

		virtual void Start()
		{}

		virtual void PreUpdate()
		{}

		virtual void Update()
		{}

		virtual void PostUpdate()
		{}

		virtual void CleanUp()
		{}

		inline bool IsActive() { return m_Active; }

	protected:
		std::string	m_Name;

	private:
		bool m_Active;
	};
}