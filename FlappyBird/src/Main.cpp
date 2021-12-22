#include "Kernstuck.h"

class Application : public Kernstuck::KernstucApllication
{
public:
	Application()
	{

	}

	~Application()
	{

	}


};

Kernstuck::KernstucApllication* Kernstuck::CreateApplication()
{
	return new Application();
}
