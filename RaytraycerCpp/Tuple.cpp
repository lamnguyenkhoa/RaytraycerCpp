#include "Tuple.h"

Tuple::Tuple(double x, double y, double z, double w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

bool Tuple::IsItVector() {
	if (w == 1) {
		return false;
	}
	else {
		return true;
	}
}

Tuple Tuple::Negate()
{
	this->x = -x;
	this->y = -y;
	this->z = -z;
	this->w = -w;
	return *this;
}

bool operator==(const Tuple t1, const Tuple t2)
{
	if (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z && t1.w == t2.w) return true;
	else return false;
}

Tuple CreatePoint(double x, double y, double z) {
	return Tuple(x, y, z, 1);
}

Tuple CreateVector(double x, double y, double z) {
	return Tuple(x, y, z, 0);
}

Tuple AddTuple(Tuple t1, Tuple t2)
{
	double newX = t1.x + t2.x;
	double newY = t1.y + t2.y;
	double newZ = t1.z + t2.z;
	double newW = t1.w + t2.w;
	return Tuple(newX, newY, newZ, newW);
}

Tuple SubtractTuple(Tuple t1, Tuple t2)
{
	double newX = t1.x - t2.x;
	double newY = t1.y - t2.y;
	double newZ = t1.z - t2.z;
	double newW = t1.w - t2.w;
	return Tuple(newX, newY, newZ, newW);
}

Tuple MultiplyTuple(Tuple t1, double scalar)
{
	double newX = t1.x * scalar;
	double newY = t1.y * scalar;
	double newZ = t1.z * scalar;
	double newW = t1.w * scalar;
	return Tuple(newX, newY, newZ, newW);
}

Tuple DivideTuple(Tuple t1, double scalar)
{
	double newX = t1.x / scalar;
	double newY = t1.y / scalar;
	double newZ = t1.z / scalar;
	double newW = t1.w / scalar;
	return Tuple(newX, newY, newZ, newW);
}



