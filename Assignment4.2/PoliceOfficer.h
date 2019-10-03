#ifndef POLICEOFFICER_H //ifndef guard
#define POLICEOFFICER_H

#include <iostream>
#include <string>


//header files
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"


class PoliceOfficer {

private:
	//member variables
	string name;
	int badgeNum;
	ParkedCar car;
	ParkingMeter carTime;
	ParkingTicket ticket;

public:
	//constructor
	PoliceOfficer(string name, int badgeNum, ParkedCar car, ParkingMeter carTime){

		this->name = name;
		this->badgeNum = badgeNum;
		this->car = car;
		this->carTime = carTime;
		ticket = { car, carTime };

	}

	//member functions

	void identify() { //identifies if the park time exceeded the paid time

		if (car.getNumOfMin() > carTime.getTime()) {
			getInfo(); //prints in the info of the police
			ticket.getInfo(); //prints the info of the car
			ticket.reportInfo(); //prints the info of the ticket
		}
		else //if the car followed the paid time
			cout << "You are not in trouble. Have a good day!" << endl;

	}

	void getInfo() { //prints the police information 

		cout << "Police Officer Information:" << endl << endl;
		cout << "\tName: " << name << endl;
		cout << "\tBadge Number: " << badgeNum << endl << endl;

	}

};

#endif