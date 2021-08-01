#include "pch.h"
#include "CppUnitTest.h"
#include "../RaytraycerCpp/Tuple.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestChapterOne)
	{
	public:
		
		TEST_METHOD(TestTuple1)
		{
			Tuple t1(4.3, -4.2, 3.1, 1.0);
			Assert::AreEqual(t1.x, 4.3);
			Assert::AreEqual(t1.y, -4.2);
			Assert::AreEqual(t1.z, 3.1);
			Assert::AreEqual(t1.w, 1);
			Assert::AreEqual(t1.IsItVector(), false);
		}

		TEST_METHOD(TestTuple2)
		{
			Tuple t1(4.3, -4.2, 3.1, 0.0);
			Assert::AreEqual(t1.x, 4.3);
			Assert::AreEqual(t1.y, -4.2);
			Assert::AreEqual(t1.z, 3.1);
			Assert::AreEqual(t1.w, 0);
			Assert::AreEqual(t1.IsItVector(), true);
		}

		TEST_METHOD(TestCreatePoint)
		{
			Tuple t1 = Tuple(4, -4, 3, 1);
			Tuple point = CreatePoint(4, -4, 3);
			Assert::IsTrue(t1 == point);
		}

		TEST_METHOD(TestCreateVector)
		{
			Tuple t1 = Tuple(4, -4, 3, 0);
			Tuple vector = CreateVector(4, -4, 3);
			Assert::IsTrue(t1 == vector);
		}
	};
}
