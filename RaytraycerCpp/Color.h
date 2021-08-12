#pragma once

#ifndef COLOR_H
#define COLOR_H

#include "Tuple.h"

class Color : public Tuple {
public:
	double red;
	double green;
	double blue;

	Color();
	Color(double r, double g, double b);
};

#endif // !COLOR_H