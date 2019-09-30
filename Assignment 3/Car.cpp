#include <iostream>
#include <string>

#include "Car.h"

//constructor
Car::Car(int model, string makeCar) {
	yearModel = model;
	make = makeCar;
	speed = 0;
}
//accessors
int Car::getYear() { return yearModel; }
int Car::getSpeed() { return speed; }
string Car::getMake() { return make; }

void Car::accelerate() { speed += 5; }
void Car::brake() { speed -= 5; }