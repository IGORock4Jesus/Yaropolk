#pragma once

#include <d3d9.h>
//#include <thread>
#include <memory>
#include "Event.h"
#include "Window.h"


class Renderer
{
	LPDIRECT3D9 direct{ nullptr };
	LPDIRECT3DDEVICE9 device{ nullptr };
	D3DPRESENT_PARAMETERS pp;
	/*bool enabled{ false };
	std::thread thread;*/

	//void StartRendering();
	void Window_SizeChanged(const SIZE& size);

public:
	Event<LPDIRECT3DDEVICE9> Drawing;

	Renderer(std::shared_ptr<Window> window);
	~Renderer();

	LPDIRECT3DDEVICE9 GetDevice() const { return device; }

	void Rendering();
};

