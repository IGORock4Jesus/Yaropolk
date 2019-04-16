#pragma once

#include <typeinfo>

#include "ECS_API.h"



namespace Yaropolk::ECS {

using SystemID = size_t;

__interface ECS_API ISystem
{
	//bool GetEnable();
};

template <typename T>
struct System : ISystem {
	static const SystemID ID;
};


template <typename T>
const SystemID System<T>::ID = typeid(T).hash_code();

}


