#ifndef NUMBERLIST_H //ifndef guard
#define NUMBERLIST_H

#include <iostream>
#include <iomanip>

using namespace std;

class NumberList {

private:

	struct ListNode {
	
		double value; //data
		ListNode* next; //pointer to the next node
	};

	ListNode* head; //first node

public:

	NumberList() {
		head = nullptr;
	} //default constructor

	~NumberList() {
		
		ListNode* nodePtr;
		ListNode* nextNode;

		nodePtr = head;

		while (nodePtr != nullptr) {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}

	} //default destructor

	//Precondition : a double data as its paramater;
	//Postcondition: adds a node each time it is called in the main function 
	void appendNode(double data) {

		ListNode* newNode;
		ListNode* nodePtr;

		newNode = new ListNode;
		newNode->value = data;
		newNode->next = nullptr;

		if (!head) //head == null
			head = newNode;

		else {

			nodePtr = head;

			while (nodePtr->next) //walks through the very end
				nodePtr = nodePtr->next;

			nodePtr->next = newNode; //add the new node
		}

	}

	//Precondition : Linkedlist may/may not be initialized
	//Postcondition: display the nodes accordingly
	double displayList() const {

		ListNode* nodePtr;
		double total= 0; //total of the nodes values
		int counter = 0; //counts the total nodes

		if (!head)
			cout << "No values in the list." << endl;

		else {

			nodePtr = head;

			while (nodePtr) {
				total += nodePtr->value; //adds up the nodes
				counter++; //adds 1 to the counter
				cout << nodePtr->value << " "; //prints out the value
				nodePtr = nodePtr->next;

			}

		}

		return total/counter; //return the average of the nodes
	}

	//Precondition : a double data type as its parameter
	//Postcondition: delete the indicated node if in the linked list
	void deleteNode(double data) {

		ListNode* nodePtr;
		ListNode* previousNode = nullptr;

		if (!head) // if its empty, then it returns nothing
			return;

		if (head->value == data) { //if it is in the first one

			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}

		else {

			nodePtr = head;

			while (nodePtr != nullptr && nodePtr->value != data) { //traverse until it is still not the actual node value

				previousNode = nodePtr;
				nodePtr = nodePtr->next;

			}

			if (nodePtr) { //if found, it will delete that node and make the previous node points to the next node
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}

	//Precondition : min and max has been declared and are set to be pass by reference
	//Postcondition: sets the min and max values on the linked list
	void maxAndMin(double& min, double& max) {

		ListNode* nodePtr;
		ListNode* minNode = nullptr;
		ListNode* maxNode = nullptr;

		max = 0; //set both initially to the first value
		min = 100; //

		nodePtr = head;

		while (nodePtr != nullptr) {
			if (max < nodePtr->value) { //test to see if greater
				max = nodePtr->value;
				maxNode = nodePtr;
			}
			 if (min > nodePtr->value) { //test to see if lesser
				min = nodePtr->value;
				minNode = nodePtr;
			}

			nodePtr = nodePtr->next; //goes through the next node
		}
		//prints max and min with their respective address
		cout << "   Highest value: " <<setw(3) << max << " Highest address: " << maxNode << endl;
		cout << "   Lowest value : " <<setw(3) << min << " Lowest address : " << minNode << endl;

	}
	
	//Precondition : min has been initialized
	//Postcondition: delete the indicated node and inserts a new node
	void changeNode(double min) {

		ListNode* nodePtr;
		ListNode* previousNode = nullptr;
		ListNode* newNode; // new node

		newNode = new ListNode;
		newNode->value = 70;
		
		if (!head) //head == null
			return;
		
		if (head->value == min) { //if the indicated node is in the first of the list
			newNode->next = head->next;
			delete head;
			head = newNode;
		}
		else {

			nodePtr = head;

			while (nodePtr != nullptr && nodePtr->value != min) { //traverse until it finds the actual min value

				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (nodePtr) { //if it is not null
				previousNode->next = newNode; //points the previous to the next node
				newNode->next = nodePtr->next; //points the new node to the next node
				delete nodePtr; //delete the node
				
			}
		}
		//prints the address of the node
		cout << "   Address of the new node with the lowest value: " << newNode << endl;
	}
};


#endif