#include "Game.h"



int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR, int) {

	Game app{ hinstance };
	return app.Run();
}