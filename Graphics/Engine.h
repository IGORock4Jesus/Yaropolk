#pragma once

#include <memory>
#include <Subsystem/Window.h>
#include <Trivial/Event.h>
#include <Trivial/Thread.h>

#include "GraphicsAPI.h"
//#include "IPainter.h"

namespace Yaropolk::Graphics {

__interface IRenderer;


class GRAPHICS_API Engine
{
	std::shared_ptr<IRenderer> renderer;
	//std::shared_ptr<IPainter> painter;
	Trivial::Thread thread;

	void Render(float elapsedTime);

public:
	Trivial::Event<std::shared_ptr<IRenderer>> Rendering;

	Engine(std::shared_ptr<Subsystem::Window> window);
	~Engine();

	void Start();
	void Stop();
};

}