#include "Example.h"
#include <iostream>
#include <glad/glad.h>

Example::Example()
{
	m_Window = new Fidela::GLFWWindow(640u, 480u, "Mi ventana");
}

void Example::Create()
{
	std::cout << "Prueba";

}

void Example::Run()
{
	while (m_Running)
	{
		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->Update();
	}
}

void Example::Destroy()
{

}

Example::~Example()
{
	delete m_Window;
}

CREATE_APPLICATION(Example);