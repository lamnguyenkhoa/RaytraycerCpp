// Putting it together chapter one
#include <iostream>
#include "PutItTogether.h"
#include "Tuple.h"
#include "Point.h"
#include "Vector.h"

//-----------------Chapter 1-----------------------

class Projectile {
public:
	Point position;
	Vector velocity;

	Projectile(Point p, Vector v) {
		this->position = p;
		this->velocity = v;
	}
};

class Environment {
public:
	Vector gravity;
	Vector wind;

	Environment(Vector g, Vector w) {
		this->gravity = g;
		this->wind = w;
	}
};

Projectile Tick(Environment env, Projectile proj) {
	Point newPosition = proj.position + proj.velocity;
	Vector newVelocity = proj.velocity + env.gravity + env.wind;
	return Projectile(newPosition, newVelocity);
}

void PITChapter1() {
	std::cout << "Yo you just run the program 1!" << std::endl;
}

void PITChapter2() {
	std::cout << "Yo you just run the program 2!" << std::endl;
}

void PITChapter3() {
	std::cout << "Yo you just run the program 3!" << std::endl;
}


