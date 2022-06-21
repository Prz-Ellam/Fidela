#define _GLFW_WIN32

// Esto no es una buena practica, mas adelante se creara un proyecto para compilar GLFW
// Razones de porque no es seguro
// 1 - Funciones estaticas, en archivos separados solo son leidas por la unidad de traduccion correspondiente
// Juntas se arma un error

#include <src/context.c>
#include <src/init.c>
#include <src/input.c>
#include <src/monitor.c>

#include <src/null_init.c>
#include <src/null_joystick.c>
#include <src/null_monitor.c>
#include <src/null_window.c>

#include <src/platform.c>
#include <src/vulkan.c>
#include <src/window.c>