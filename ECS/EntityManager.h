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

	// ���������� ��������� ������������ ��������
	size_t GetSize() const;

	// ��������� �������� � ���������� ��� ��
	size_t Add();

	// ������� �������� �� ��
	void Remove(size_t id);
};

}