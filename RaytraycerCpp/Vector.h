#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"

class Vector : public Tuple {
public:
	Vector(double x, double t, double z);
};

#endif // VECTOR_H