#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include <iostream>

using namespace std;

template <class T>
class DynamicQueue {
private:
	struct QueueNode {

		T data; //used to store value of the queue
		QueueNode* next;
	};

	QueueNode* front;
	QueueNode* rear;
	int numItems; //number of nodes in the queue

public:
	//default constructor
	DynamicQueue() {
		front = nullptr;
		rear = nullptr;
		numItems = 0;
	}
	//destructor
	~DynamicQueue() {
		T value;
		while(numItems > 0)
			dequeue(value);
	}
	//put a value in the queue accordingly
	void enqueue(T data) {

		QueueNode* newNode = nullptr; //creates a new node

		newNode = new QueueNode;
		newNode->data = data;
		newNode->next = nullptr;
		
		if (numItems == 0) { //check to see if the queue is empty
			front = newNode;
			rear = newNode;
		}
		
		else {

			rear->next = newNode;
			rear = newNode;
			
		}
		
		numItems++; //increment the number of items in the queue
	}
	//removes a value in the queue accordingly
	void dequeue(T& value) {

		QueueNode* temp = nullptr;

		if (numItems == 0) //check to see if the queue is empty
			cout << "The queue is empty" << endl;

		else {
			
			value = front->data;

			temp = front;
	
			front = front->next;
	
			delete temp;
		
			numItems--; //removes one count of item in the queue 

		}
	}
	//displays the queue accordingly
	void displayQueue() {

		QueueNode* nodeptr = front;

		while (nodeptr) {

			cout << nodeptr->data << endl;
			nodeptr = nodeptr->next;
		}
	}

};

#endif
