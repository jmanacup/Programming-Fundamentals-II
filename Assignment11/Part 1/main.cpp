//John Manacup
#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

int main() {

	IntBinaryTree binTree; //int binary tree

	cout << "Inserting Nodes." << endl;

	binTree.insertNode(5);
	binTree.insertNode(8);
	binTree.insertNode(3);
	binTree.insertNode(12);
	binTree.insertNode(9);

	cout << "Here are the values in the tree:" << endl;
	binTree.displayInOrder(); //display the values in the tree
	cout << endl << endl;

	cout << "Number of nodes: " << binTree.totalNodes() << endl; //display the total nodes in the tree
	cout << "Number of leaf nodes: " << binTree.leafNodes() << endl << endl; //display the total leaf nodes

	cout << "Deleting 8..." << endl;
	binTree.remove(8);
	cout << "Deleting 12..." << endl << endl;
	binTree.remove(12);

	cout << "Now, here are the nodes in the tree:" << endl;
	binTree.displayInOrder();
	cout << endl << endl;

	cout << "Number of nodes: " << binTree.totalNodes() << endl;
	cout << "Number of leaf nodes: " << binTree.leafNodes() << endl << endl;

	return 0;
}