#ifndef KERNSTUCK_APPLICATION_H
#define KERNSTUCK_APPLICATION_H
#include "khpc.h"

#include "Core.h"

#include "Window.h"




namespace Kernstuck
{
	class KS_API KernstuckApplication
	{
	public:
		KernstuckApplication();
		virtual ~KernstuckApplication();

		auto  run() -> void;
		auto onEvent(Event& event) -> void;


		// define this in the client
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
	};
	KernstuckApplication* CreateApplication();
}
#endif // KERNSTUCK_APPLICATION_H

