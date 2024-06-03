#pragma once

#include <spdlog/spdlog.h>
#include "YuHuiVEngine/Core/Base.h"

namespace Yuhui
{
	class Logger
	{
	public:
		static void Init();

		static Ref<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
	};
}

#define YHV_CORE_TRACE(...)    ::Yuhui::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define YHV_CORE_INFO(...)     ::Yuhui::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define YHV_CORE_WARN(...)     ::Yuhui::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define YHV_CORE_ERROR(...)    ::Yuhui::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define YHV_CORE_CRITICAL(...) ::Yuhui::Logger::GetCoreLogger()->critical(__VA_ARGS__)