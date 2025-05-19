#include "pchRender.h"

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace RenderEngine
{
	std::shared_ptr<spdlog::logger> RenderEngine::Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> RenderEngine::Log::s_ClientLogger;

	void RenderEngine::Log::Init()
	{
		// Properly color the message, time stamp, name of the logger, actual message.
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("RE_ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

		RE_CORE_INFO("Initialized Log!");
	}
}