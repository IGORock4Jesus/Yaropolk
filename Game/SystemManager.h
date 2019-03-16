#pragma once

#include <memory>
#include <bitset>
#include <vector>
#include <exception>
#include <Windows.h>
#include "System.h"

constexpr size_t SYSTEM_COUNT = 32;
struct not_found : std::exception {
	not_found(const char* message)
		: std::exception(message) {}
};

class SystemManager final {
	std::vector<std::shared_ptr<System>> systems;
	//std::bitset<SYSTEM_COUNT> key;

public:
	SystemManager(const std::vector<std::shared_ptr<System>>& systems)
		:systems{ std::move(systems) }
	{
		for (auto && s : systems) {
			if (!s)
				throw std::exception("System cannot to be nullptr.");
		}
	}
	template <typename T>
	std::shared_ptr<T> Get() {
		static_assert(std::is_base_of_v<System, T>, "The T must be inheritance of the System.");
		for (auto&& s : systems) {
			if (typeid(*s) == typeid(T))
				return std::dynamic_pointer_cast<T>(s);
		}
		throw not_found("The T system is not found in this manager.");
	}
};