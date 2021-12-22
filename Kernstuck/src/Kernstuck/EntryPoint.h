#pragma once
#include "KernstucApllication.h"

#ifdef KS_PLATFORM_WINDOWS

extern Kernstuck::KernstucApllication* Kernstuck::CreateApplication();
	int main(int argc, char** argv)
	{
		auto app = new Kernstuck::KernstucApllication();
		app->Run();
		delete app;
	}
#endif