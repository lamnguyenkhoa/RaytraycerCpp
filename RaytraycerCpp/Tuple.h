#pragma once

#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
	public:
		double x;
		double y;
		double z;
		double w;

		Tuple(double x, double y, double z, double w);
		bool IsItVector();
		Tuple Negate();
		

};

bool operator== (const Tuple t1, const Tuple t2);
Tuple CreatePoint(double x, double y, double z);
Tuple CreateVector(double x, double y, double z);
Tuple AddTuple(Tuple t1, Tuple t2);
Tuple SubtractTuple(Tuple t1, Tuple t2);
Tuple MultiplyTuple(Tuple t1, double scalar);
Tuple DivideTuple(Tuple t1, double scalar);

#endif // TUPLE_H