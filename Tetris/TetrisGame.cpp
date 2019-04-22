#include <Application/App.h>

using namespace Yaropolk::Application;

class TetrisGame : public App {
public:
	TetrisGame(HINSTANCE hinstance)
		: App(hinstance) {

	}
};

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR, int) {
	TetrisGame game{ hinstance };
	game.Run();

	return 0;
}