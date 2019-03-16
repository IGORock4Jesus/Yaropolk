#pragma once

#include <memory>
#include <bitset>
#include <Windows.h>
#include "System.h"

constexpr size_t SYSTEM_COUNT = 32;

class SystemManager final {
	std::shared_ptr<System> systems[SYSTEM_COUNT]{
		// добавить конструкторы систем
	};
	std::bitset<SYSTEM_COUNT> key;

public:
	template <typename T>
	std::shared_ptr<T> Get() {
		static_assert(std::is_base_of_v<System, T>, "The T must be inheritance of the System.");
		for (auto&& s : systems) {
			if (s->GetID() == ecs::GetSystemID<T>())
				return std::dynamic_pointer_cast<T>(s);
		}
	}
};