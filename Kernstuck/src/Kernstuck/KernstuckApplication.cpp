#include "khpc.h"

#include "KernstuckApplication.h"

#include <GL/gl.h>


#include "Kernstuck/Events/ApplicationEvent.h"

#include "Kernstuck/Logger.h"

namespace Kernstuck
{

	KernstuckApplication::KernstuckApplication()
	{
		m_Window = std::unique_ptr<Window>(Window::createWindow());
		m_Window->setEventCallback([this](auto&& PH1) { onEvent(std::forward<decltype(PH1)>(PH1)); });
	}

	KernstuckApplication::~KernstuckApplication()
	{
		
	}
	auto KernstuckApplication::onEvent(Event& event)->void
	{
		KS_CORE_INFO("Event: {0}", event.toString());
	}


	[[noreturn]] auto  KernstuckApplication::run() -> void
	 {

		while (m_Running)
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->onUpdate();
		}
	 }

}