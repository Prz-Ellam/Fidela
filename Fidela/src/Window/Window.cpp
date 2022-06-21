#include "fdlpch.h"
#include "Window.h"
#include "Core/Core.h"

namespace Fidela
{
	Window::Window(uint32_t width, uint32_t height, std::string title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		
	
	}

	uint32_t Window::GetWidth() const
	{
		return m_Width;
	}

	uint32_t Window::GetHeight() const
	{
		return m_Height;
	}

	std::string Window::GetTitle() const
	{
		return m_Title;
	}
}