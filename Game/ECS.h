#pragma once

#include <vector>
#include <memory>

#include "ComponentManager.h"
#include "SystemManager.h"
#include "EntityManager.h"

constexpr size_t MAX_ENTITIES = 100;

class ECS
{
	std::vector<std::shared_ptr<ComponentManager>> componentManagers;
	std::shared_ptr<SystemManager> systemManager;
	std::shared_ptr<EntityManager<MAX_ENTITIES>> entityManager;


public:
	ECS(std::vector<std::shared_ptr<ComponentManager>> componentManagers,
		std::vector<std::shared_ptr<System>> systems);
	~ECS();

	std::shared_ptr<SystemManager> GetSystemManager() const {
		return systemManager;
	}

	template <typename T>
	std::shared_ptr<T> GetComponentManager() const {
		for (auto&& m : componentManagers) {
			if (typeid(*m) == typeid(T)) {
				return std::dynamic_pointer_cast<T>(m);
			}
		}
		throw not_found("The ComponentManager of type of T is not found.");
	}

	std::shared_ptr<EntityManager<MAX_ENTITIES>> GetEntityManager() const { return entityManager; }
};

