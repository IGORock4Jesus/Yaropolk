#include "Engine.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"


namespace Yaropolk::ECS {

Engine::Engine()
{
	componentManager = std::make_shared<ComponentManager>();
	entityManager = std::make_shared<EntityManager>();
	systemManager = std::make_shared<SystemManager>();
}


Engine::~Engine()
{
}

bool Engine::Start()
{
	if (!systemManager->Initialize())
		return false;

	return systemManager->Start();
}

void Engine::Stop()
{
	systemManager->Stop();
}

}