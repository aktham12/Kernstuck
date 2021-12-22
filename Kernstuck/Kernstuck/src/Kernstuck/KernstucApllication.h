#pragma once
#include "Core.h"
namespace Kernstuck
{
	class KS_API KernstucApllication
	{
	public:
		KernstucApllication();
		virtual ~KernstucApllication();

		void Run();

		// define this in the client
		
	};
	KernstucApllication* CreateApplication();
}

