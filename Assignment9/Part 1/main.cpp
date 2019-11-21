//John Manacup

#include <iostream>
#include "DynamicStack.h"

using namespace std;

int main() {

	DynamicStack<double> stack; // stack
	int stackSize; //stack size
	double num; //to store num in the pop function
	double numArr[] = { 5.1, 10.1, 20.2, 25.4, 36.7 }; //double values

	cout << "Pushing 5 values to the stack: " << endl;
	for (int i = 0; i < 5; i++) {
		stack.push(numArr[i]); //pushes the corresponding values in the stack
		cout << " Pushing " << numArr[i] << endl;
	}
	stack.displayStack();

	cout << "\nAdding top two numbers and pushing the sum onto the stack:" << endl;
	stack.add(); //adds the 2 values of the stack and pushing their sum
	stack.displayStack();

	cout << "\nPops the first two values off the stack and divide. Then push it back onto the stack:" << endl;
	stack.divide();//divides the 2 values of the stack and pushing their quotient
	stackSize = stack.displayStack(); //store the size of the stack based on the last operation done

	cout << "\nPopping values from the stack: " << endl;
	for (int i = 0; i < stackSize; i++) { //pop values in the stack
		stack.pop(num);
		cout << " Popping " << num << endl;
	}

	cout << "\nAttempting to pop a value that isn't there:" << endl;
	stack.pop(num); //check to see if the stack is empty

	return 0;
}