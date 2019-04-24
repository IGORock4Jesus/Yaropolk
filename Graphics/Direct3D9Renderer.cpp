#include "Direct3D9Renderer.h"
#include <exception>
#include <d3dx9.h>


namespace Yaropolk::Graphics {

struct ColorVertex2
{
	float x, y, z, w;
	DWORD color;
	static const DWORD FORMAT = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	static const DWORD SIZE;
};
const DWORD ColorVertex2::SIZE = sizeof(ColorVertex2);

Direct3D9Renderer::Direct3D9Renderer(HWND hwnd)
{
	if (!(direct = Direct3DCreate9(D3D_SDK_VERSION)))
		throw std::exception("Direct3DCreate9");

	D3DPRESENT_PARAMETERS pp{ 0 };
	pp.AutoDepthStencilFormat = D3DFMT_D24S8;
	pp.BackBufferCount = 1;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	RECT rect;
	::GetClientRect(hwnd, &rect);
	pp.BackBufferHeight = rect.bottom - rect.top;
	pp.BackBufferWidth = rect.right - rect.left;
	pp.EnableAutoDepthStencil = TRUE;
	pp.hDeviceWindow = hwnd;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = TRUE;

	if (FAILED(direct->CreateDevice(0, D3DDEVTYPE_HAL, hwnd, D3DCREATE_MULTITHREADED | D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &device)))
		throw std::exception("IDirect3D9::CreateDevice");
}


Direct3D9Renderer::~Direct3D9Renderer()
{
}

void Direct3D9Renderer::Begin()
{
	device->Clear(0, nullptr, D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xff444444, 1.0f, 0);
	device->BeginScene();
}

void Direct3D9Renderer::End()
{
	device->EndScene();
	device->Present(nullptr, nullptr, nullptr, nullptr);
}

void Direct3D9Renderer::DrawRectangle(float x, float y, float w, float h, DWORD argb)
{
	ColorVertex2 vs[]{
		{x, y, 0, 1, argb},
		{x + w, y, 0, 1, argb},
		{x + w, y + h, 0, 1, argb},
		{x, y + h, 0, 1, argb},
	};
	device->SetFVF(ColorVertex2::FORMAT);
	device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vs, ColorVertex2::SIZE);
}

void Direct3D9Renderer::DrawString(float x, float y, float w, float h, int fontSize, std::string text, std::string fontName, DWORD format)
{
	Microsoft::WRL::ComPtr<ID3DXFont> font;
	auto result = D3DXCreateFont(device.Get(), -fontSize, 0, 0, 0, 0, 0, 0, 0, 0, fontName.c_str(), &font);
	
	RECT r{ (int)x, (int)y, (int)(x + w), (int)(y + h) };
	font->DrawTextA(nullptr, text.c_str(), text.size(), &r, format, 0xffffffff);
}

}