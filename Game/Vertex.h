#pragma once

#include <d3dx9.h>

struct ColorVertex
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 normal;
	UINT color;

	static const DWORD size;
	static const DWORD format;
};