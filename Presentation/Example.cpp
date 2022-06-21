#include "Example.h"
#include <glad/glad.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

void ExampleLayer::Create()
{
	FDL_DEBUG("Entre a create")
}

void ExampleLayer::Update()
{
	FDL_DEBUG("Entre a update")
}

void ExampleLayer::Destroy()
{
	FDL_DEBUG("Entre a destroy")
}

void AnotherExampleLayer::Create()
{
	FDL_DEBUG("Otro a create")
}

void AnotherExampleLayer::Update()
{
	FDL_INFO("Otro a update")
}

void AnotherExampleLayer::Destroy()
{
	FDL_DEBUG("Entre a destroy")
}


Example::Example()
{
	m_Window = std::make_unique<Fidela::GLFWWindow>(1280u, 720u, "Fidela Engine");
	m_Layers.push_back(std::make_unique<ExampleLayer>());
	m_Layers.push_back(std::make_unique<AnotherExampleLayer>());
	Create();
}

void Example::Create()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(reinterpret_cast<GLFWwindow*>(m_Window->GetNativeWindow()), true);
	ImGui_ImplOpenGL3_Init("#version 330");

	//m_Window->SetWindowCloseEvent(std::bind(&CloseWindow, this, std::placeholders::_1));
	m_Window->SetWindowCloseEvent([this](Fidela::WindowCloseEvent e) { CloseWindow(e); });
	m_Window->SetWindowMoveEvent([this](Fidela::WindowMoveEvent e) { WindowMove(e); });

	for (auto& layer : m_Layers)
	{
		layer->Create();
	}


}

void Example::CloseWindow(Fidela::WindowCloseEvent e)
{
	m_Running = false;
}

void Example::WindowMove(Fidela::WindowMoveEvent e)
{
	FDL_INFO("Window position x: {} y: {}", e.GetX(), e.GetY());
}

void Example::Run()
{
	while (m_Running)
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		for (auto& layer : m_Layers)
		{
			layer->Update();
		}

		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");       
		if (ImGui::Button("Button"))    {}
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();

		ImGui::Render();
		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		m_Window->Update();
	}
}

void Example::Destroy()
{
	for (auto& layer : m_Layers)
	{
		layer->Destroy();
	}
}

Example::~Example()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

CREATE_APPLICATION(Example);