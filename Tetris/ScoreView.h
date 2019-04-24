#pragma once

#include <string>
#include <ECS/Component.h>


namespace Yaropolk::Tetris {


struct ScoreView : ECS::Component<ScoreView>
{
	float x, y; // позиция
	int fontSize; // размер шрифта
	int score; // очки

	ScoreView(float x, float y, int fontSize, int score)
		: x{ x }, y{ y }, fontSize{ fontSize }, score{ score }
	{

	}
};

}