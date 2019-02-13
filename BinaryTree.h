#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;


template <class T>
class BinaryTree {
private:
	struct TreeNode {
		T value;
		TreeNode* left;
		TreeNode* right;
	};
	TreeNode* root;

	//private:

	void idisplay(TreeNode* node) {
		if (node != nullptr) {
			if (node->left != nullptr) idisplay(node->left);
			cout << node->value << endl;
			if (node->right != nullptr) idisplay(node->right);
		}
	}

	void prdisplay(TreeNode* node) {
		if (node != nullptr) {
			cout << node->value << endl;
			if (node->left != nullptr) prdisplay(node->left);
			if (node->right != nullptr) prdisplay(node->right);
		}
	}

	void podisplay(TreeNode* node) {
		if (node != nullptr) {
			if (node->left != nullptr) podisplay(node->left);
			if (node->right != nullptr) podisplay(node->right);
			cout << node->value << endl;
		}
	}

	int getsize(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			return getsize(node->left) + getsize(node->right) + 1;
		}
	}

	int getheight(TreeNode* node) {
		if (node->left == nullptr && node->right == nullptr)
			return 0;
		else {
			return max(getheight(node->left), getheight(node->right));
		}
	}

	int getwidth(TreeNode* node, int level) {
		if (root != nullptr) {
			if (level == 1) return 1;
			return getwidth(node->left, level - 1) + getwidth(node->right, level - 1);
		}
		return 0;
	}

	int getleafsize(TreeNode* node) {
		if (node == nullptr) return 0;
		if (node->left == nullptr && node->right == nullptr)
			return 1;
		else {
			return getleafsize(node->left) + getleafsize(node->right);
		}
	}

	void insertNode(TreeNode *&nodeptr, TreeNode *&newNode) {
		if (nodeptr == nullptr)
			nodeptr = newNode;
		else if (newNode->value < nodeptr->value)
			insertNode(nodeptr->left, newNode);
		else
			insertNode(nodeptr->right, newNode);
	}

	void deleteNode(T item, TreeNode *&nodeptr) {
		if (item < nodeptr->value)
			deleteNode(item, nodeptr->left);
		else if (item > nodeptr->value)
			deleteNode(item, nodeptr->right);
		else
			makeDeletion(nodeptr);
	}

	void makeDeletion(TreeNode *&nodeptr) {
		TreeNode *tempNodePtr = nullptr;
		if (nodeptr == nullptr)
			cout << "Cannot delete empty node.\n";
		else if (nodeptr->right == nullptr) {
			tempNodePtr = nodeptr;
			nodeptr = nodeptr->left;
			delete tempNodePtr;
		}
		else if (nodeptr->left == nullptr) {
			tempNodePtr = nodeptr;
			nodeptr = nodeptr->right;
			delete tempNodePtr;
		}
		else {
			tempNodePtr = nodeptr->right;
			while (tempNodePtr->left)
				tempNodePtr = tempNodePtr->left;
			tempNodePtr->left = nodeptr->left;
			tempNodePtr = nodeptr;
			nodeptr = nodeptr->right;
			delete tempNodePtr;
		}
	}

public:
	BinaryTree<T>() {
		root = nullptr;
	}

	bool isEmpty() const {
		return root == nullptr;
	}

	void inOrder() {
		idisplay(root);
	}

	void preOrder() {
		prdisplay(root);
	}


	void postOrder() {
		podisplay(root);
	}


	void insert(T nvalue) {
		/*TreeNode *newNode = nullptr;
		newNode = new TreeNode();
		newNode->value = nvalue;
		newNode->left = nullptr;
		newNode->right = nullptr;
		int check;
		if (isEmpty()) root = newNode;
		else {
		TreeNode  *temp = root;


		while (temp != nullptr) {
		if (newNode->value < temp->value) {
		if (temp->left != nullptr)temp = temp->left;
		else {
		check = 0;
		break;
		}
		}
		else {
		if (temp->right != nullptr) temp = temp->right;
		else {
		check = 1;
		break;
		}
		}
		}
		if (check == 0) {
		temp->left = newNode;
		}
		else {
		temp->right = newNode;
		}

		}*/
		TreeNode *newNode = nullptr;

		newNode = new TreeNode; //try to implicit deleted constructor of struct treenode. I ve asked professor and TA but no solution
		newNode->value = nvalue;
		newNode->left = newNode->right = nullptr;

		insertNode(root, newNode);
	}

	int findif(T t) {
		TreeNode* current;
		current = root;

		while (current != nullptr) {
			if (current->value == t) {
				cout << current->value << endl;
				return 1;
			}
			if (current->value <= t) current = current->right;
			else current = current->left;
		}
		return 0;
	}

	void remove(T dvalue) {
		/*int flag = 0;
		if (isEmpty()) {
		cout << "Error - Tree is empty!" << endl;
		return;
		}

		TreeNode* current;
		TreeNode* parent;
		current = root;
		parent = current;

		while (current != nullptr) {
		if (current->value == dvalue) {
		flag = 1;
		break;
		}
		parent = current;
		if (current->value <= dvalue) current = current->right;
		else current = current->left;
		}
		if (!flag) {
		return;
		}

		if (current->left == nullptr && current->right != nullptr) {
		if (parent->left == current) {
		parent->left = current->right;
		}
		else {
		parent->right = current->right;
		}
		}
		else if (current->left != nullptr && current->right == nullptr) {
		if (parent->left == current) {
		parent->left = current->left;
		}
		else {
		parent->right = current->left;
		}
		}
		else if (current->left == nullptr && current->right == nullptr) {
		if (parent->left == current) {
		parent->left = nullptr;
		}
		else {
		parent->right = nullptr;
		}
		}
		else if (current->left != nullptr && current->right != nullptr) {
		TreeNode* temp;
		TreeNode* ptemp;
		temp = current->right;
		ptemp = current;
		while (temp->left != nullptr) {
		ptemp = temp;
		temp = temp->left;
		}
		current->value = temp->value;
		if (ptemp != current) ptemp->left = nullptr;
		else current->right = nullptr;
		}*/
		deleteNode(dvalue, root);
	}

	int size() {
		return getsize(root);
	}

	int height() {
		return getheight(root);
	}

	int width() {
		int maxwidth = 0;
		int height = this->height();
		for (int i = 1; i <= height; i++) {
			maxwidth = max(maxwidth, getwidth(root, i));
		}
		return maxwidth;
	}

	int leafsize() {
		return getleafsize(root);
	}

};

#endif
