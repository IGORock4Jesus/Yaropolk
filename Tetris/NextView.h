#pragma once

#include <vector>
#include <ECS/Component.h>

namespace Yaropolk::Tetris {


struct NextView : ECS::Component<NextView>
{
	float x, y; // позици€
	float width, height; // размер
	int horizontal, vertical; // количество €чеек
	float cellSize; // размер €чейки
	float border;
	std::vector<std::vector<bool>> map;

	NextView(float x, float y, float w, float h, int hor, int ver, float cellSize,float border)
		: x{ x }, y{ y }, width{ w }, height{ h }, horizontal{ hor }, vertical{ ver }, cellSize{ cellSize }, border{ border }
	{
		map.resize(vertical);
		for (size_t i = 0; i < vertical; i++)
		{
			map[i].resize(horizontal);
			for (size_t j = 0; j < horizontal; j++)
			{
				map[i][j] = false;
			}
		}
	}
};

}