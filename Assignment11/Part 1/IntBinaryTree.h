#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

#include <iostream>

using namespace std;

class IntBinaryTree {
private:
	struct TreeNode {

		int value;
		TreeNode* left;
		TreeNode* right;

	};

	TreeNode* root;
	int totalCount; //counts the total number of nodes in the binary tree

	void insert(TreeNode*& nodePtr, TreeNode*& newNode) {

		if (nodePtr == nullptr)
			nodePtr = newNode;
		else if (newNode->value < nodePtr->value)
			insert(nodePtr->left, newNode);
		else
			insert(nodePtr->right, newNode);

	}
	void displayInOrder(TreeNode* nodePtr) {

		if (nodePtr) {
			displayInOrder(nodePtr->left);
			cout << nodePtr->value << endl;
			totalCount++;
			displayInOrder(nodePtr->right);
		}
	}
	int leafNode(TreeNode* nodePtr){

		if (nodePtr == nullptr) //if node is null
			return 0;
		else if (nodePtr->left == nullptr && nodePtr->right == nullptr) //condition to check if the left and right pointers of the node is null
			return 1;
		else
			return leafNode(nodePtr->left) + leafNode(nodePtr->right); //passes the left and right pointers of the each nodes and add them

	}

	void destroySubTree(TreeNode* nodePtr) {
		if (nodePtr) {
			if (nodePtr->left)
				destroySubTree(nodePtr->left);
			if (nodePtr->right)
				destroySubTree(nodePtr->right);
			delete nodePtr;
		}
	}

	void deleteNode(int num, TreeNode*& nodePtr) {
		if (num < nodePtr->value)
			deleteNode(num, nodePtr->left);
		else if (num > nodePtr->value)
			deleteNode(num, nodePtr->right);
		else
			makeDeletion(nodePtr);
	}
	void makeDeletion(TreeNode*& nodePtr) {

		TreeNode* tempNodePtr = nullptr;

		if (nodePtr == nullptr)
			cout << "Cannot delete empty node." << endl;
		else if (nodePtr->right == nullptr) {
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left;
			delete tempNodePtr;
		}
		else if (nodePtr->left == nullptr) {
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
		}
		else {
			tempNodePtr = nodePtr->right;
			while (tempNodePtr->left)
				tempNodePtr = tempNodePtr->left;
			tempNodePtr->left = nodePtr->left;
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
		}
	}

public:

	IntBinaryTree() {
		root = nullptr;
		totalCount = 0;
	}
	~IntBinaryTree() {
		destroySubTree(root);
	}

	void insertNode(int num) {

		TreeNode* newNode = nullptr;

		newNode = new TreeNode;
		newNode->value = num;
		newNode->left = newNode->right = nullptr;

		insert(root, newNode);

	}
	void displayInOrder() {
		totalCount = 0;
		displayInOrder(root);
	}
	int totalNodes() {
		return totalCount; //return the totalCount value CONDITION: displayInOrder should be called first
						   //since they are of the same code, I just put it in displayInOrder
	}
	int leafNodes() {
		return leafNode(root);
	}
	void remove(int num) {
		deleteNode(num, root);
		totalCount--; //lessen the node by 1
	}
};


#endif
