#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {

	private:
		//member variables
		int yearModel, speed;
		string make;
	public:
		//constructor
		Car(int, string);
		//accessors
		int getYear();
		int getSpeed();
		string getMake();

		void accelerate();
		void brake();

};

#endif