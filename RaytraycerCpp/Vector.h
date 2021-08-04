#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"

class Vector : public Tuple {
public:
	Vector();
	Vector(double x, double t, double z);
};

Vector operator+(const Vector v1, const Vector v2);
Vector CrossProduct(Vector t1, Vector t2);

#endif // VECTOR_H