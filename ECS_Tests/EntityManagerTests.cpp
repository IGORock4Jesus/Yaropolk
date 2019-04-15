#include "pch.h"
#include "CppUnitTest.h"
#include <EntityManager.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
	TEST_CLASS(EntityManagerTests)
	{
	public:
		
		TEST_METHOD(EmptyTests)
		{
			EntityManager entityMnagaer;

			Assert::AreEqual((size_t)0, entityMnagaer.GetSize(), L"Менеджер сущностей изначально должен быть пустым.");
		}
	};
}
