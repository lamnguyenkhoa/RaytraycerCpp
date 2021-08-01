#pragma once

#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
	public:
		double x;
		double y;
		double z;
		int w;

		Tuple(double x, double y, double z, int w);
		bool IsItVector();
		

};

bool operator== (const Tuple t1, const Tuple t2);
Tuple CreatePoint(double x, double y, double z);
Tuple CreateVector(double x, double y, double z);

#endif // TUPLE_H