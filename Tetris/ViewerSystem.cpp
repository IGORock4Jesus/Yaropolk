#include "ViewerSystem.h"
#include <ECS/ComponentManager.h>
#include <Graphics/IRenderer.h>
#include "GameFieldView.h"
#include "ScoreView.h"
#include "NextView.h"


namespace Yaropolk::Tetris {
void ViewerSystem::Render(const std::shared_ptr<Graphics::IRenderer>& renderer)
{
	// draw the game field
	auto gameFields = engine->GetComponentManager()->GetList<GameFieldView>();
	for (auto&& gameField : gameFields) {
		// border
		renderer->DrawRectangle(gameField->x - gameField->border, gameField->y - gameField->border,
			gameField->width + gameField->border * 2, gameField->height + gameField->border * 2,
			0xff222222);
		// main 
		renderer->DrawRectangle(gameField->x, gameField->y, gameField->width, gameField->height, 0xff666666);

		const float a = 3.0f, b = 5.0f, c = 8.0f;

		// field cells
		for (size_t yi = 0; yi < gameField->verticalCount; yi++)
		{
			for (size_t xi = 0; xi < gameField->horizontalCount; xi++)
			{
				//gameField->map[yi][xi] = rand() % 2;

				renderer->DrawRectangle(
					gameField->x + xi * gameField->cellSize + a, gameField->y + yi * gameField->cellSize + a,
					gameField->cellSize - a * 2, gameField->cellSize - a * 2,
					gameField->map[yi][xi] ? 0xff050505 : 0xff8a8a8a);

				renderer->DrawRectangle(
					gameField->x + xi * gameField->cellSize + b, gameField->y + yi * gameField->cellSize + b,
					gameField->cellSize - b * 2, gameField->cellSize - b * 2,
					0xff666666);

				renderer->DrawRectangle(
					gameField->x + xi * gameField->cellSize + c, gameField->y + yi * gameField->cellSize + c,
					gameField->cellSize - c * 2, gameField->cellSize - c * 2,
					gameField->map[yi][xi] ? 0xff050505 : 0xff8a8a8a);
			}
		}
	}

	// draw the scores
	auto scoreViews = engine->GetComponentManager()->GetList<ScoreView>();
	for (auto&& scoreView : scoreViews)
	{
		// пишем SCORE
		renderer->DrawString(scoreView->x, scoreView->y, 200, 50,
			scoreView->fontSize, "SCORE", "DS-Digital", DT_CENTER | DT_VCENTER);

		// ниже пишем количество очков
		renderer->DrawString(scoreView->x, scoreView->y + scoreView->fontSize, 200, 50,
			scoreView->fontSize, std::to_string(scoreView->score), "DS-Digital", DT_CENTER | DT_VCENTER);

	}

	// draw the next field
	auto nextFields = engine->GetComponentManager()->GetList<NextView>();
	for (auto&& nextField : nextFields) {
		// border
		renderer->DrawRectangle(nextField->x - nextField->border, nextField->y - nextField->border,
			nextField->width + nextField->border * 2, nextField->height + nextField->border * 2,
			0xff222222);
		// main 
		renderer->DrawRectangle(nextField->x, nextField->y, nextField->width, nextField->height, 0xff666666);

		const float a = 3.0f, b = 5.0f, c = 7.0f;

		// field cells
		for (size_t yi = 0; yi < nextField->vertical; yi++)
		{
			for (size_t xi = 0; xi < nextField->horizontal; xi++)
			{
				//nextField->map[yi][xi] = rand() % 2;

				renderer->DrawRectangle(
					nextField->x + xi * nextField->cellSize + a, nextField->y + yi * nextField->cellSize + a,
					nextField->cellSize - a * 2, nextField->cellSize - a * 2,
					nextField->map[yi][xi] ? 0xff050505 : 0xff8a8a8a);

				renderer->DrawRectangle(
					nextField->x + xi * nextField->cellSize + b, nextField->y + yi * nextField->cellSize + b,
					nextField->cellSize - b * 2, nextField->cellSize - b * 2,
					0xff666666);

				renderer->DrawRectangle(
					nextField->x + xi * nextField->cellSize + c, nextField->y + yi * nextField->cellSize + c,
					nextField->cellSize - c * 2, nextField->cellSize - c * 2,
					nextField->map[yi][xi] ? 0xff050505 : 0xff8a8a8a);
			}
		}
	}
}
ViewerSystem::ViewerSystem(const std::shared_ptr<Graphics::Engine>& engine, const std::shared_ptr<ECS::Engine>& ecs)
	:engine{ ecs }
{
	engine->Rendering.Add(this, &ViewerSystem::Render);

	AddFontResourceEx("DS-DIGI.ttf", FR_PRIVATE, 0);
}


ViewerSystem::~ViewerSystem()
{
	RemoveFontResource("DS-DIGI.ttf");
}

bool ViewerSystem::Initialize(ECS::SystemManager* manager)
{
	return true;
}

}