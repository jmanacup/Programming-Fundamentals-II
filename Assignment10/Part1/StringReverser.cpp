//John Manacup

#include <iostream>
#include <cstring>

using namespace std;

void reverse(char word[]) { //recursive function

	int length = strlen(word); //gets the length of the char array
	char temp[50]; //placeholder to copy the the word array - 1 of the length

	if (length > 0) { //recursive case

		strncpy_s(temp, word, length - 1); //copy the word array minus the last character
		cout << word[length - 1]; // cout the last character
		reverse(temp); //calls the function itself

	}

}

int main() {

	char input[] = "Welcome"; //char array

	cout << "Original Word: ";

	for (char a : input) //prints the char array
		cout << a;

	cout << "\nReverse Word : ";
	reverse(input); //calls the recursive function

	cout << endl << endl;
	return 0;
}