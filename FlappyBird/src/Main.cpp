#include "Kernstuck.h"

class Application : public Kernstuck::KernstuckApplication
{
public:
	Application()
	{

	}

	~Application()
	{

	}


};

Kernstuck::KernstuckApplication* Kernstuck::CreateApplication()
{
	return new Application();
}
