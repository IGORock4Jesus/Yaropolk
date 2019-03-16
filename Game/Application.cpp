#include "Application.h"
#include <string>
#include "Helpers.h"

#pragma region Managers
#include "PrimitiveManager.h"
#include "LightManager.h"

#pragma endregion

#pragma region Systems
#include "RenderSystem.h"

#pragma endregion




static void test(const SIZE& size) {
	debug("Size {" + std::to_string(size.cx) + ", " + std::to_string(size.cy) + "}");
}

Application::Application(HINSTANCE hinstance)
	: hinstance{ hinstance }
{
	window = std::make_shared<Window>(hinstance);
	window->SizeChanged.Add(test);

	renderer = std::make_shared<Renderer>(window);

	scene = std::make_shared<Scene>(renderer);

	ecs = std::make_shared<ECS>(
		std::vector<std::shared_ptr<ComponentManager>> {
			std::make_shared<PrimitiveManager>(),
			std::make_shared<LightManager>()
		},
		std::vector<std::shared_ptr<System>> {
			std::make_shared<RenderSystem>(renderer)
		});
}


Application::~Application()
{
	renderer.reset();
	window.reset();
}

int Application::Run()
{
	DWORD oldTime = timeGetTime();

	while (window->Update()) {
		auto newTime = timeGetTime();
		auto time = (newTime - oldTime)*0.001f;
		oldTime = newTime;

		scene->Update(time);

		renderer->Rendering();
	}
	return 0;
}
