#include "fdlpch.h"
#include "Application.h"
#include "Logging/Log.h"

extern Fidela::Application* CreateApplication();

int main(int argc, char** argv)
{
	Fidela::Application* application = CreateApplication();
	application->Run();
	delete application;
}

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int nCmdShow)
{
	Fidela::Application* application = CreateApplication();
	application->Run();
	delete application;
}
*/