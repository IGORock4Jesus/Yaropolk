#include "ECS.h"



ECS::ECS(std::vector<std::shared_ptr<ComponentManager>> componentManagers,
	std::vector < std::shared_ptr<System>> systems)
	: componentManagers{ std::move(componentManagers)}
{
	this->systemManager = std::make_shared<SystemManager>(systems);
}


ECS::~ECS()
{
}
