#include "InputSystem.h"
#include <ECS/SystemManager.h>
#include <ECS/ComponentManager.h>
#include <ECS/EntityManager.h>

#include "BlockGeneratorSystem.h"
#include "ViewerSystem.h"
#include "NextView.h"


namespace Yaropolk::Tetris {
void InputSystem::KeyDown(int key)
{
	switch (key)
	{
	case VK_SPACE: {
		auto block = ecs->GetSystemManager()->Get<BlockGeneratorSystem>()->Next();

		auto next = ecs->GetEntityManager()->Find("next");
		auto nextView = ecs->GetComponentManager()->Get<NextView>(next);

		nextView->map = block->map;

		break;
	}
	default:
		break;
	}
	
}
InputSystem::InputSystem(std::shared_ptr<ECS::Engine> ecs, std::shared_ptr<Subsystem::Window> window)
	: ecs{ ecs }
{
	window->KeyDown.Add(this, &InputSystem::KeyDown);
}

}