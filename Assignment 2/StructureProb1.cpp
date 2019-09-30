#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//structure Moviedata
struct Moviedata {

	//members of the structure
	string title, director;
	int yearReleased, minutes;

};

//function prototype
void print(Moviedata);

int main() {

	//Moviedata declared and initialized
	Moviedata movie1 = { "Book Thief", "Brian Percival", 2013, 131 };
	Moviedata movie2 = { "3 Idiots", "Rajkumar Hirani", 2009, 170 };

	//calls the print fuctions
	print(movie1);
	print(movie2);

	return 0;
}
//Precondition : Moviedata has been declared and initialized
//Postcondition: outputs the data based on the members of the structure
void print(Moviedata movie) {

	//prints the members uniformly
	cout << setw(15) << "Movie Title: " << movie.title << endl;
	cout << setw(15) << "Director: " << movie.director << endl;
	cout << setw(15) << "Year Released: " << movie.yearReleased << endl;
	cout << setw(15) << "Running Time: " << movie.minutes << " minutes" << endl;

	cout << endl << endl; //spacing
}