#include "pch.h"
#include "CppUnitTest.h"
#include "../RaytraycerCpp/Tuple.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestChapterOne)
	{
	public:
		
		TEST_METHOD(TestTuple1) {
			Tuple t1(4.3, -4.2, 3.1, 1);
			Assert::AreEqual(t1.x, 4.3);
			Assert::AreEqual(t1.y, -4.2);
			Assert::AreEqual(t1.z, 3.1);
			Assert::AreEqual(t1.w, 1.0);
			Assert::AreEqual(t1.IsItVector(), false);
		}

		TEST_METHOD(TestTuple2) {
			Tuple t1(4.3, -4.2, 3.1, 0.0);
			Assert::AreEqual(t1.x, 4.3);
			Assert::AreEqual(t1.y, -4.2);
			Assert::AreEqual(t1.z, 3.1);
			Assert::AreEqual(t1.w, 0.0);
			Assert::AreEqual(t1.IsItVector(), true);
		}

		TEST_METHOD(TestCreatePoint) {
			Tuple t1 = Tuple(4, -4, 3, 1);
			Tuple point = CreatePoint(4, -4, 3);
			Assert::IsTrue(t1 == point);
		}

		TEST_METHOD(TestCreateVector) {
			Tuple t1 = Tuple(4, -4, 3, 0);
			Tuple vector = CreateVector(4, -4, 3);
			Assert::IsTrue(t1 == vector);
		}

		TEST_METHOD(TestAdd) {
			Tuple t1 = Tuple(3, -2, 5, 1);
			Tuple t2 = Tuple(-2, 3, 1, 0);
			Assert::IsTrue(AddTuple(t1, t2) == Tuple(1, 1, 6, 1));
		}

		TEST_METHOD(TestSubtract) {
			Tuple point = CreatePoint(3, 2, 1);
			Tuple vector = CreateVector(5, 6, 7);
			Assert::IsTrue(SubtractTuple(point, vector) == CreatePoint(-2, -4, -6));
			Tuple vector1 = CreateVector(0, 0, 0);
			Tuple vector2 = CreateVector(1, -2, 3);
			Assert::IsTrue(SubtractTuple(vector1, vector2) == CreateVector(-1, 2, -3));
		}

		TEST_METHOD(TestNegate) {
			Tuple t1 = Tuple(1, -2, 3, -4);
			Assert::IsTrue(t1.Negate() == Tuple(-1, 2, -3, 4));
		}

		TEST_METHOD(TestMultiply) {
			Tuple t1 = Tuple(1, -2, 3, -4);
			Assert::IsTrue(MultiplyTuple(t1, 3.5) == Tuple(3.5, -7, 10.5, -14));
			Tuple t2 = Tuple(1, -2, 3, -4);
			Assert::IsTrue(MultiplyTuple(t2, 0.5) == Tuple(0.5, -1, 1.5, -2));
		}

		TEST_METHOD(TestDivide) {
			Tuple t1 = Tuple(1, -2, 3, -4);
			double scalar = 2;
			Assert::IsTrue(DivideTuple(t1, scalar) == Tuple(0.5, -1, 1.5, -2));
		}

		TEST_METHOD(TestMagnitude) {
			Tuple v1 = CreateVector(0, 1, 0);
			Assert::IsTrue(abs(Magnitude(v1) - 1) <= 0);
			Tuple v2 = CreateVector(0, 0, 1);
			Assert::IsTrue(abs(Magnitude(v2) - 1) <= 0);
			Tuple v3 = CreateVector(1, 2, 3);
			Assert::IsTrue(abs(Magnitude(v3) - sqrt(14)) <= 0);
			Tuple v4 = CreateVector(-1, -2, -3);
			Assert::IsTrue(abs(Magnitude(v4) - sqrt(14)) <= 0);
		}

		TEST_METHOD(TestNormalize) {
			Tuple v1 = CreateVector(4, 0, 0);
			Assert::IsTrue(Normalize(v1) == CreateVector(1, 0, 0));
			Tuple v2 = CreateVector(1, 2, 3);
			Assert::IsTrue(Normalize(v2) == CreateVector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
		}

		TEST_METHOD(TestDotProduct) {
			Tuple v1 = CreateVector(1, 2, 3);
			Tuple v2 = CreateVector(2, 3, 4);
			Assert::AreEqual(DotProduct(v1, v2), 20.0);
		}

		TEST_METHOD(TestCrossProduct) {
			Tuple v1 = CreateVector(1, 2, 3);
			Tuple v2 = CreateVector(2, 3, 4);
			Assert::IsTrue(CrossProduct(v1, v2) == CreateVector(-1, 2, -1));
			Assert::IsTrue(CrossProduct(v2, v1) == CreateVector(1, -2, 1));
		}
	};
}
