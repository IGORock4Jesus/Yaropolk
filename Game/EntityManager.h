#pragma once

#include <bitset>
#include "Entity.h"

template <size_t N>
class EntityManager final {
	Entity entities[N];
	std::bitset<N> key;

public:
	EntityManager()
	{
		for (size_t i = 0; i < N; i++)
		{
			entities[i].SetId(i);
		}
	}
	Entity& Create() {
		if (key.all())
			throw std::out_of_range("There is not enough space for new Entity.");
		for (size_t i = 0; i < N; i++)
		{
			if (!key.test(i)) {
				key.set(i);
				entities[i].Clear();
				return entities[i];
			}
		}
		throw std::out_of_range("There is not enough space for new Entity.");
	}
	void Kill(Entity& entity) {
		key.reset(entity.GetId());
	}
};
