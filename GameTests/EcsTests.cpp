#include "stdafx.h"
#include "CppUnitTest.h"
#include <Component.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(ECSTests)
	{
	public:

		TEST_METHOD(GetUniqueComponentID_Normal)
		{
			auto a = ecs::GetUniqueComponentID();
			auto b = ecs::GetUniqueComponentID();

			Assert::AreEqual((ComponentID)0, a, L"Wrong ComponentID.");
			Assert::AreEqual((ComponentID)1, b, L"Wrong ComponentID.");
		}

		/*TEST_METHOD(GetUniqueComponentID_GetNext) {
			auto a = ecs::GetUniqueComponentID();
			auto b = ecs::GetUniqueComponentID();

			Assert::AreEqual(a + 1, b, L"The ComponentIDs don\'t be as equal.");
		}*/

		TEST_METHOD(GetComponentID_Normal) {
			struct A : BaseComponent<A> {};
			struct B : BaseComponent<B> {};

			auto a = ecs::GetComponentID<A>();
			auto b = ecs::GetComponentID<B>();

			Assert::AreEqual((ComponentID)0, a, L"Wrong a ComponentID.");
			Assert::AreEqual((ComponentID)1, b, L"Wrong b ComponentID.");
		}
	};
}