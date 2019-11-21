//John Manacup 10/21/19
// Using template functions

#include <iostream>
#include <string>

using namespace std;

// function template printArray definition
template< typename T >
void printArray(const T array, int count)
{
	// display array
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";

	cout << endl;
} // end function printArray

//overloaded printArray function 
template< typename T >
void printArray(const T array, int count, int lowSubscript, int highSubscript)
{
	try { //exceptions
		string error; 
		//validates low and high subscript
		if (lowSubscript < 0 || highSubscript > count - 1 || highSubscript <= lowSubscript) {
			error = "Error invalid subscript."; //message for error
			throw error;
		}
		
		//since it is already established that it is within the range
		cout << highSubscript - lowSubscript + 1;
	}
	catch (string msg) {
		cout << msg << endl; //prints the message
	}
}

int main()
{
	const int INTCOUNT = 5; // size of array intarr
	const int DOUBLECOUNT = 7; // size of array doublearr
	const int CHARCOUNT = 6; // size of array chararr
	// declare and initialize arrays
	int intarr[INTCOUNT] = { 1, 2, 3, 4, 5 };
	double doublearr[DOUBLECOUNT] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char chararr[CHARCOUNT] = "HELLO"; // 6th position for null

	// display array “intarr” using printArray function
	cout << "Using original printArray function\n";
	printArray(intarr, INTCOUNT);
	cout << "Array intarr contains: ";
	printArray(intarr, INTCOUNT, 0, INTCOUNT - 1);
	cout << " elements." << endl;
	cout << "Array intarr from position 1 to 3 contains: ";
	printArray(intarr, INTCOUNT, 1, 3);
	cout << " elements." << endl;
	cout << "Array intarr with invalid subscripts contains: ";
	printArray(intarr, INTCOUNT, -1, INTCOUNT);
	cout << endl;

	// display array “doublearr” using printArray function
	cout << "Using original printArray function\n";
	printArray(doublearr, DOUBLECOUNT);
	cout << "Array doublearr contains: ";
	printArray(doublearr, DOUBLECOUNT, 0, DOUBLECOUNT - 1);
	cout << " elements." << endl;
	cout << "Array doublearr from position 1 to 3 contains: ";
	printArray(doublearr, DOUBLECOUNT, 1, 3);
	cout << " elements." << endl;
	cout << "Array doublearr with invalid subscripts contains: ";
	printArray(doublearr, DOUBLECOUNT, -1, DOUBLECOUNT);
	cout << endl;
	
	// display array “chararr” using printArray function
	cout << "Using original printArray function\n";
	printArray(chararr, CHARCOUNT);
	cout << "Array chararr contains: ";
	printArray(chararr, CHARCOUNT, 0, CHARCOUNT - 2);
	cout << " elements." << endl;
	cout << "Array chararr from position 1 to 3 contains: ";
	printArray(chararr, CHARCOUNT, 1, 3);
	cout << " elements." << endl;
	cout << "Array doublearr with invalid subscripts contains: ";
	printArray(chararr, CHARCOUNT, -1, CHARCOUNT);
	cout << endl << endl;

	return 0;
	
}
