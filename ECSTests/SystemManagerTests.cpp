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
		bool Initialize(SystemManager* manager) override {
			return true;
		}
	};
	struct SystemB : System<SystemB>
	{
		bool Initialize(SystemManager* manager) override {
			return true;
		}
	};
	struct SystemC : System<SystemC>
	{
		bool Initialize(SystemManager* manager) override {
			return true;
		}
	};
	struct SystemFail : System<SystemC>
	{
		bool Initialize(SystemManager* manager) override {
			return false;
		}
	};

	TEST_METHOD(AddSystem) {
		SystemManager manager;
		auto a = manager.Add<SystemA>();

		Assert::IsNotNull(a.get(), L"������� �� �������.");
		Assert::AreEqual(SystemA::ID, a->ID, L"�� ������� �������.");
	}

	TEST_METHOD(Initializing) {
		SystemManager manager;
		auto c = manager.Add<SystemC>();
		auto b = manager.Add<SystemB>();
		auto a = manager.Add<SystemA>();

		manager.AddDependency(b, a);

		manager.AddDependency(c, a);
		manager.AddDependency(c, b);

		Assert::IsTrue(manager.Initialize(), L"�������� ������ �� ���������������.");
	}

	TEST_METHOD(Ordering) {
		SystemManager manager;
		auto c = manager.Add<SystemC>();
		auto b = manager.Add<SystemB>();
		auto a = manager.Add<SystemA>();

		manager.AddDependency(b, a);

		manager.AddDependency(c, a);
		manager.AddDependency(c, b);

		manager.Initialize();

		Assert::AreEqual(size_t(0), manager.GetIndex<SystemA>(), L"������� A ����� �������� ������.");
		Assert::AreEqual(size_t(1), manager.GetIndex<SystemB>(), L"������� B ����� �������� ������.");
		Assert::AreEqual(size_t(2), manager.GetIndex<SystemC>(), L"������� C ����� �������� ������.");
	}

	TEST_METHOD(FailInitialize_SystemFail) {
		SystemManager manager;
		auto c = manager.Add<SystemC>();
		auto fail = manager.Add<SystemFail>();
		auto a = manager.Add<SystemA>();

		manager.AddDependency(fail, a);

		manager.AddDependency(c, a);
		manager.AddDependency(c, fail);

		Assert::IsFalse(manager.Initialize(), L"�������� ������ ��������������� ���������, � �� ����� ��� SystemFail ��� ������������� ������� false.");
	}
};
}