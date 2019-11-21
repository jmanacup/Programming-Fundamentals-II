//John Manacup
#include <iostream>

using namespace std;

int power(int num, int exp) {  //recursive function
	
	if (exp == 0) //base case: check to see if the exponent is 0
		return 1;
	else {
		return num * power(num, exp - 1); //recursive case: will repeat if exponent is not 0
	}
}

int main() {

	//variables used
	int base, exponent;

	cout << "Recursive Power Function" << endl;

	cout << "Enter base: ";
	cin >> base; 

	cout << "Enter exponent: ";
	cin >> exponent;

	cout << "\nResult: " << power(base, exponent) << endl << endl; //calls the recursion

	return 0;
}