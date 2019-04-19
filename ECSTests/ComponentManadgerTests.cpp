#include "pch.h"
#include "CppUnitTest.h"
#include <EntityManager.h>
#include <ComponentManager.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
TEST_CLASS(ComponentManagerTests)
{
public:
	struct Position : Component<Position>
	{
		float x, y;
		Position(float x, float y) : x{ x }, y{ y }{}
	};
	struct Gravity : Component<Gravity>
	{
		float power;
	};

	// Проверка при добавлении.
	TEST_METHOD(AddOne)
	{
		EntityManager entityManager;
		ComponentManager componentManager;

		auto entity = entityManager.Add();

		auto expectedX = 10.0f;
		auto expectedY = 4.8f;

		auto position = componentManager.Add<Position>(entity, expectedX, expectedY);

		position = componentManager.Get<Position>(entity);

		Assert::IsNotNull(position.get(), L"Компонент не был добавлен.");
		Assert::AreEqual(expectedX, position->x, L"Компонент создан некорректно.");
		Assert::AreEqual(expectedY, position->y, L"Компонент создан некорректно.");
	}

	// Проверка на удаление
	TEST_METHOD(Remove) {
		EntityManager entityManager;
		ComponentManager componentManager;

		auto entity = entityManager.Add();

		auto expectedX = 10.0f;
		auto expectedY = 4.8f;

		auto position = componentManager.Add<Position>(entity, expectedX, expectedY);

		componentManager.Remove<Position>(entity);

		position = componentManager.Get<Position>(entity);

		Assert::IsNull(position.get(), L"Компонент не был удален.");
	}

	// Полная очистка компонентов
	TEST_METHOD(AllClear) {
		EntityManager entityManager;
		ComponentManager componentManager;

		auto entity = entityManager.Add();

		auto expectedX = 10.0f;
		auto expectedY = 4.8f;

		auto position = componentManager.Add<Position>(entity, expectedX, expectedY);

		componentManager.Clear();

		position = componentManager.Get<Position>(entity);

		Assert::IsNull(position.get(), L"Компонент не был удален.");
	}

	// Полная очистка компонентов
	TEST_METHOD(ClearForEntity) {
		EntityManager entityManager;
		ComponentManager componentManager;

		auto entity = entityManager.Add();

		auto expectedX = 10.0f;
		auto expectedY = 4.8f;

		auto position = componentManager.Add<Position>(entity, expectedX, expectedY);

		componentManager.Clear(entity);

		position = componentManager.Get<Position>(entity);

		Assert::IsNull(position.get(), L"Компонент не был удален.");
	}

	// Получение по типу
	TEST_METHOD(GetByType) {
		EntityManager entityManager;
		ComponentManager componentManager;

		auto entity = entityManager.Add();

		auto expectedX = 10.0f;
		auto expectedY = 4.8f;

		auto position = componentManager.Add<Position>(entity, expectedX, expectedY);

		auto gravity = componentManager.Add<Gravity>(entity);

		position = componentManager.Get<Position>(entity);
		gravity = componentManager.Get<Gravity>(entity);

		Assert::IsNotNull(position.get(), L"Компонент Position не получен от менеджера.");
		Assert::IsNotNull(gravity.get(), L"Компонент Gravity не получен от менеджера.");
	}
};

}