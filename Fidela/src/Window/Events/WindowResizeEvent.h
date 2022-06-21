#pragma once
#ifndef _FIDELA_WINDOW_RESIZE_EVENT_H
#define _FIDELA_WINDOW_RESIZE_EVENT_H

namespace Fidela
{
	class WindowResizeEvent
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height);

		inline uint32_t GetWidth() const;
		inline uint32_t GetHeight() const;

	private:
		uint32_t m_Width, m_Height;
	};

	inline uint32_t WindowResizeEvent::GetWidth() const
	{
		return m_Width;
	}

	inline uint32_t WindowResizeEvent::GetHeight() const
	{
		return m_Height;
	}

	using WindowResizeEventFn = std::function<void(WindowResizeEvent)>;
}

#endif // _FIDELA_WINDOW_RESIZE_EVENT_H
