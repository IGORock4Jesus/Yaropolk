#pragma once

#include <ECS/System.h>
#include <Graphics/Engine.h>
#include <ECS/Engine.h>

namespace Yaropolk::Tetris {

class ViewerSystem : public ECS::System<ViewerSystem>
{
	const std::shared_ptr<ECS::Engine>& engine;


	void Render(const std::shared_ptr<Graphics::IRenderer>& renderer);

public:
	ViewerSystem(const std::shared_ptr<Graphics::Engine>& engine, const std::shared_ptr<ECS::Engine>& ecs);
	~ViewerSystem();

	// Унаследовано через System
	virtual bool Initialize(ECS::SystemManager* manager) override;
};

}