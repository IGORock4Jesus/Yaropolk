#include "Window.h"


namespace Yaropolk::Subsystem {
LRESULT Window::WndProcStatic(HWND h, UINT m, WPARAM w, LPARAM l)
{
	switch (m)
	{
	case WM_NCCREATE: {
		auto cs = (LPCREATESTRUCT)l;
		auto window = (Window*)cs->lpCreateParams;
		SetWindowLongPtr(h, GWLP_USERDATA, (LONG_PTR)window);
		return TRUE;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default: {
		auto window = static_cast<Window*>((void*)GetWindowLongPtr(h, GWLP_USERDATA));
		if (window)
			return window->Processor(h, m, w, l);
		else
			return DefWindowProc(h, m, w, l);
	}
	}
	return LRESULT(0);
}
LRESULT Window::Processor(HWND h, UINT m, WPARAM w, LPARAM l)
{
	switch (m)
	{
	case WM_KEYDOWN:
		KeyDown(w);
		return 0;
	case WM_KEYUP:
		KeyUp(w);
		return 0;
	default:
		return DefWindowProc(h, m, w, l);
	}

}
Window::Window(HINSTANCE hinstance, int width, int height)
{
	WNDCLASS wc{ 0 };
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hInstance = hinstance;
	wc.lpfnWndProc = WndProcStatic;
	wc.lpszClassName = className;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);

	handle = CreateWindow(className, className, WS_POPUPWINDOW, 0, 0, width, height, HWND_DESKTOP, nullptr, hinstance, this);

	ShowWindow(handle, SW_NORMAL);
	UpdateWindow(handle);
}


Window::~Window()
{
}

void Window::Run()
{
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

}