//John Manacup 10/17/2019

#include <iostream>
#include <string>
#include "TestScores.h"

using namespace std;


int main() {

	//arrays to be checked at
	int myScores[NUM_SCORES] = { 88, 90, 93, 87, 99 };
	int badScores[NUM_SCORES] = { 88, 90, -99, 87, 99 };

	TestScores test1(myScores), test2(badScores); // assigns the array to the TestScores objects

	try {

		double avgT1, avgT2;

		//calculating average of the first TestScores
		cout << "Calculating 1st average of the test scores" << endl;
		avgT1 = test1.average();
		cout << "The average score is: " << avgT1 << endl << endl;

		//calculating average of the second TestScores
		cout << "Calculating 1st average of the test scores" << endl;
		avgT2 = test2.average();
		cout << "The average score is: " << avgT2 << endl;
	}
	catch (string msg) { //catches the message being thrown

		cout << msg << endl;
	}

	return 0;
}