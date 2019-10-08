#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {

private:
	//member variables
	string name = "", hireDate = "";
	int employeeNum = 0;

public:
	//default constructors
	Employee(){}

	//contructor
	Employee(string name, int employeeNum, string hireDate) {
		this->name = name;
		this->employeeNum = employeeNum;
		this->hireDate = hireDate;
	}

	//accessors
	string getName() { return name; }
	string getDate() { return hireDate; }
	int getNum() { return employeeNum; }

	//mutators
	void setName(string name) {
		this->name = name;
	}
	void setDate(string hireDate) {
		this->hireDate = hireDate;
	}
	void setNum(int employeeNum) {
		this->employeeNum = employeeNum;
	}

};

#endif