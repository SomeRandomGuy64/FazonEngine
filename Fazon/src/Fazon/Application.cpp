#include "Application.h"
#include "fzpch.h"

#include "Fazon/Events/WindowEvent.h"

#include "Input.h"

#include <glad/glad.h>

namespace Fazon {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application() 
	{
		FZ_CORE_ASSERT(s_instance == nullptr, "Application already exists!");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

		m_imGuiLayer = new ImGuiLayer{};
		pushOverlay(m_imGuiLayer);

		m_vertexArray = VertexArray::create(3);

		std::vector<float> vertices{
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		m_vertexBuffer = VertexBuffer::create(std::move(vertices), static_cast<uint32_t>(sizeof(float) * vertices.size()));

		std::vector<uint32_t> indices{ 0, 1, 2 };

		m_elementBuffer = ElementBuffer::create(std::move(indices), static_cast<uint32_t>(sizeof(uint32_t) * indices.size()));

		m_vertexArray->setBuffers(m_vertexBuffer, m_elementBuffer);

		m_shader = Shader::create("triangle", "../../Shaders/triangle.vert", "../../Shaders/triangle.frag");

	}

	Application::~Application() 
	{
	}

	void Application::pushLayer(Layer* layer) {

		m_layerStack.pushLayer(layer);
		layer->onAttach();

	}

	void Application::pushOverlay(Layer* overlay) {

		m_layerStack.pushOverlay(overlay);
		overlay->onAttach();

	}

	void Application::onEvent(Event& event) {

		EventDispatcher dispatcher{ event };
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::m_onWindowClosed));

		FZ_CORE_DEBUG("{0}", event);

		for (auto it{ m_layerStack.end() }; it != m_layerStack.begin(); ) {
			(*--it)->onEvent(event);
			if (event.handled) {
				break;
			}
		}

	}

	void Application::run() {
		while (m_running) {

			glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_shader->bind();
			m_vertexArray->bind();
			glDrawElements(GL_TRIANGLES, m_elementBuffer->getCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_layerStack) {
				layer->onUpdate();
			}

			m_imGuiLayer->begin();
			for (Layer* layer : m_layerStack) {
				layer->onImGuiRender();
			}
			m_imGuiLayer->end();
			
			m_window->onUpdate();

		}
	}

	bool Application::m_onWindowClosed(WindowCloseEvent&) {

		m_running = false;
		return true;

	}

}