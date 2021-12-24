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

#define BIT(x)  (1 << (x))
