#pragma once
#include "KernstucApllication.h"

#ifdef KS_PLATFORM_WINDOWS

extern Kernstuck::KernstucApllication* Kernstuck::CreateApplication();
	int main(int argc, char** argv)
	{

		Kernstuck::Logger::Init();
		KS_CORE_TRACE("init everyThing");
		KS_CORE_INFO("hELLO! Var={0}", 5);
	

		auto app = new Kernstuck::KernstucApllication();
		app->Run();
		delete app;
	}
#endif