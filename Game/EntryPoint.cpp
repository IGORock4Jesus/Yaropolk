#include "Application.h"



int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR, int) {

	Application app{ hinstance };
	return app.Run();
}