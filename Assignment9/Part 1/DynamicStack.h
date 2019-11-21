#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class DynamicStack {
private:
	struct StackNode {

		T data; //where to store data 
		StackNode* next; //points to the next node

	};

	StackNode* top; //starting place

public:
	//default constructor
	DynamicStack() {
		top = nullptr;
	}
	//default destructor
	~DynamicStack() {
		StackNode* nodePtr, * nextNode;
		nodePtr = top;

		while (nodePtr != nullptr) {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}
	//creates a new node and push it to the stack 
	void push(T data) {
		StackNode* newNode; //creates a new node

		newNode = new StackNode;
		newNode->data = data;

		if (!top) { //if the stack is empty, makes the new node the first node
			top = newNode;
			newNode->next = nullptr;
		}
		else { //if the stack is not empty
			newNode->next = top; //points the new node to the previous node
			top = newNode; //make new node the starting place
		}

	}
	//displays the nodes present in the stack
	int displayStack() {
		
		StackNode* nodePtr = top;
		int counter = 0;

		cout << fixed << showpoint << setprecision(2);
		cout << "Displaying the Stack:" << endl;
		while (nodePtr != nullptr) {
			cout << " |" << setw(5) << nodePtr->data << "|" << endl;
			counter++;
			nodePtr = nodePtr->next;
		}
		return counter;
	}
	//pops the value on the top place
	void pop(T &num) {

		StackNode* temp = nullptr;

		if (!top) { //check to see if the stack is empty
			cout << "The stack is empty." << endl;
		}
		else { 
			temp = top->next; //makes temp the previous node
			num = top->data; //to see which value would be popping out
			delete top;//deletes the top
			top = temp;//replacing top with the previous node
		}
	}
	//pops the top 2 nodes in the stack and add them and pushing the sum in the stack
	void add() {
		
		if (top->next == nullptr)
			cout << "Not enough stack to do operation." << endl;
		else {

			T num1, num2;
			StackNode* previousNode = top->next;

			num1 = top->data;
			num2 = previousNode->data;

			delete top;
			top = previousNode->next;
			delete previousNode;

			push(num1 + num2);
		}
	}
	//pops the top 2 nodes in the stack and divide them and pushing the quotient in the stack
	void divide() {

		if (top->next == nullptr)
			cout << "Not enough stack to do operation." << endl;
		
		else {
			T num1, num2;
			T quotient;

			StackNode* previousNode = top->next;

			num1 = top->data;
			num2 = previousNode->data;

			if (num2 == 0)
				cout << "Cannot divide the 2 values of the stack." << endl;
			else {
				delete top;
				top = previousNode->next;
				delete previousNode;
				quotient = num1 / num2;
				push(num1 / num2);
			}
		}
	}
};

#endif

