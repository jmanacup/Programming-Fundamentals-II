//John Manacup

#include <iostream>
#include <fstream>
#include <string>

#include "DynamicQueue.h"

using namespace std;

int main() {

	ifstream infile1, infile2; //creates 2 infile stream
	infile1.open("file1.txt"); //opens both files
	infile2.open("file2.txt");

	DynamicQueue<char> file1;//two queues for the 2 files 
	DynamicQueue<char> file2;
	char value; //placement for every extraction for the infile
	int counter = 0; //counter for file size considering that both file 1 and file 2 has same amount of data
	string msg = "The files are identical.";

	while (infile1 >> value) {
		file1.enqueue(value); //enqueue each value in file1
		counter++;
	}

	while (infile2 >> value)
		file2.enqueue(value); //enqueue each value in file2
		
	cout << "File content comparison:" << endl;

	cout << "File 1\t\tFile 2\t\tResult" << endl;

	for (int i = 0; i < counter; i++) { //dequeue the values of both of the files and compare them to each one 

		char char1, char2;
		file1.dequeue(char1); 
		file2.dequeue(char2); 

		cout << char1<< "\t\t" << char2 << "\t\t  ";
		
		if (char1 == char2) //if they are equal put equal sign
			cout << " =" << endl;

		else {
			cout << "!=" << endl; //not equal !=
			msg = "The files are not identical.";
		}

	}

	cout << endl << msg;

	return 0;
}