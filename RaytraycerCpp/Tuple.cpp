#include "Tuple.h"

Tuple::Tuple(double x, double y, double z, int w) {
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
