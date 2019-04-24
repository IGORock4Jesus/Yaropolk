#pragma once

#include <memory>
#include <list>
//#include <bitset>

#include "EcsAPI.h"
#include "Entity.h"

namespace Yaropolk::ECS {

//using EntityID = size_t;

// Менеджер сущностей.
class ECS_API EntityManager
{
	// сущности
	std::list<std::shared_ptr<Entity>> entities;

public:
	// Конструктор
	EntityManager();
	// Деструктор
	~EntityManager();

	// возвращает колиество используемых объектов
	size_t GetSize() const;

	// добавляет сущность и возвращает его
	std::shared_ptr<Entity> Add();

	// удаляет сущность по
	void Remove(std::shared_ptr<Entity> entity);

	// поиск по имени
	std::shared_ptr<Entity> Find(std::string name);
};

}