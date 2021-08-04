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

Tuple operator+(const Tuple t1, const Tuple t2)
{
	return Tuple(t1.x + t2.x, t1.y + t2.y, t1.z + t2.z, t1.w + t2.w);
}

Tuple operator-(const Tuple t1, const Tuple t2)
{
	return Tuple(t1.x - t2.x, t1.y - t2.y, t1.z - t2.z, t1.w - t2.w);
}

Tuple operator*(const Tuple t, const double s)
{
	return Tuple(t.x * s, t.y * s, t.z * s, t.w * s);
}

Tuple operator/(const Tuple t, const double s)
{
	return Tuple(t.x / s, t.y / s, t.z / s, t.w / s);
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
