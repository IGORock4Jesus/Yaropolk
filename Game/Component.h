#pragma once

#include <string>

class Entity;
using ComponentID = size_t;

struct Component {
	ComponentID id;
	Entity* object;

public:
	Component(ComponentID id)
		: id{ id } {}
};

namespace ecs {
	inline ComponentID GetUniqueComponentID() {
		static ComponentID id{ (ComponentID)0 };
		return id++;
	}
	template <typename T>
	inline ComponentID GetComponentID() {
		static ComponentID id = GetUniqueComponentID();
		return id;
	}
}

template <typename T>
struct BaseComponent : Component
{
	BaseComponent()
		: Component(ecs::GetComponentID<T>())
	{

	}
};