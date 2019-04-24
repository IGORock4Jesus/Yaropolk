#include "pch.h"
#include "CppUnitTest.h"
#include "..\Trivial\Event.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::Trivial::Tests
{
	TEST_CLASS(EventTests)
	{
		void PrivateCallbackReturn6(int& v) {
			v = 6;
		}
	public:
		void CallbackReturn4(int& v) {
			v = 4;
		}

		TEST_METHOD(Checking)
		{
			Event<int&> getValue;
			int val = 0;

			getValue.Add(this, &EventTests::CallbackReturn4);

			getValue(val);

			Assert::AreEqual(val, 4, L"Событие работает неверно.");
		}

		TEST_METHOD(PrivateCallback)
		{
			Event<int&> getValue;
			int val = 0;

			getValue.Add(this, &EventTests::PrivateCallbackReturn6);

			getValue(val);

			Assert::AreEqual(val, 6, L"Событие работает неверно.");
		}
	};
}
