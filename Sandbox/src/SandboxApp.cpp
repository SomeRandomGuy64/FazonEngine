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

	void onEvent([[maybe_unused]]Fazon::Event& event) override {
		FZ_TRACE("{0}", event);
	}

	virtual void onImGuiRender() override {

		ImGui::Begin("Test");
		ImGui::Text("Hello, world!");
		ImGui::End();

	}

};

class Sandbox : public Fazon::Application {

public:
	Sandbox() 
	{
		//pushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}

};

Fazon::Application* Fazon::createApplication() {
	return new Sandbox();
}