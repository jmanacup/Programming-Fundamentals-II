//John Manacup 10/8/2019

#include <iostream>
#include <string>
#include <iomanip>

#include "Employee.h"
#include "ProductionWorker.h"

using namespace std;

int main() {

	ProductionWorker worker; //declared a ProductionWorker object

	//sets the information about worker
	worker.setName("John Jones");
	worker.setNum(123);
	worker.setDate("10/12/2010");
	worker.setShift(2);
	worker.setPay(18.00);

	//printing out the information
	cout << right << setw(20) << "Name: " << worker.getName() << endl;
	cout << setw(20) << "Employee Number: " << worker.getNum() << endl;
	cout << setw(20) << "Hire Date: " << worker.getDate() << endl;

	cout << setw(20) << "Shift: ";

	//checks to see if Day or Night based on the shift (assuming only 1 and 2 are the only accepted values
	if (worker.getShift() == 1)
		cout << "Day" << endl;
	else
		cout << "Night" << endl;

	cout << setw(20) << "Shift number: " << worker.getShift() << endl;

	cout << fixed << showpoint << setprecision(2); 
	cout << setw(20) << "Pay rate: " << worker.getPay() << endl;

	return 0;
}