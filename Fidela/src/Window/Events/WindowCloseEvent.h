#pragma once
#ifndef _FIDELA_WINDOW_CLOSE_EVENT_H
#define _FIDELA_WINDOW_CLOSE_EVENT_H

namespace Fidela
{
	class WindowCloseEvent
	{
	public:
		WindowCloseEvent() = default;
	};

	using WindowCloseEventFn = std::function<void(WindowCloseEvent)>;
}

#endif // _FIDELA_WINDOW_CLOSE_EVENT_H
