#include "Point.h"

Point::Point() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 1;
}

Point::Point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 1;
}

Point operator+(const Point p, const Vector v) {
	return Point(p.x + v.x, p.y + v.y, p.z + v.z);
}
