#include "Application.h"
#include <string>
#include "System.h"


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
