#ifndef LOGGER_H
#define LOGGER_h


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>
namespace Kernstuck
{
	class KS_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};
}

// core Log macros
#define KS_CORE_INFO(...)      ::Kernstuck::Logger::getCoreLogger()->info(__VA_ARGS__)
#define KS_CORE_TRACE(...)     ::Kernstuck::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define KS_CORE_WARN(...)      ::Kernstuck::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define KS_CORE_ERROR(...)     ::Kernstuck::Logger::getCoreLogger()->error(__VA_ARGS__)
#define KS_CORE_FATAL(...)     ::Kernstuck::Logger::getCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define KS_CLIENT_INFO(...)     ::Kernstuck::Logger::getClientLogger()->info(__VA_ARGS__)
#define KS_CLIENT_TRACE(...)    ::Kernstuck::Logger::getClientLogger()->trace(__VA_ARGS__)
#define KS_CLIENT_WARN(...)     ::Kernstuck::Logger::getClientLogger()->warn(__VA_ARGS__)
#define KS_CLIENT_ERROR(...)    ::Kernstuck::Logger::getClientLogger()->error(__VA_ARGS__)
#define KS_CLIENT_FATAL(...)    ::Kernstuck::Logger::getClientLogger->fatal(__VA_ARGS__)


#endif // !LOGGER_H