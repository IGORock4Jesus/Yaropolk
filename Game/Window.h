#pragma once

#include <Windows.h>
#include "Event.h"


class Window
{
	HWND handle;
	LPCSTR windowClass = "YAROPOLK WINDOW";


	static LRESULT CALLBACK WndProc(HWND h, UINT m, WPARAM w, LPARAM l);
public:
	Event<const SIZE&> SizeChanged;

	Window(HINSTANCE hinstance);
	~Window();

	HWND GetHandle() const { return handle; }
	SIZE GetClientSize() const {
		RECT r;
		GetClientRect(handle, &r);
		return { r.right - r.left,r.bottom - r.top };
	}

	bool Update();
};

