//John Manacup
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//function prototype
void print(vector<string>&);
void fill(vector<string>&);

int main() {

	vector<string> list;
	vector<string>::iterator it;
	
	cout << "1) Creating an empty vector and printing it: " << endl;
	print(list);

	cout << "2) Append items to the vector" << endl;
	fill(list); // fill the vector with user inputs
	cout << "   Shopping list is now: " << endl;
	print(list);

	cout << "\n3) Removing the last element from the vector: " << endl;
	list.pop_back(); //removes the last element in the vector
	print(list);

	cout << "\n4) Append the item 'coffee' to the vector: " << endl;
	list.push_back("coffee"); //puts coffee in the vector
	print(list);

	cout << "\n5) Searching for the item, 'sugar' and inserting the word 'honey' before it: " << endl;
	it = find(list.begin(), list.end(), "sugar"); //finds the index of sugar
	list.insert(it, "honey");//inserts honey before the index
	print(list);

	cout << "\n6) Searching for the item, 'milk' and removing it from the vector: " << endl;
	it = find(list.begin(), list.end(), "milk"); //finds the index of milk
	list.erase(it); //erase the index of milk
	print(list);

	return 0;
}
//Precondition  : list has been declared
//Postcondition : prints the elements of the vector using iterator
void print(vector<string>& list) {

	string input;
	vector<string> ::iterator it;

	cout << "   "; //spacing
	for (it = list.begin(); it != list.end(); it++) {
		if (it == list.end() - 1) //puts period after the end of the element
			cout << *it << ".";
		else
		cout << *it << ", ";
	}

	cout << endl; //spacing
}

//Precondition  : list has been declared
//Postcondition : fills the vector with strings from the user input
void fill(vector<string>& list) {

	string input;
	vector<string> ::iterator it = list.begin();  //iterator pointing at the first element

	do
	{
		vector<string> ::iterator it = list.begin();  //iterator pointing at the first element; should be updated every time
		cout << "   Enter a shopping list item or 0 to quit: ";
		getline(cin, input);

		if (input != "0")
			list.insert(it,input);

	} while (input != "0");

}
