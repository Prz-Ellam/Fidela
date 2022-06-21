#pragma once
#ifndef _FIDELA_GLFWWINDOW_H
#define _FIDELA_GLFWWINDOW_H

#include "Window/Window.h"

#include "Window/Events/WindowCloseEvent.h"

struct GLFWwindow;

namespace Fidela
{
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(uint32_t width, uint32_t height, const std::string& title);
		virtual ~GLFWWindow();

		std::string GetTitle() const;
		void SetTitle(const std::string& title) override;

		void Update() override;
		void Show() override;
		void Hide() override;

		void SetWindowCloseEvent(WindowCloseEventFn windowCloseEventFn);

	private:
		GLFWwindow* m_Window = nullptr;

		static void StaticWindowCloseEvent(GLFWwindow* glfwWindow);

		WindowCloseEventFn m_WindowCloseEventFn;

	};
}

#endif
