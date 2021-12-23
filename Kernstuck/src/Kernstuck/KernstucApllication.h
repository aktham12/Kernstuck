#ifndef KERNSTUCK_APPLICATION_H
#define KERNSTUCK_APPLICATION_H

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
#endif // KERNSTUCK_APPLICATION_H

