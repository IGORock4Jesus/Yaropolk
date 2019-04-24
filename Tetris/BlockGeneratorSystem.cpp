#include "BlockGeneratorSystem.h"
#include <Windows.h>


namespace Yaropolk::Tetris {

BlockGeneratorSystem::BlockGeneratorSystem()
{
	srand(timeGetTime());
}

std::shared_ptr<Block> BlockGeneratorSystem::Next()
{
	int count = (int)BlockType::_Count;
	count = 1;
	int r = rand() % count;
	BlockType type = (BlockType)r;

	auto block = std::make_shared<Block>();
	block->type = type;
	
	count = (int)Orientation::_Count;
	r = rand() % count;
	Orientation orientation = (Orientation)r;
	block->orientation = orientation;


	switch (type)
	{
	case BlockType::L:
		switch (orientation)
		{
		case Orientation::N:
			block->map[0][0] = block->map[1][0] = block->map[2][0] = block->map[2][1] = true;
			break;
		case Orientation::E:
			block->map[1][0] = block->map[0][0] = block->map[0][1] = block->map[0][2] = true;
			break;
		case Orientation::S:
			block->map[0][0] = block->map[0][1] = block->map[1][1] = block->map[2][1] = true;
			break;
		case Orientation::W:
			block->map[1][0] = block->map[1][1] = block->map[1][2] = block->map[0][2] = true;
			break;
		}
		break;
	case BlockType::R:
		break;
	case BlockType::T:
		break;
	case BlockType::I:
		break;
	case BlockType::O:
		break;
	case BlockType::Z:
		break;
	}

	return block;

}

}