#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee { //ProductionWorker is the derived class; Employee as the base class

private:
	//member variables
	int shift = 0;
	double hourPay = 0.0;

public:
	//default constructor
	ProductionWorker(){}
	//constructor
	ProductionWorker(int shift, double hourPay) {
		this->shift = shift;
		this->hourPay = hourPay;
	}

	//accessors
	int getShift() { return shift; }
	double getPay() { return hourPay; }

	//mutators
	void setShift(int shift) {
		this->shift = shift;
	}
	void setPay(double hourPay) {
		this->hourPay = hourPay;
	}
};

#endif