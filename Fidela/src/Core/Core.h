#ifndef FIDELA_CORE_H
#define FIDELA_CORE_H
#pragma once

#define FDL_ASSERT(condition, message, ...)\
	if (!condition) {\
		Fidela::Log::Error(std::source_location::current() ,message, __VA_ARGS__);\
		__debugbreak();\
	}\

#endif
