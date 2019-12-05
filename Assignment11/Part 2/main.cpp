//John Manacup
#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

int main() {

	IntBinaryTree binTree; //binary tree created

	cout << "Inserting 14 values to the tree..." << endl;

	binTree.insertNode(1);
	binTree.insertNode(2);
	binTree.insertNode(9);
	binTree.insertNode(21);
	binTree.insertNode(4);
	binTree.insertNode(17);
	binTree.insertNode(99);
	binTree.insertNode(15);
	binTree.insertNode(98);
	binTree.insertNode(100);
	binTree.insertNode(3);
	binTree.insertNode(5);
	binTree.insertNode(6);
	binTree.insertNode(10);

	cout << "Displaying the values in the tree:" << endl;
	binTree.displayInOrder(); //display the order of the tree
	cout << endl << endl;

	cout << "Tree Height is: " << binTree.height() << endl; //tree height
	cout << "Tree Width is : " << binTree.width() << endl; //tree width
 

	return 0;
}