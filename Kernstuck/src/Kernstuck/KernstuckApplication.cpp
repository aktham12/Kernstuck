#include "khpc.h"

#include "KernstuckApplication.h"

#include "Kernstuck/Events/ApplicationEvent.h"

#include "Kernstuck/Logger.h"

namespace Kernstuck
{

	KernstuckApplication::KernstuckApplication()
	{
		m_Window = std::unique_ptr<Window>(Window::createWindow());
	}

	KernstuckApplication::~KernstuckApplication()
	{
		
	}


	[[noreturn]] auto  KernstuckApplication::run() -> void
	 {

		while (m_Running)
		{ 
			m_Window->onUpdate();
		}
	 }

}