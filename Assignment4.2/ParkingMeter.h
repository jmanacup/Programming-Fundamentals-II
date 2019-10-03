#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include <iostream>
#include <string>

using namespace std;

class ParkingMeter {

private:
	//member variable
	int minPurchased = 0;

public:
	//default constructor
	ParkingMeter() {}
	//constructor
	ParkingMeter(int min) {

		minPurchased = min;
	}
	//accessor
	int getTime() { return minPurchased; }

};

#endif
