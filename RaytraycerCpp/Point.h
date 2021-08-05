#pragma once

#ifndef POINT_H
#define POINT_H

#include "Tuple.h"
#include "Vector.h"

class Point : public Tuple {
public:
	Point();
	Point(double x, double y, double z);
	std::string toString() const;
};

Point operator+(const Point p, const Vector v);

#endif // POINT_H