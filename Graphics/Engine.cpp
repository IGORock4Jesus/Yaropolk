#include "Engine.h"
#include "IRenderer.h"

#include "Direct3D9Renderer.h"


namespace Yaropolk::Graphics {

void Engine::Render(float elapsedTime) {
	renderer->Begin();

	Rendering(renderer);

	renderer->End();
}

Engine::Engine(std::shared_ptr<Subsystem::Window> window)
{
	thread.Updating.Add(this, &Engine::Render);
	thread.SetDelay(1);

	renderer = std::make_shared<Direct3D9Renderer>(window->GetHandle());

	//painter = std::make_shared<
}


Engine::~Engine()
{
}

void Engine::Start() {
	thread.Start();
}

void Engine::Stop() {
	thread.Stop();
}
}