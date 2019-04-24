#include "pch.h"
#include "CppUnitTest.h"
#include <ECS/Engine.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
TEST_CLASS(EngineTests)
{
public:
	TEST_METHOD(Construct) {
		Engine engine;

		Assert::IsNotNull(engine.GetComponentManager().get(), L"Менеджер компонентов не создан.");
		Assert::IsNotNull(engine.GetEntityManager().get(), L"Менеджер сущностей не создан.");
		Assert::IsNotNull(engine.GetSystemManager().get(), L"Менеджер систем не создан.");
	}
};
}