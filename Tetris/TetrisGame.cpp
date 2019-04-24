#include <Application/App.h>
#include <ECS/SystemManager.h>
#include <ECS/EntityManager.h>
#include <ECS/ComponentManager.h>

#include "GameFieldView.h"
#include "ScoreView.h"
#include "NextView.h"
#include "ViewerSystem.h"
#include "BlockGeneratorSystem.h"

using namespace Yaropolk::Application;


namespace Yaropolk::Tetris {

class TetrisGame : public App {

public:
	TetrisGame(HINSTANCE hinstance)
		: App(hinstance) {
		GetECS()->GetSystemManager()->Add<ViewerSystem>(GetGraphics(), GetECS());
		GetECS()->GetSystemManager()->Add<BlockGeneratorSystem>();

		auto entity = GetECS()->GetEntityManager()->Add();
		entity->name = "gameField";
		auto gameFieldView = GetECS()->GetComponentManager()->Add<GameFieldView>(entity, 250, 12, 300, 570, 5, 10, 19, 30);

		entity = GetECS()->GetEntityManager()->Add();
		entity->name = "score";
		auto scoreView = GetECS()->GetComponentManager()->Add<ScoreView>(entity, 575, 75, 50, 0);

		entity = GetECS()->GetEntityManager()->Add();
		entity->name = "next";
		GetECS()->GetComponentManager()->Add<NextView>(entity, 625, 200, 100, 100, 4, 4, 25, 3);
	}
};

}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR, int) {
	Yaropolk::Tetris::TetrisGame game{ hinstance };
	game.Run();

	return 0;
}