#pragma once
#ifndef _FIDELA_WINDOW_MOVE_EVENT_H_
#define _FIDELA_WINDOW_MOVE_EVENT_H_

namespace Fidela
{
	class WindowMoveEvent
	{
	public:
		WindowMoveEvent(int x, int y) : m_X(x), m_Y(y) {}

		inline int GetX() const;
		inline int GetY() const;

	private:
		int m_X, m_Y;
	};

	inline int WindowMoveEvent::GetX() const
	{
		return m_X;
	}

	inline int WindowMoveEvent::GetY() const
	{
		return m_Y;
	}

	using WindowMoveEventFn = std::function<void(WindowMoveEvent)>;
}

#endif // _FIDELA_WINDOW_MOVE_EVENT_H_
