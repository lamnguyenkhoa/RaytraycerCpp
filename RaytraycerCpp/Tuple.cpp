#include "Tuple.h"
#include <cmath>
#include <iostream>

Tuple::Tuple() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

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
	if (abs(t1.x - t2.x) <= 0 && 
		abs(t1.y - t2.y) <= 0 && 
		abs(t1.z - t2.z) <= 0 && 
		abs(t1.w - t2.w) <= 0) 
		return true;
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

double Magnitude(Tuple t1) {
	double mag = pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2) + pow(t1.w, 2);
	mag = sqrt(mag);
	return mag;
}

Tuple Normalize(Tuple t1) {
	double mag = Magnitude(t1);
	double newX = t1.x / mag;
	double newY = t1.y / mag;
	double newZ = t1.z / mag;
	return Tuple(newX, newY, newZ, t1.w);
}

double DotProduct(Tuple t1, Tuple t2) {
	return t1.x * t2.x + t1.y * t2.y + t1.z * t2.z + t1.w * t2.w;
}

Tuple CrossProduct(Tuple t1, Tuple t2) {
	if (t1.w == 1 || t2.w == 1) {
		std::cout << "CrossProduct bug! Input are not vectors!" << std::endl;
		throw std::runtime_error(std::string("Failed! CrossProduct's inputs are not vectors!"));
	}
	return CreateVector(t1.y * t2.z - t1.z * t2.y, t1.z * t2.x - t1.x * t2.z, t1.x * t2.y - t1.y * t2.x);
}



