#pragma once

#include <memory>

#include <ECS/System.h>

#include "Block.h"

namespace Yaropolk::Tetris
{

class BlockGeneratorSystem : public ECS::System<BlockGeneratorSystem>
{
public:
	BlockGeneratorSystem();

	std::shared_ptr<Block> Next();
};

}