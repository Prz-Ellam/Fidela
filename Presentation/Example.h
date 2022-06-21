#pragma once

#include <Fidela.h>

class Example : public Fidela::Application
{
public:
	Example();
	void Create() override;
	void Run() override;
	void Destroy() override;
	virtual ~Example();
};