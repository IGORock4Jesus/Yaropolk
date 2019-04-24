#pragma once

#include <vector>
#include <map>
#include <memory>

#include "EcsAPI.h"
#include "Component.h"


namespace Yaropolk::ECS {

struct Entity;

class ECS_API ComponentManager
{
	// карта сущность-компонент
	std::map<std::shared_ptr<Entity>, std::map<ComponentID, std::shared_ptr<IComponent>>> components;

public:
	ComponentManager();
	~ComponentManager();

	// Создает и добавляет компонент к сущности.
	template <typename T, typename... TArgs>
	std::shared_ptr<T> Add(std::shared_ptr<Entity> entity, TArgs&&... args) {
		auto component = std::make_shared<T>(std::forward<TArgs>(args)...);
		auto& ec = components[entity];
		ec[Component<T>::ID] = component;
		return component;
	}

	// Удаляет компонент от сущности.
	template <typename T>
	void Remove(std::shared_ptr<Entity> entity) {
		Remove(entity, T::ID);
	}
	void Remove(std::shared_ptr<Entity> entity, ComponentID componentId);

	void Clear(std::shared_ptr<Entity> entity);

	void Clear();

	template <typename T>
	std::shared_ptr<T> Get(std::shared_ptr<Entity> entity) {
		return std::dynamic_pointer_cast<T>(Get(entity, T::ID));
	}
	std::shared_ptr<IComponent> Get(std::shared_ptr<Entity> entity, ComponentID componentId);

	template <typename T>
	std::vector<std::shared_ptr<T>> GetList() {
		std::vector<std::shared_ptr<T>> result;

		for (auto&& e : components) {
			auto c = Get<T>(e.first);
			if (c) {
				result.push_back(c);
			}
		}

		return std::move(result);
	}
	std::vector<std::shared_ptr<IComponent>> GetList(ComponentID componentID);
};

}