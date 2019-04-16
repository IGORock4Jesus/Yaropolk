#include "pch.h"
#include "CppUnitTest.h"
#include <EntityManager.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Yaropolk::ECS::ECSTests
{
	TEST_CLASS(EntityManagerTests)
	{
	public:
		
		// �������� �� ���������� ������ ���������.
		TEST_METHOD(Empty)
		{
			EntityManager entityMnagaer;

			Assert::AreEqual((size_t)0, entityMnagaer.GetSize(), L"�������� ��������� ���������� ������ ���� ������.");
		}

		// ��������� ���������� ��������.
		TEST_METHOD(CreateOne) {
			EntityManager manager;

			auto entity = manager.Add();

			Assert::AreEqual((size_t)1, manager.GetSize(), L"����� �������� ��������, ���������� �� ����������.");
		}

		// ��������� �������� ��������.
		TEST_METHOD(RemoveOne) {

			EntityManager manager;

			auto entity = manager.Add();

			Assert::AreEqual((size_t)1, manager.GetSize(), L"����� �������� ��������, ���������� �� ����������.");

			manager.Remove(entity);
					   
			Assert::AreEqual((size_t)0, manager.GetSize(), L"����� �������� ��������, ���������� �� ����������.");
		}
	};
}
