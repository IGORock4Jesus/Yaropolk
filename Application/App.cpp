#include "App.h"


namespace Yaropolk::Application {


App::App(HINSTANCE hinstance)
	: hinstance{ hinstance }
{
	window = std::make_shared<Subsystem::Window>(hinstance, 800, 600);

	graphics = std::make_shared<Graphics::Engine>(window);

	ecs = std::make_shared<ECS::Engine>();
}


App::~App()
{
}

void App::Run()
{
	graphics->Start();

	ecs->Start();

	window->Run();

	ecs->Stop();

	graphics->Stop();
}

}