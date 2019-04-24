#pragma once


#ifdef TRIVIAL_EXPORTS
#define TRIVIAL_API __declspec(dllexport)
#else
#define TRIVIAL_API __declspec(dllimport)
#endif // TRIVIAL_EXPORTS
