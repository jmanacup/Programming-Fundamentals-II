#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//structure of the soccer player
struct Player{

	//structure members
	string name;
	int number = 0, score = 0;

};

//function prototypes
int fill(Player[]);
void display(Player[]);

const int SIZE = 6; //max size of soccer players

int main() {

	//array consisting of soccer players
	Player team[SIZE];
	int totalScore;

	totalScore = fill(team); //puts the total in totalScore and fill the array with players
	display(team); //displays the player's members in a formatted manner

	cout << "The total score of the team is: " << totalScore << endl << endl;
	return 0;
}

//Precondition : a struct Player array has been established and initialized
//Postcondition: it inputs the user's members to the 6 players
int fill(Player a[]) {

	int total = 0;

	for (int i = 0; i < SIZE; i++) {

		cout << "Player " << i + 1 << endl;
		cout << "Insert the name of the soccer player: ";

		getline(cin, a[i].name);
		
		//looping structure that does not stop until the given number is valid
		do {

			//outputs if the input number/score is invalid
			if (a[i].number < 0) {
				cout << "The number inserted is invalid." << endl;
			}

			//asks the user for number
			cout << "Insert the soccer player's number: ";
			cin >> a[i].number;

		} while (a[i].number < 0);

		//looping structure that does not stop until the given score is valid
		do {

			if (a[i].score < 0)
				cout << "The score inserted is invalid." << endl;

			//asks the user for score
			cout << "Insert the soccer player's points scored: ";
			cin >> a[i].score;


		} while (a[i].score < 0);

		total += a[i].score; //gets the total score of the team
		cin.ignore(); //accounts for the cin
		cout << endl; //spacing

	}

	//spacing
	cout << endl << endl;

	return total;
}
//Precondition : a struct Player array has been established and initialized; function fill has been called
//Postcondition: it displays the member function in an orderly manner
void display(Player a[]) {
	
	cout << "  " << left << setw(15) << "PLAYER" << setw(15) << "NUMBER" << setw(15) << "POINTS SCORED" << endl; //header
	cout << "===============================================" << endl;

	for (int i = 0; i < SIZE; i++) //displays members data of each players
		cout << "  " << setw(15) << a[i].name << setw(15) << a[i].number << setw(15) << a[i].score << endl;

	//spacing
	cout << endl << endl;


}