// Putting it together chapter one
#include <iostream>
#include "PutItTogether.h"
#include "Tuple.h"
#include "Point.h"
#include "Vector.h"


//-----------------Chapter 1---------------------------------------
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
	std::cout << "========================================" << std::endl;
	std::cout << "Program 1: Canon simulator." << std::endl;
	// Init
	Projectile p = Projectile(Point(0, 1, 0), Normalize(Vector(1, 1, 0)));
	Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
	int tickCount = 0;
	std::cout << "Projectile: " << std::endl;
	std::cout << "Start: " << p.position.toString() <<" | Velocity: " << p.velocity.toString() << std::endl;
	std::cout << "Environment: " << std::endl;
	std::cout << "Gravity: " << e.gravity.toString() << " | Wind: " << e.wind.toString() << std::endl;
	std::cout << "========================================" << std::endl;

	// Loop
	std::cout << "Tick " << tickCount << ": " << p.position.toString() << std::endl;
	while (p.position.y > 0) {
		p = Tick(e, p);
		tickCount++;
		std::cout << "Tick " << tickCount << ": " << p.position.toString() << std::endl;
	}
	std::cout << "The projectile hit the ground!" << std::endl;
}
//-----------------End chapter 1---------------------------------------


//-----------------Chapter 2---------------------------------------
void PITChapter2() {
	std::cout << "Yo you just run the program 2!" << std::endl;
}

void PITChapter3() {
	std::cout << "Yo you just run the program 3!" << std::endl;
}


