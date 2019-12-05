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
	
	void insert(TreeNode*& nodePtr, TreeNode*& newNode) { //insert a new number in the binary tree

		if (nodePtr == nullptr)
			nodePtr = newNode;
		else if (newNode->value < nodePtr->value)
			insert(nodePtr->left, newNode);
		else
			insert(nodePtr->right, newNode);

	}
	void displayInOrder(TreeNode* nodePtr) { //inorder traversal

		if (nodePtr) {
			displayInOrder(nodePtr->left);
			cout << nodePtr->value << endl;
			displayInOrder(nodePtr->right);
		}
	}

	void destroySubTree(TreeNode* nodePtr) { //for destructor
		if (nodePtr) {
			if (nodePtr->left)
				destroySubTree(nodePtr->left);
			if (nodePtr->right)
				destroySubTree(nodePtr->right);
			delete nodePtr;
		}
	}

	int height(TreeNode* nodePtr) { //return the max height of the tree

		if (nodePtr == nullptr) //base case: no node
			return 0;
		else { //recursive case

			int leftHeight = height(nodePtr->left);  //goes to the left side of the nodes
			int rightHeight = height(nodePtr->right); //goes to the right side of the nodes

			if (leftHeight > rightHeight) //check to see which one has a higher children nodes
				return leftHeight + 1; //if left, then it would return leftHeight (edges) + 1 (root node)
			else
				return rightHeight + 1;//right, then it would return rightHeight (edges) + 1 (root node)
		}
	}
	int width(TreeNode* nodePtr, int level) {

		if (nodePtr == nullptr) //node is null
			return 0;
		if (level == 1) //if level is 1 (root node)
			return 1;

		return width(nodePtr->left, level - 1) + width(nodePtr->right, level - 1); //check the left and right node level
	}
	int widthMax(TreeNode* nodePtr) {

		int level = height(root); // to get the maximum height that will represent the levels
		int max = INT_MIN; //lowest value possible
		
		for (int i = 1; i <= level; i++) { // i = 1 to start at the first level 
			int levelWidth = width(root, i); //check the width of the i level
			if (levelWidth > max) //store the highest width of each levels
				max = levelWidth;
		}
		return max;
	}
public:

	IntBinaryTree() {

		root = nullptr;

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

		displayInOrder(root);
	}

	int height() {

		return height(root);
	}

	int width() {

		return widthMax(root);
	}
};

#endif
