#include "pch.h"
#include "CppUnitTest.h"
#include "../RaytraycerCpp/Tuple.cpp"
#include "../RaytraycerCpp/Tuple.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestChapter1)
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
			Tuple p1 = Point(4, -4, 3);
			Assert::IsTrue(t1 == p1);
		}

		TEST_METHOD(TestCreateVector) {
			Tuple t1 = Tuple(4, -4, 3, 0);
			Tuple v1 = Vector(4, -4, 3);
			Assert::IsTrue(t1 == v1);
		}

		TEST_METHOD(TestAdd) {
			Tuple t1 = Tuple(3, -2, 5, 1);
			Tuple t2 = Tuple(-2, 3, 1, 0);
			Assert::IsTrue(t1 + t2 == Tuple(1, 1, 6, 1));
		}

		TEST_METHOD(TestSubtract) {
			Tuple p = Point(3, 2, 1);
			Tuple v = Vector(5, 6, 7);
			Assert::IsTrue(p - v == Point(-2, -4, -6));
			Tuple v1 = Vector(0, 0, 0);
			Tuple v2 = Vector(1, -2, 3);
			Assert::IsTrue(v1 - v2 == Vector(-1, 2, -3));
		}

		TEST_METHOD(TestNegate) {
			Tuple t1 = Tuple(1, -2, 3, -4);
			Assert::IsTrue(t1.Negate() == Tuple(-1, 2, -3, 4));
		}

		TEST_METHOD(TestMultiply) {
			Tuple t1 = Tuple(1, -2, 3, -4);
			Assert::IsTrue(t1 * 3.5 == Tuple(3.5, -7, 10.5, -14));
			Tuple t2 = Tuple(1, -2, 3, -4);
			Assert::IsTrue(t1 * 0.5 == Tuple(0.5, -1, 1.5, -2));
		}

		TEST_METHOD(TestDivide) {
			Tuple t1 = Tuple(1, -2, 3, -4);
			double scalar = 2;
			Assert::IsTrue(t1 / scalar == Tuple(0.5, -1, 1.5, -2));
		}

		TEST_METHOD(TestMagnitude) {
			Tuple v1 = Vector(0, 1, 0);
			Assert::IsTrue(abs(v1.Magnitude() - 1) <= 0);
			Tuple v2 = Vector(0, 0, 1);
			Assert::IsTrue(abs(v2.Magnitude() - 1) <= 0);
			Tuple v3 = Vector(1, 2, 3);
			Assert::IsTrue(abs(v3.Magnitude() - sqrt(14)) <= 0);
			Tuple v4 = Vector(-1, -2, -3);
			Assert::IsTrue(abs(v4.Magnitude() - sqrt(14)) <= 0);
		}

		TEST_METHOD(TestNormalize) {
			Tuple v1 = Vector(4, 0, 0);
			Assert::IsTrue(v1.Normalize() == Vector(1, 0, 0));
			Tuple v2 = Vector(1, 2, 3);
			Assert::IsTrue(v2.Normalize() == Vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
		}

		TEST_METHOD(TestDotProduct) {
			Tuple v1 = Vector(1, 2, 3);
			Tuple v2 = Vector(2, 3, 4);
			Assert::AreEqual(v1.DotProduct(v2), 20.0);
		}

		TEST_METHOD(TestCrossProduct) {
			Tuple v1 = Vector(1, 2, 3);
			Tuple v2 = Vector(2, 3, 4);
			Assert::IsTrue(v1.CrossProduct(v2) == Vector(-1, 2, -1));
			Assert::IsTrue(v2.CrossProduct(v1) == Vector(1, -2, 1));
		}
	};
}
