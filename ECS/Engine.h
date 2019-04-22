#pragma once

#include <memory>
#include <vector>

#include "EcsAPI.h"

namespace Yaropolk::ECS {

__interface ISystem;
class ComponentManager;
class EntityManager;
class SystemManager;

// Движок компонент
class ECS_API Engine
{
	std::shared_ptr<ComponentManager> componentManager;
	std::shared_ptr<EntityManager> entityManager;
	std::shared_ptr<SystemManager> systemManager;

public:
	Engine();
	~Engine();

	std::shared_ptr<ComponentManager> GetComponentManager() const { return componentManager; }
	std::shared_ptr<EntityManager> GetEntityManager() const { return entityManager; }
	std::shared_ptr<SystemManager> GetSystemManager() const { return systemManager; }

	void Start();
	void Stop();
};

}