#include <Fazon.h>

class Sandbox : public Fazon::Application {

public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Fazon::Application* Fazon::createApplication() {
	return new Sandbox();
}