#include "stdafx.h"
#include "CppUnitTest.h"
#include <EntityManager.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(EntityManagerTests)
	{
	public:

		TEST_METHOD(CreateNormal)
		{
			try {
				EntityManager<2> manager;
				auto e1 = manager.Create();
				auto e2 = manager.Create();
			}
			catch (std::out_of_range ex) {
				Assert::Fail(L"out og range");
			}
		}

		TEST_METHOD(CreateWithOutOfRange) {
			try
			{
				EntityManager<2> manager;
				auto e1 = manager.Create();
				auto e2 = manager.Create();
				auto e3 = manager.Create();
				Assert::Fail(L"The EntityManager has to throw an out_of_range exception.");

			}
			catch (const std::out_of_range&)
			{

			}
		}
	};
}