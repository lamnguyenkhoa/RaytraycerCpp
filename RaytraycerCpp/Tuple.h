#pragma once

#ifndef TUPLE_H
#define TUPLE_H

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
};

bool operator== (const Tuple t1, const Tuple t2);
Tuple operator+ (const Tuple t1, const Tuple t2);
Tuple operator- (const Tuple t1, const Tuple t2);
Tuple operator* (const Tuple t1, const double scalar);
Tuple operator/ (const Tuple t1, const double scalar);
double Magnitude(Tuple t1);
Tuple Normalize(Tuple t1);
double DotProduct(Tuple t1, Tuple t2);

#endif // TUPLE_H