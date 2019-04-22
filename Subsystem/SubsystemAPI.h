#pragma once

#ifdef SUBSYSTEM_EXPORTS
#define SUBSYSTEM_API __declspec(dllexport)
#else
#define SUBSYSTEM_API __declspec(dllimport)
#endif // SUBSYSTEM_EXPORTS
