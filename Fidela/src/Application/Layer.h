#pragma once
#ifndef _FIDELA_LAYER_H
#define _FIDELA_LAYER_H

namespace Fidela
{
	class Layer
	{
	public:
		Layer() = default;

		virtual void Create() = 0;
		virtual void Update() = 0;
		virtual void Destroy() = 0;
	private:
	};
}

#endif
