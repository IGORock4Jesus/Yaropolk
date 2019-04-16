#include "pch.h"
#include "CppUnitTest.h"
#include <EntityManager.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
	TEST_CLASS(EntityManagerTests)
	{
	public:
		
		// Проверка на изначально пустой контейнер.
		TEST_METHOD(Empty)
		{
			EntityManager entityMnagaer;

			Assert::AreEqual((size_t)0, entityMnagaer.GetSize(), L"Менеджер сущностей изначально должен быть пустым.");
		}

		// Проверяем добавление сущности.
		TEST_METHOD(CreateOne) {
			EntityManager manager;

			auto entity = manager.Add();

			Assert::AreEqual((size_t)1, manager.GetSize(), L"После создания сущности, количество не изменилось.");
		}

		// Проверяем удаление сущности.
		TEST_METHOD(RemoveOne) {

			EntityManager manager;

			auto entity = manager.Add();

			Assert::AreEqual((size_t)1, manager.GetSize(), L"После создания сущности, количество не изменилось.");

			manager.Remove(entity);
					   
			Assert::AreEqual((size_t)0, manager.GetSize(), L"После удаления сущности, количество не изменилось.");
		}
	};
}
