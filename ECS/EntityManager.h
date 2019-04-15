#pragma once

#include <memory>
#include <vector>

#include "ECS_API.h"
#include "Entity.h"

namespace Yaropolk::ECS {

//using EntityID = size_t;

class ECS_API EntityManager
{
	std::vector<Entity> entities;

public:
	EntityManager();
	~EntityManager();

	// возвращает колиество используемых объектов
	size_t GetSize() const;

	// добавляет сущность и возвращает его ид
	size_t Add();

	// удаляет сущность по ид
	void Remove(size_t id);
};

}