#pragma once

#include <d3d9.h>
#include <wrl.h>

#include "IRenderer.h"

namespace Yaropolk::Graphics {

class Direct3D9Renderer : public IRenderer
{
	Microsoft::WRL::ComPtr<IDirect3D9> direct;
	Microsoft::WRL::ComPtr<IDirect3DDevice9> device;

public:
	Direct3D9Renderer(HWND hwnd);
	~Direct3D9Renderer();



	// Унаследовано через IRenderer
	virtual void Begin() override;

	virtual void End() override;

	void DrawRectangle(float x, float y, float w, float h, DWORD argb);
	void DrawString(float x, float y, float w, float h, int fontSize, std::string text, std::string fontName, DWORD format = DT_LEFT | DT_TOP);
};

}