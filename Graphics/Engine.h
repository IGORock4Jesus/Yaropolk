#pragma once

#include <memory>
#include <Subsystem/Window.h>

#include "GraphicsAPI.h"

namespace Yaropolk::Graphics {

__interface IRenderer;


class GRAPHICS_API Engine
{
	std::shared_ptr<IRenderer> renderer;

public:
	Engine(std::shared_ptr<Subsystem::Window> window);
	~Engine();

	void Start();
	void Stop();
};

}