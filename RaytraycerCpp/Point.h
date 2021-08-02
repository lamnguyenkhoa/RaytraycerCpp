#pragma once

#ifndef POINT_H
#define POINT_H

#include "Tuple.h"

class Point : public Tuple {
public:
	Point(double x, double y, double z);
};

#endif // POINT_H