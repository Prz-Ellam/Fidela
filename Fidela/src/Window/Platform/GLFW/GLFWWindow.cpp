#include "fdlpch.h"
#include "GLFWWindow.h"
#include "Logging/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Fidela
{
	GLFWWindow::GLFWWindow(uint32_t width, uint32_t height, const std::string& title)
		: Window(width, height, title)
	{
		glfwInit();

		m_Window = glfwCreateWindow(static_cast<int>(m_Width), static_cast<int>(m_Height), m_Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);

		int result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		m_WindowCloseEventFn = [](WindowCloseEvent e) {};
		m_WindowMoveEventFn = [](WindowMoveEvent e) {};

		glfwSetWindowCloseCallback(m_Window, StaticWindowCloseEvent);
		glfwSetWindowUserPointer(m_Window, this);

		glfwSetWindowPosCallback(m_Window, StaticWindowMoveEvent);

		glfwSetWindowSizeCallback(m_Window, GLFWwindowsizefun);

	}

	GLFWWindow::~GLFWWindow()
	{
		delete m_Window;
	}

	void* GLFWWindow::GetNativeWindow() const
	{
		return m_Window;
	}

	std::string GLFWWindow::GetTitle() const
	{
		return m_Title;
	}

	void GLFWWindow::SetTitle(const std::string& title)
	{
		m_Title = title;
		glfwSetWindowTitle(m_Window, m_Title.c_str());
	}

	void GLFWWindow::Update()
	{
		glfwPollEvents();
		// TODO: Mover glfwSwapBuffers(GLFWwindow*) a la clase del contexto
		glfwSwapBuffers(m_Window);
	}

	void GLFWWindow::Show()
	{
		glfwShowWindow(m_Window);
	}

	void GLFWWindow::Hide()
	{
		glfwHideWindow(m_Window);
	}

	void GLFWWindow::StaticWindowCloseEvent(GLFWwindow* glfwWindow)
	{
		GLFWWindow* window = reinterpret_cast<GLFWWindow*>(glfwGetWindowUserPointer(glfwWindow));
		window->m_WindowCloseEventFn(WindowCloseEvent());
	}

	void GLFWWindow::StaticWindowMoveEvent(GLFWwindow* glfwWindow, int x, int y)
	{
		GLFWWindow* window = reinterpret_cast<GLFWWindow*>(glfwGetWindowUserPointer(glfwWindow));
		window->m_WindowMoveEventFn(WindowMoveEvent(x, y));
	}

	void GLFWWindow::SetWindowCloseEvent(WindowCloseEventFn windowCloseEventFn)
	{
		m_WindowCloseEventFn = windowCloseEventFn;
	}

	void GLFWWindow::SetWindowMoveEvent(WindowMoveEventFn windowMoveEventFn)
	{
		m_WindowMoveEventFn = windowMoveEventFn;
	}

	void GLFWWindow::StaticWindowResizeEvent(GLFWwindow* glfwWindow, uint32_t width, uint32_t height)
	{
		
	}
}