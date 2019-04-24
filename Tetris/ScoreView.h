#pragma once

#include <string>
#include <ECS/Component.h>


namespace Yaropolk::Tetris {


struct ScoreView : ECS::Component<ScoreView>
{
	float x, y; // �������
	int fontSize; // ������ ������
	int score; // ����

	ScoreView(float x, float y, int fontSize, int score)
		: x{ x }, y{ y }, fontSize{ fontSize }, score{ score }
	{

	}
};

}