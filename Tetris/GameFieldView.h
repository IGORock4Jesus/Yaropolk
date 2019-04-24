#pragma once

#include <vector>
#include <ECS/Component.h>


namespace Yaropolk::Tetris {

struct GameFieldView : ECS::Component<GameFieldView>
{
	float x, y;
	float width, height;
	float border;
	int horizontalCount, verticalCount;
	float cellSize;
	std::vector<std::vector<bool>> map; // карта


	GameFieldView(float x, float y, float w, float h, float border, int hor, int ver, float cellSize)
		: x{ x }, y{ y }, width{ w }, height{ h }, border{ border }, horizontalCount{ hor }, verticalCount{ ver },
		  cellSize{ cellSize }
	{
		map.resize(verticalCount);
		for (size_t i = 0; i < verticalCount; i++)
		{
			map[i].resize(horizontalCount);
			for (size_t j = 0; j < horizontalCount; j++)
			{
				map[i][j] = false;
			}
		}
	}
};

}