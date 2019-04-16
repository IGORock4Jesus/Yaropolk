#include "ComponentManager.h"


namespace Yaropolk::ECS {


ComponentManager::ComponentManager()
{
}


ComponentManager::~ComponentManager()
{
}

void ComponentManager::Remove(std::shared_ptr<Entity> entity, ComponentID componentId)
{
	auto& ec = components.at(entity);
	ec.erase(componentId);
}

void ComponentManager::Clear(std::shared_ptr<Entity> entity)
{
	auto& e = components.at(entity);
	e.clear();
}

void ComponentManager::Clear()
{
	components.clear();
}

std::shared_ptr<IComponent> ComponentManager::Get(std::shared_ptr<Entity> entity, ComponentID componentId)
{
	auto ec = components[entity];
	if (ec.find(componentId) != ec.end())
		return ec.at(componentId);
	else
		return nullptr;
}

}