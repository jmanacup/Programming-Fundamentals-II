#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <iostream>
#include <string>


//header files
#include "ParkedCar.h"
#include "ParkingMeter.h"

using namespace std;

class ParkingTicket {

private:
	//member variables
	ParkedCar car;
	int minPurchased = 0;

public:
	//default constructor
	ParkingTicket() {}
	//constructor
	ParkingTicket(ParkedCar car, ParkingMeter carTime) {
		this->car = car;
		minPurchased = carTime.getTime();
	}

	void getInfo() { //prints the car information

		cout << "Car Information:" << endl << endl;
	
		cout << "\tMake: " << car.getMake() << endl;
		cout << "\tModel: " << car.getModel() << endl;
		cout << "\tColor: " << car.getColor() << endl;
		cout << "\tLicense Number: " << car.getLicense() << endl;
		cout << "\tMinutes Parked: " << car.getNumOfMin() << endl << endl;
	}

	void reportInfo() { //prints the violation report

		int fine = 0;
		int minViolation = car.getNumOfMin() - minPurchased;
		int temp = minViolation;

		//Automatically deduct an hour and make the fine $25
		temp -= 60;
		fine += 25;

		while (temp > 0) { //if the time exceeded an hour

			temp -= 60;
			fine += 10;
		}
		
		cout << "Ticket Information:" << endl << endl;
		cout << "\tMinutes in violation: " << minViolation << endl;
		cout << "\tFine: " << "$ " << fine << endl << endl;

	}

};

#endif
