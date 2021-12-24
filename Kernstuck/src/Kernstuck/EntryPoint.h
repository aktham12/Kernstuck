#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H
#include "KernstuckApplication.h"	

#ifdef KS_PLATFORM_WINDOWS

extern Kernstuck::KernstuckApplication* Kernstuck::CreateApplication();
	int main(int argc, char** argv)
	{

		Kernstuck::Logger::init();
		KS_CORE_INFO("The Logger Is Working!");


		const auto app = new Kernstuck::KernstuckApplication();
		app->run();
		delete app;
	}
#endif //KS_PLATFORM_WINDOWS
#endif //ENTRY_POINT_H