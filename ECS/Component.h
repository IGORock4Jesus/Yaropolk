#pragma once

#include <typeinfo>
#include "EcsAPI.h"

namespace Yaropolk::ECS {

using ComponentID = size_t;

struct ECS_API IComponent
{
	virtual ~IComponent() {}
};

template <typename T>
struct Component : IComponent {
	static const ComponentID ID;

};

template <typename T>
const ComponentID Component<T>::ID = typeid(T).hash_code();

}