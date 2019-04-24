#pragma once

#include <memory>
#include <Windows.h>

#include <ECS/Engine.h>
#include <Subsystem/Window.h>
#include <Graphics/Engine.h>

#include "ApplicationAPI.h"

namespace Yaropolk::Application {

class APPLICATION_API App
{
	HINSTANCE hinstance;
	std::shared_ptr<Subsystem::Window> window;
	std::shared_ptr<Graphics::Engine> graphics;
	std::shared_ptr<ECS::Engine> ecs;

public:
	App(HINSTANCE hinstance);
	virtual ~App();

	void Run();

	const std::shared_ptr<Subsystem::Window>& GetWindow() const { return window; }
	const std::shared_ptr<Graphics::Engine>& GetGraphics() const { return graphics; }
	const std::shared_ptr<ECS::Engine>& GetECS() const { return ecs; }
};

}