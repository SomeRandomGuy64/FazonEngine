#include <Fazon.h>

class ExampleLayer : public Fazon::Layer {

public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override {
		FZ_INFO("ExampleLayer::Update");
	}

	void onEvent(Fazon::Event& event) override {
		FZ_TRACE("{0}", event);
	}

};

class Sandbox : public Fazon::Application {

public:
	Sandbox() 
	{
		//pushLayer(new ExampleLayer());
		pushLayer(new Fazon::ImGuiLayer());
	}

	~Sandbox() 
	{

	}

};

Fazon::Application* Fazon::createApplication() {
	return new Sandbox();
}