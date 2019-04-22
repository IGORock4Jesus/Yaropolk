#pragma once

#include <Windows.h>

#include "SubsystemAPI.h"


namespace Yaropolk::Subsystem {

class SUBSYSTEM_API Window
{
	HWND handle;
	LPCSTR className = "YAROPOLK_WINDOW";

	static LRESULT CALLBACK WndProcStatic(HWND h, UINT m, WPARAM w, LPARAM l);
	virtual LRESULT Processor(HWND h, UINT m, WPARAM w, LPARAM l);

public:
	Window(HINSTANCE hinstance, int width, int height);
	~Window();

	HWND GetHandle() const { return handle; }

	void Run();
};

}