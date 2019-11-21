//John Manacup

#include <iostream>
#include <iomanip>
#include "NumberList.h"

using namespace std;

int main() {

	//variables used
	double num, min, max, average;

	NumberList scores; //numberlist

	//enters 7 inputs for test grade
	cout << "Enter seven exam scores for your class (0 lowest, 100 highest):" << endl;
	for (int i = 0; i < 7; i++) {
		cout << "  Enter grade for Exam " << i + 1 << ": ";
		cin >> num;
		scores.appendNode(num); //appends the value into nodes
	}
	
	cout << endl;
	
	cout << "1) Highest and Lowest exam scores among the linked-list:" << endl;
	scores.maxAndMin(min, max); //prints out the highest and lowest score with address
	cout << "   List of Exam Grades: ";
	scores.displayList();
	cout << endl << endl;

	cout << "2) Replace the lowest exam score with a new node that has the value 70:" << endl;
	scores.changeNode(min); //change the min node with a new node with value of 70
	cout << "   List of Exam Grades: ";
	scores.displayList();
	cout << endl << endl;
	
	cout << "3) Delete the highest exam score from the list and display the list:" << endl;
	scores.deleteNode(max); //deletes the highest score 
	cout << "   List of Exam Grades: ";
	average = scores.displayList();
	cout << endl << endl;

	cout << "4) Calculate and display the class average:" << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "   Class average: " << average << endl << endl;

	return 0;
}