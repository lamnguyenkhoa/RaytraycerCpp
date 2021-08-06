#pragma once

#ifndef TUPLE_H
#define TUPLE_H

#include <string>

class Tuple {
public:
	double x;
	double y;
	double z;
	double w;

	Tuple();
	Tuple(double x, double y, double z, double w);
	bool IsItVector();
	Tuple Negate();
	std::string ToString() const;
	double Magnitude();
	Tuple Normalize();
	double DotProduct(Tuple other);
	Tuple CrossProduct(Tuple other);
};

Tuple Vector();
Tuple Vector(double x, double y, double z);
Tuple Point();
Tuple Point(double x, double y, double z);
bool operator== (const Tuple t1, const Tuple t2);
Tuple operator+ (const Tuple t1, const Tuple t2);
Tuple operator- (const Tuple t1, const Tuple t2);
Tuple operator- (const Tuple neg);
Tuple operator* (const Tuple t1, const double scalar);
Tuple operator/ (const Tuple t1, const double scalar);

#endif // TUPLE_H