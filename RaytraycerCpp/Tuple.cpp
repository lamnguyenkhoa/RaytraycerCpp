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
	// w == 1 mean it's point. w == 0 mean it's vector.
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

std::string Tuple::ToString() const
{
	return "(" + std::to_string(this->x) + "," +
		std::to_string(this->y) + "," +
		std::to_string(this->z) + ")";
}

// Square-root operation is expensive so we use this function when need the squared magnitude
double Tuple::MagnitudeSq() {
	double magSq = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2);
	return magSq;
}

double Tuple::Magnitude() {
	double magSq = this->MagnitudeSq();
	return sqrt(magSq);
}

Tuple Tuple::Normalize() {
	double mag = this->Magnitude();
	return Tuple(this->x / mag, this->y / mag, this->z / mag, this->w);
}

double Tuple::DotProduct(Tuple other) {
	return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
}

Tuple Tuple::CrossProduct(Tuple other) {
	return Vector(this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x);
}

Tuple Vector() {
	return Tuple(0, 0, 0, 0);
}

Tuple Vector(double x, double y, double z) {
	return Tuple(x, y, z, 0);
}

Tuple Point() {
	return Tuple(0, 0, 0, 0);
}

Tuple Point(double x, double y, double z) {
	return Tuple(x, y, z, 1);
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

Tuple operator-(const Tuple neg) {
	return Tuple(-neg.x, -neg.y, -neg.z, -neg.w);
}

Tuple operator*(const Tuple t, const double s)
{
	return Tuple(t.x * s, t.y * s, t.z * s, t.w * s);
}

Tuple operator*(const double s, const Tuple t)
{
	return Tuple(t.x * s, t.y * s, t.z * s, t.w * s);
}

Tuple operator/(const Tuple t, const double s)
{
	return Tuple(t.x / s, t.y / s, t.z / s, t.w / s);
}
