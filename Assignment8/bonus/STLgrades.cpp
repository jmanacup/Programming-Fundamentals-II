//John Manacup

#include <iostream>
#include <iomanip>
#include <list> //to access linked list STL

using namespace std;

//Precondition : list of double scores has been declared and initialized
//Postcondition: prints each of the values of the Linked List
void print(list<double> scores) {

	list<double> ::iterator it;

	cout << "   List of Exam Grades: ";
	for (it = scores.begin(); it != scores.end(); it++)
		cout << *it << " ";

	cout << endl;

}
//Precondition : list of double scores has been declared and initialized; double min and max has been declared
//Postcondition: prints the highest and the lowest in the Linked List with their corresponding addresses
void highAndLow(list<double> scores, double& min, double& max) {

	list <double> ::iterator it, lowest, highest;

	scores.sort();
	lowest = scores.begin();
	highest = scores.end();
	highest--; //access the very last of the element

	min = *lowest;
	max = *highest;

	cout << "   Highest value: " << setw(3) << *highest << " Highest address: " << &highest << endl;
	cout << "   Lowest value : " << setw(3) << *lowest << " Lowest address : " << &lowest << endl;

	cout << endl;
}
int main() {

	//variables used
	double num;
	list <double> scores; //numberlist
	double min, max, total = 0;
	list <double> ::iterator it, lowest, highest;

	//enters 7 inputs for test grade
	cout << "Enter seven exam scores for your class (0 lowest, 100 highest):" << endl;
	for (int i = 0; i < 7; i++) {
		cout << "  Enter grade for Exam " << i + 1 << ": ";
		cin >> num;
		scores.push_back(num); //creates a new node with the value num
	}

	cout << endl; //spacing

	cout << "1) Highest and Lowest exam scores among the linked-list:" << endl;
	highAndLow(scores, min, max);  //determines the highest and lowest score
	print(scores);
	cout << endl;

	cout << "2) Replace the lowest exam score with a new node that has the value 70:" << endl;
	
	for (it = scores.begin(); it != scores.end(); it++) 
		if (*it == min)
			lowest = it; //gets the iterator for min

	scores.insert(lowest, 70); //inserts a new node
	scores.erase(lowest++); //erase the node after the newly inserted node
	cout << "Address of new node with the lowest value: " << &lowest << endl; //prints new address of the node
	print(scores);
	cout << endl;

	cout << "3) Delete the highest exam score from the list and display the list:" << endl;
	for (it = scores.begin(); it != scores.end(); it++)
		if (*it == max)
			highest = it; //gets the iterator for max

	scores.erase(highest);//erases the highest node
	print(scores);
	cout << endl;

	cout << "4) Calculate and display the class average:" << endl;

	for (it = scores.begin(); it != scores.end(); it++)
		total += *it; //gets the total

	cout << fixed << showpoint << setprecision(2);
	cout << "   Class average: " << total/scores.size() << endl << endl; //prints out the average
	
	return 0;
}