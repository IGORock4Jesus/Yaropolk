#pragma once

#include <memory>
#include "Window.h"
#include "Renderer.h"
#include "Scene.h"
#include "ECS.h"


class Application
{
	HINSTANCE hinstance;
	std::shared_ptr<Window> window;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Scene> scene;
	std::shared_ptr<ECS> ecs;

public:
	Application(HINSTANCE hinstance);
	virtual ~Application();

	int Run();

	std::shared_ptr<ECS> GetECS() const { return ecs; }
};

