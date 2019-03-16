#include "Window.h"


LRESULT Window::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
	switch (m)
	{
	case WM_NCCREATE: {
		auto create = (CREATESTRUCT*)l;
		::SetWindowLongPtr(h, GWLP_USERDATA, (LONG_PTR)create->lpCreateParams);
		return TRUE;
	}
	case WM_NCDESTROY:
		::SetWindowLongPtr(h, GWLP_USERDATA, (LONG_PTR)nullptr);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_SIZE: {
		auto _this = (Window*)::GetWindowLongPtr(h, GWLP_USERDATA);
		SIZE size{ LOWORD(l), HIWORD(l) };
		_this->SizeChanged(size);
		return 0;
	}

	default:
		return DefWindowProc(h, m, w, l);
	}
}

Window::Window(HINSTANCE hinstance)
{
	WNDCLASS wc{ 0 };
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hInstance = hinstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = windowClass;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	RegisterClass(&wc);

	handle = CreateWindow(windowClass, windowClass, WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, HWND_DESKTOP, nullptr, hinstance, this);

	ShowWindow(handle, SW_NORMAL);
}

Window::~Window()
{
}

bool Window::Update()
{
	MSG msg;

	if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.message != WM_QUIT;
}
