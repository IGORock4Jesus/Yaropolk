#pragma once

#include <vector>
#include <ECS/Component.h>

namespace Yaropolk::Tetris
{

enum class BlockType
{
	L, 
	R, // L - reverse
	T, // 3x1 + center x 2
	I, // 4x1
	O, // 2x2
	Z, // 2x1 + 2x1
	Zr, // 2x1 + 2x1 Z - reverse
	_Count // количество элементов
};

enum class Orientation
{
	N, E, S, W,
	_Count
};

struct Block : ECS::Component<Block>
{
	BlockType type;
	std::vector<std::vector<bool>> map;
	Orientation orientation;

	Block()
	{
		map.resize(4);
		for (size_t i = 0; i < 4; i++)
		{
			map[i].resize(4);
		}
	}
};

}