#pragma once

#include <memory>
#include "Window.h"
#include "Renderer.h"
#include "Scene.h"


class Application
{
	HINSTANCE hinstance;
	std::shared_ptr<Window> window;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Scene> scene;

public:
	Application(HINSTANCE hinstance);
	virtual ~Application();

	int Run();
};

