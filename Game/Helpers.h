#pragma once

#include <string>
#include <Windows.h>


inline void debug(std::string s) {
	OutputDebugString((s + "\n").c_str());
}