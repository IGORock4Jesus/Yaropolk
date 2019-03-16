#pragma once

#include "Component.h"

using SystemID = size_t;

namespace ecs {
	inline SystemID GetUniqueSystemID() {
		static SystemID id{ 0 };
		return id++;
	}
	template <typename T>
	inline SystemID GetSystemID() {
		static SystemID id = GetUniqueSystemID();
		return id;
	}
}

class System {
	const SystemID id;
public:
	System(SystemID id)
		: id{id}
	{

	}
	SystemID GetID() const { return id; }
};
template <typename T>
class BaseSystem : public System {
public:
	BaseSystem()
		: System(ecs::GetSystemID<T>())
	{

	}
};

