#pragma once

#include <list>
#include <memory>
#include "Component.h"


class ComponentManager {
};

template <typename T>
class BaseComponentManager : public ComponentManager {
	std::list<std::shared_ptr<T>> components;

public:
	std::shared_ptr<T> Create(const Entity& entity) {
		auto c = std::make_shared<T>(entity);
		//c->Initialize();
		components.push_back(c);
		return c;
	}

	void Remove(std::shared_ptr<T> c) {
		components.remove(c);
	}

	const std::list<std::shared_ptr<T>>& GetArray() {
		return components;
	}
};