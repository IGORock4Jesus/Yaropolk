#pragma once

#include <bitset>
#include <array>
#include <memory>
#include <d3d9.h>
#include "Component.h"

constexpr size_t MAX_COMPONENTS = 32;

class Entity final
{
	std::bitset<MAX_COMPONENTS> key;
	std::array<Component*, MAX_COMPONENTS> components;
	std::string name;
	size_t id;

public:
	virtual ~Entity()
	{

	}
	const std::string GetName() const { return name; }
	void SetName(const std::string& newName) { name = newName; }
	void SetId(size_t newId) { id = newId; }
	size_t GetId() const { return id; }

	virtual void Update(float time) {}
	virtual void Render(LPDIRECT3DDEVICE9 device) {}

#pragma region ECS
	void Clear() {
		key.reset();
	}
	template <typename T>
	void Add(T& t) {
		static_assert(std::is_base_of_v<Component, T>, "The T must be inheritance of the Component.");
		
	}
#pragma endregion

};