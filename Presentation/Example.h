#pragma once
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <Fidela.h>

class Example : public Fidela::Application
{
public:
	Example();
	virtual ~Example();

	void Create() override;
	void Run() override;
	void Destroy() override;

	void CloseWindow(Fidela::WindowCloseEvent e);
	void WindowMove(Fidela::WindowMoveEvent e);
};

class ExampleLayer : public Fidela::Layer
{
public:
	ExampleLayer() : Layer() {};
	virtual ~ExampleLayer() {}

	void Create() override;
	void Update() override;
	void Destroy() override;
};

class AnotherExampleLayer : public Fidela::Layer
{
public:
	AnotherExampleLayer() : Layer() {};
	virtual ~AnotherExampleLayer() {}

	void Create() override;
	void Update() override;
	void Destroy() override;
};

#endif