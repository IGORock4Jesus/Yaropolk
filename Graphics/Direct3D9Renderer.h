#pragma once

#include "IRenderer.h"

namespace Yaropolk::Graphics {

class Direct3D9Renderer : public IRenderer
{
public:
	Direct3D9Renderer();
	~Direct3D9Renderer();
};

}