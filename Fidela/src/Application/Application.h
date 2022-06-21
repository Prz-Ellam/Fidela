#pragma once
#ifndef _FIDELA_APPLICATION_H_
#define _FIDELA_APPLICATION_H_

#include "Window/Window.h"
#include "Layer.h"

/*
	Crear una aplicacion en el cliente utilizando esta macro
*/
#define CREATE_APPLICATION(applicationName)\
	Fidela::Application* CreateApplication() {\
		return new applicationName;\
	}\

namespace Fidela
{
	class Application
	{
	public:
		Application() = default;
		Application(const Application& other) = default;
		Application(Application&& other) noexcept = default;
		virtual ~Application() = default;

		Application& operator=(const Application& other) = default;
		Application& operator=(Application&& other) noexcept = default;

		virtual void Create() = 0;
		virtual void Run() = 0;
		virtual void Destroy() = 0;
	protected:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window = nullptr;
		std::vector<std::unique_ptr<Layer>> m_Layers;
	};
}

#endif // _FIDELA_APPLICATION_H_
