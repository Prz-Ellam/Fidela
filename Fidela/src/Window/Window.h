#pragma once
#ifndef _FIDELA_WINDOW_H_
#define _FIDELA_WINDOW_H_

#include "Events/Events.h"

namespace Fidela
{
	class Window
	{
	public:
		Window();
		Window(uint32_t width, uint32_t height, std::string title);

		uint32_t GetWidth() const;
		uint32_t GetHeight() const;

		std::string GetTitle() const;
		virtual void SetTitle(const std::string& title) = 0;

		virtual void* GetNativeWindow() const = 0;

		virtual void Update() = 0;
		virtual void Show() = 0;
		virtual void Hide() = 0;

		virtual void SetWindowCloseEvent(WindowCloseEventFn windowCloseEventFn) = 0;
		virtual void SetWindowMoveEvent(WindowMoveEventFn windowMoveEventFn) = 0;
	protected:
		uint32_t m_Width, m_Height;
		std::string m_Title;

		WindowCloseEventFn m_WindowCloseEventFn;
		WindowMoveEventFn m_WindowMoveEventFn;
		WindowResizeEventFn m_WindowResizeEventFn;
	};
}

#endif
