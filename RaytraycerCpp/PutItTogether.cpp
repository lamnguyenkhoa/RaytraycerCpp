// Putting it together chapter one
#include <iostream>
#include "PutItTogether.h"
#include "Tuple.h"

//-----------------Chapter 1-----------------------

class Projectile {
public:
	Tuple point;
	Tuple velocity;

	Projectile(Tuple p, Tuple v) {
		this->point = p;
		this->velocity = v;
	}
};

class Environment {
public:
	Tuple gravity;
	Tuple wind;

	Environment(Tuple g, Tuple w) {
		this->gravity = g;
		this->wind = w;
	}
};

void PITChapter1() {
	std::cout << "Yo you just run the program 1!" << std::endl;
}

void PITChapter2() {
	std::cout << "Yo you just run the program 2!" << std::endl;
}

void PITChapter3() {
	std::cout << "Yo you just run the program 3!" << std::endl;
}


