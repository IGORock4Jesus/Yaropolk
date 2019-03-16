#include "stdafx.h"
#include "CppUnitTest.h"
#include <SystemManager.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(SystemManagerTests)
	{
		class NameSystem : public System{};
		class PointSystem : public System{};

	public:
		TEST_METHOD(Get_IsNotNull) {
			auto ns = std::make_shared<NameSystem>();
			auto ps = std::make_shared<PointSystem>();

			SystemManager manager{ {
				ns,
				ps
			} };

			auto nameSystem = manager.Get<NameSystem>();
			auto pointSystem = manager.Get<PointSystem>();

			Assert::IsNotNull(nameSystem.get());
			Assert::IsNotNull(pointSystem.get());

			/*Assert::AreSame((*ns), (*nameSystem), L"Name System is wrong.");
			Assert::AreSame((*ps), (*pointSystem), L"Point System is wrong.");*/
		}
	};

}
