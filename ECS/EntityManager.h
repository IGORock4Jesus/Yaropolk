#pragma once

#include <memory>
#include <list>
//#include <bitset>

#include "EcsAPI.h"
#include "Entity.h"

namespace Yaropolk::ECS {

//using EntityID = size_t;

// �������� ���������.
class ECS_API EntityManager
{
	// ��������
	std::list<std::shared_ptr<Entity>> entities;

public:
	// �����������
	EntityManager();
	// ����������
	~EntityManager();

	// ���������� ��������� ������������ ��������
	size_t GetSize() const;

	// ��������� �������� � ���������� ���
	std::shared_ptr<Entity> Add();

	// ������� �������� ��
	void Remove(std::shared_ptr<Entity> entity);

	// ����� �� �����
	std::shared_ptr<Entity> Find(std::string name);
};

}