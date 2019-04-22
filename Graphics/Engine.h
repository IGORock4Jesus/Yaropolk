#pragma once

#include <memory>
#include "GraphicsAPI.h"

namespace Yaropolk::Graphics {

__interface IRenderer;


class GRAPHICS_API Engine
{
	std::shared_ptr<IRenderer> renderer;

public:
	Engine();
	~Engine();
};

}