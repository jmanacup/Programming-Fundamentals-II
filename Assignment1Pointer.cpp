#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void getScores(double *, int);
void getAve(double *, int);

int main() {

	//variables used
	int numScores;
	double* ptr = nullptr;

	//ask for the total number of test scores
	cout << "Please enter the number of the test scores: ";
	cin >> numScores; //gets the user total test scores

	//dynamically allocating an array
	ptr = new double[numScores];

	getScores(ptr, numScores); //gets the user inputted score one by one in the array
	
	cout << "The scores are as followed: " << endl << endl;

	for (int j = 0; j < numScores; j++) {
		//spacing for the test scores 
		if (j % 4 == 0 && j >= 4)
			cout << endl;

		cout << setw(8) << *(ptr + j); //outputs the value in the array 
	}
	cout << endl;
	getAve(ptr, numScores); //gets the average of the scores in the dynamically allocated array

	//deletes the allocated memory
	delete[] ptr;
	ptr = nullptr; //sets ptr pointer to null pointer

	return 0;

}

// Preconditions: a dynamically allocated array has been declared; user already inputted the total number of test scores
//Postconditions: it put the positive inputted score in the array
void getScores(double* ptr, int numScores) {

	for (int i = 0; i < numScores; i++) {
		double temp = 0; //temporary variable for the score
		do { //a loop that will execute everytime if the input score is negative

			if (temp < 0) //if the score is negative
				cout << "The input score is invalid." << endl;

			cout << "Insert the (" << i + 1 << ") score: ";
			cin >> temp; //gets the score

			*(ptr + i) = temp; //assign the temp to the array

		} while (temp < 0);
	}
	//spacing
	cout << endl;
}
// Preconditions: a dynamically allocated array has been declared; user already inputted the total number of test scores
//Postconditions: it prints the average of the array
void getAve(double *ptr, int numScores) {

	double total = 0;

	for (int i = 0; i < numScores; i++) {
		
		total += *(ptr + i); //put into the total variable the total of the array

	}
	//outputs the average of the test scores
	cout << "The average of the test scores is: " << total / numScores << endl;

}
