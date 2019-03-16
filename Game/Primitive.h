#pragma once

#include <d3dx9.h>
#include "Component.h"
#include "IRenderable.h"


struct Primitive : Component
{
	virtual ~Primitive()
	{

	}
};


struct BoxMesh : Primitive
{
	D3DXVECTOR3 size{ 1.0f, 1.0f, 1.0f };
	UINT color{ 0xff009999 };
};


