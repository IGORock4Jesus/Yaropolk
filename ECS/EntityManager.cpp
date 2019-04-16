#include "EntityManager.h"


namespace Yaropolk::ECS {

EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

size_t EntityManager::GetSize() const
{
	return entities.size();
}

std::shared_ptr<Entity> EntityManager::Add()
{
	auto p = std::make_shared<Entity>();
	entities.push_back(p);
	return p;
}

void EntityManager::Remove(std::shared_ptr<Entity> entity)
{
	entities.remove(entity);
}

}