#include <chrono>
#include <d3dx9.h>
#include "Helpers.h"
#include "Renderer.h"


using namespace std::chrono_literals;


Renderer::Renderer(std::shared_ptr<Window> window)
	: pp{ (UINT)window->GetClientSize().cx, (UINT)window->GetClientSize().cy, D3DFMT_X8R8G8B8, 1,
		D3DMULTISAMPLE_TYPE::D3DMULTISAMPLE_NONE, 0,
		D3DSWAPEFFECT_DISCARD, window->GetHandle(), TRUE, TRUE, D3DFMT_D24S8, 0,
		0, 0 }
{
	direct = Direct3DCreate9(D3D_SDK_VERSION);
	direct->CreateDevice(0, D3DDEVTYPE_HAL, window->GetHandle(), D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &pp, &device);

	//device->SetRenderState(D3DRS_LIGHTING, FALSE);
	//device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	window->SizeChanged.Add(this, &Renderer::Window_SizeChanged);

	/*enabled = true;
	thread = std::thread(&Renderer::StartRendering, this);*/
}


//void Renderer::StartRendering()
//{
//	while (enabled)
//	{
//		device->Clear(0, nullptr, D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET, 0xff222222, 1.0f, 0);
//		device->BeginScene();
//
//		Drawing(device);
//
//		device->EndScene();
//		device->Present(nullptr, nullptr, nullptr, nullptr);
//
//		std::this_thread::sleep_for(1ms);
//	}
//}

void Renderer::Window_SizeChanged(const SIZE & size)
{
	pp.BackBufferHeight = size.cy;
	pp.BackBufferWidth = size.cx;

	auto result = device->Reset(&pp);
	debug("Reset = " + std::string(result == S_OK ? "S_OK" : "E_FAIL"));
}

Renderer::~Renderer()
{
	/*enabled = false;
	if (thread.joinable())
		thread.join();*/
	if (device) device->Release();
	if (direct) direct->Release();
}

void Renderer::Rendering()
{
	device->Clear(0, nullptr, D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET, 0xff222222, 1.0f, 0);
	device->BeginScene();

	D3DXMATRIX m;
	device->SetTransform(D3DTS_VIEW, D3DXMatrixLookAtLH(&m, &D3DXVECTOR3(3, 3, -3), &D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 1.0f, 0.0f)));
	device->SetTransform(D3DTS_PROJECTION, D3DXMatrixPerspectiveFovLH(&m, D3DX_PI*0.25f, 1.3f, 0.1f, 10000.0f));

	Drawing(device);

	device->EndScene();
	device->Present(nullptr, nullptr, nullptr, nullptr);
}
