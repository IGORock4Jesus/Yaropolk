#include "pch.h"
#include "CppUnitTest.h"
#include <Component.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
TEST_CLASS(ComponentTests)
{
	struct Transform : Component<Transform>
	{
		int x, y;
	};

	struct Gravity : Component<Gravity>
	{
		float power;
	};

public:

	// ѕроверка на изначально пустой контейнер.
	TEST_METHOD(CheckIDs)
	{
		Transform transform;
		Gravity gravity;

		Assert::AreEqual(typeid(Transform).hash_code(), transform.ID, L"Transform ID is not correct.");
		Assert::AreEqual(typeid(Gravity).hash_code(), gravity.ID, L"Gravity ID is not correct.");
	}
};
}