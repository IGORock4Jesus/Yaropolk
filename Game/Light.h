#pragma once

#include <d3dx9.h>
#include "Component.h"
#include "IRenderable.h"


struct Light : Component
{
	D3DXVECTOR3 direction{ 0.0f, -1.0f, 0.0f };
	D3DCOLORVALUE color{ 1.0f, 1.0f, 1.0f, 1.0f };
};