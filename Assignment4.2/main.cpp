//John Manacup 10/1/2019

#include <iostream>
#include <string>

//header files
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

int main() {

	//Initialized ParkedCar object
	ParkedCar car1("Volkswagen", 1972, "Red", "147RHZM", 125);
	//Initialized ParkingMeter
	ParkingMeter car1Time(60);
	//Initialized PoliceOfficer object
	PoliceOfficer cop("Joe Friday", 4788, car1, car1Time);
	cop.identify(); //Identifies if the car violated the time rule

	return 0;
}