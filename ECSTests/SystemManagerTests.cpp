#include "pch.h"
#include "CppUnitTest.h"
#include <SystemManager.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
TEST_CLASS(SystemManagerTests)
{
public:
	struct SystemA : System<SystemA>
	{

	};
	struct SystemB : System<SystemB>
	{

	};

	TEST_METHOD(AddSystem) {
		SystemManager manager;
		auto a = manager.Add<SystemA>();

		Assert::IsNotNull(a.get(), L"Система не создана.");
		Assert::AreEqual(SystemA::ID, a->ID, L"ИД системы неверен.");
	}

	TEST_METHOD(CheckOrdering) {
		SystemManager manager;
		auto b = manager.Add<SystemB>();
		auto a = manager.Add<SystemA>();

		manager.AddDependency(b, a);

		Assert::Fail(L"Данный тест не имеет проверки.");
	}
};
}