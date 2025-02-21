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

		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		float vertices[6 * 3]{
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		m_vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
		m_vertexBuffer->bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

		uint32_t indices[3]{ 0, 1, 2 };

		m_elementBuffer.reset(ElementBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_elementBuffer->bind();

		m_shader = std::make_unique<Shader>("../../Shaders/triangle.vert", "../../Shaders/triangle.frag");

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
			glBindVertexArray(m_vao);
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