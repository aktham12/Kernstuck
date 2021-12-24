#ifndef KERNSTUCK_APPLICATION_H
#define KERNSTUCK_APPLICATION_H

#include "Core.h"
namespace Kernstuck
{
	class KS_API KernstuckApplication
	{
	public:
		KernstuckApplication();
		virtual ~KernstuckApplication();

		auto static run() ->void;

		// define this in the client
		
	};
	KernstuckApplication* CreateApplication();
}
#endif // KERNSTUCK_APPLICATION_H

