// Putting it together chapter one
#include <iostream>
#include "PutItTogether.h"
#include "Tuple.h"

//-----------------Chapter 1---------------------------------------
class Projectile {
public:
	Tuple position;
	Tuple velocity;

	Projectile(Tuple p, Tuple v) {
		this->position = p;
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

Projectile Tick(Environment env, Projectile proj) {
	Tuple newPosition = proj.position + proj.velocity;
	Tuple newVelocity = proj.velocity + env.gravity + env.wind;
	return Projectile(newPosition, newVelocity);
}

void PITChapter1() {
	std::cout << "========================================" << std::endl;
	std::cout << "Program 1: Canon simulator." << std::endl;
	// Init
	Projectile p = Projectile(Point(0, 1, 0), Vector(1, 1, 0).Normalize());
	Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
	int tickCount = 0;
	std::cout << "Projectile: " << std::endl;
	std::cout << "Start: " << p.position.ToString() <<" | Velocity: " << p.velocity.ToString() << std::endl;
	std::cout << "Environment: " << std::endl;
	std::cout << "Gravity: " << e.gravity.ToString() << " | Wind: " << e.wind.ToString() << std::endl;
	std::cout << "========================================" << std::endl;

	// Loop
	std::cout << "Tick " << tickCount << ": " << p.position.ToString() << std::endl;
	while (p.position.y > 0) {
		p = Tick(e, p);
		tickCount++;
		std::cout << "Tick " << tickCount << ": " << p.position.ToString() << std::endl;
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


