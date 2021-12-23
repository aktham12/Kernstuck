#pragma once
#ifdef KS_PLATFORM_WINDOWS
	#ifdef KS_BULID_DLL
		#define KS_API __declspec(dllexport)
	#else
		#define KS_API __declspec(dllimport)

	#endif // KS_BULID_DLL
#else
#error Kernstuck ONLY SUPPORT WINDOWS


#endif
