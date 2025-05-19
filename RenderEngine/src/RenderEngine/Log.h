#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace RenderEngine
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

/*-------- CORE LOGS --------*/
// The '...' represents that the macro will have a variable number of arguments
// And we forward this variable number of arguments using '__VA_ARGS__' to the log function
#define RE_CORE_LOG(...)  ::RenderEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RE_CORE_INFO(...)   ::RenderEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...)   ::RenderEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)  ::RenderEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_CRITICAL(...)  ::RenderEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

/*-------- CLIENT LOGS --------*/
#define RE_LOG(...)       ::RenderEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RE_INFO(...)        ::RenderEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define RE_WARN(...)        ::RenderEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...)       ::RenderEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define RE_CRITICAL(...)       ::RenderEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

