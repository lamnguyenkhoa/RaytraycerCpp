#include "Vector.h"

Vector::Vector() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 0;
}

std::string Vector::toString() const
{
	return "(" + std::to_string(this->x) + "," + 
		std::to_string(this->y) + "," + 
		std::to_string(this->z) + ")";
}

Vector operator+(const Vector v1, const Vector v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector CrossProduct(Vector t1, Vector t2)
{
	return Vector(t1.y * t2.z - t1.z * t2.y, t1.z * t2.x - t1.x * t2.z, t1.x * t2.y - t1.y * t2.x);
}

Vector Normalize(Vector v)
{
	double mag = Magnitude(v);
	return Vector(v.x / mag, v.y / mag, v.z / mag);
}
