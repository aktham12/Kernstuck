#ifndef CORE_H
#define CORE_H


#ifdef KS_PLATFORM_WINDOWS
		#ifdef KS_BUILD_DLL
			#define KS_API __declspec(dllexport)
		#else
			#define KS_API __declspec(dllimport)

		#endif // KS_BUILD_DLL
	#else
	#error Kernstuck ONLY SUPPORT WINDOWS


	#endif
#endif

#ifdef KS_ENABLE_ASSERT
	#define KS_ASSERT(x, ...) { if (!(x)) { KS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KS_CORE_ASSERT(x, ...) { if (!(x)) { KS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KS_ASSERT(x, ...)
	#define KS_CORE_ASSERT(x, ...)
#endif
#define BIT(x)  (1 << (x))
