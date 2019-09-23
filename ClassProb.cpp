//John Manacup 9/17/2019

#include <iostream>
#include <string>
#include "Car.h" //separating implementation of class

using namespace std;

int main() {

	Car car1(2019, "Dodge Charger"); // Car type

	cout << "The make of the car is: " << car1.getMake() << endl; //gets the make of the car
	cout << "Year model is: " << car1.getYear() << endl << endl; //gets the year model of the car

	cout << "The current speed of the car is: " << car1.getSpeed() << endl; //gets the initial speed of the car 

	for (int i = 0; i < 10; i++) {
		
		if (i < 5) { //calls the accelerate member function 5 times
			cout << "Accelerating...." << endl;
			car1.accelerate();
			cout << "The current speed of the car is: " << car1.getSpeed() << endl;
		}
		else { //calls the brake member function 5 times
			cout << "Braking...." << endl;
			car1.brake();
			cout << "The current speed of the car now is: " << car1.getSpeed() << endl;
			
		}
	}


}