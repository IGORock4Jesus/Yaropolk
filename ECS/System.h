#pragma once

#include <typeinfo>

#include "EcsAPI.h"



namespace Yaropolk::ECS {

using SystemID = size_t;

class SystemManager;

__interface ECS_API ISystem
{
	//bool GetEnable();
	bool Initialize(SystemManager* manager);
	const SystemID GetID() const;
};

template <typename T>
struct System : ISystem {
	static const SystemID ID;
	const SystemID GetID() const override {
		return ID;
	}
};


template <typename T>
const SystemID System<T>::ID = typeid(T).hash_code();

}


