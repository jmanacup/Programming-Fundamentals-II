#ifndef TESTSCORES_H
#define TESTSCORES_H

#include <iostream>
#include <string>

using namespace std;

const int NUM_SCORES = 5; //const value of 5

class TestScores {

private:
	//array member variable
	int myScores[NUM_SCORES] = {};

public:

	TestScores() {}; //default constructor

	TestScores(int myScores1[]) { //constructor
		for (int i = 0; i < NUM_SCORES; i++)
			myScores[i] = myScores1[i];
	}
	double average() { //returns the average of the test scores

		//variables used
		double total = 0;
		string msg;

		for (int i = 0; i < NUM_SCORES; i++) {

			if (myScores[i] < 0 || myScores[i] > 100) { //checks to see if a score is a negative or greater than 100
				msg = "An invalid score was found. The invalid score is " + to_string(myScores[i]);
				throw msg;
			}

			total += myScores[i];
		}

		return total / NUM_SCORES; //returns the average
	}

};

#endif