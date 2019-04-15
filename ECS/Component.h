#pragma once

#include <typeinfo>

namespace Yaropolk::ECS {

struct Component {
	virtual ~Component()
	{

	}
};

template <typename T>
struct BaseComponent : Component {
	constexpr inline static size_t GetID() {
		return typeid(T).hash_code();
	}
};

}