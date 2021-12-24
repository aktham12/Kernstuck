#include "khpc.h"

#include "Logger.h"

namespace Kernstuck
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	[[ noreturn ]] auto  Logger::init() ->void
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("KernStuck");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}



	
