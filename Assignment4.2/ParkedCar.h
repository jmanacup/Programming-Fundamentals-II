#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <iostream>
#include <string>

using namespace std;

class ParkedCar {

private:
	//member variables
	string make="", color="", licenseNum="";
	int model=0, numOfMin=0;

public:
	//default constructor
	ParkedCar(){}
	//constructor
	ParkedCar(string make, int model, string color, string licenseNum, int numOfMin){

		this->make = make;
		this->model = model;
		this->color = color;
		this->licenseNum = licenseNum;
		this->numOfMin = numOfMin;
	}
	
	//accessors
	string getMake() { return make; }
	int getModel() { return model; }
	string getColor() { return color; }
	string getLicense() { return licenseNum; }
	int getNumOfMin() { return numOfMin; }
	
};

#endif
