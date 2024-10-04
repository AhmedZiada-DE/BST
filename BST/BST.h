#pragma once
#include "BSTNode.h"
#include "output.h"
#include "queue"
template <typename T>
class BST
{
private:
	BSTNode<T>* root;
public:
	BST(): root(nullptr){}
	bool isEmpty() {
		return root == nullptr;
	}

	output insert(T value) {
		string path = "Root";
		if (isEmpty()) {
			root = new BSTNode<T>(value);
			return output(true, path);
		}
		auto ptr = root;
		while (ptr->value != value) {
			if (value > ptr->value) {
				if (ptr->right != nullptr) {
					ptr = ptr->right;
					path += "->Right";
				}
				else {
					ptr->right = new BSTNode<T>(value);
					path += "->Right";
					return output(true, path);
				}
			}
			else {
				if (ptr->left != nullptr) {
					ptr = ptr->left;
					path += "->Left";
				}
				else {
					ptr->left = new BSTNode<T>(value);
					path += "->Left";
					return output(true, path);
				}
			}
		}
		return output(false, path);
	}

	output search(T value) {
		if (isEmpty()) {
			return output(false, "Root");
		}
		string path = "Root";
		auto ptr = root;
		while (ptr != nullptr) {
			if (value > ptr->value) {
				path += "->Right";
				if (ptr->right == nullptr) {
					return output(false, path);
				}
				else {
					ptr = ptr->right;
				}
			}
			else if (value < ptr->value) {
				path += "->Left";
				if (ptr->left == nullptr) {
					return output(false, path);
				}
				else {
					ptr = ptr->left;
				}
			}
			else {
				return output(true, path);
			}
		}
		return output(false, path);
	}

	output erase(T value) {
		string path = "Root";
		if (isEmpty()) {
			return output(false, path);
		}
		
		auto ptr = root;
		auto parent = ptr;
		while (ptr != nullptr) {
			if (value > ptr->value) {
				path += "->Right";
				parent = ptr;
				ptr = ptr->right;
			}
			else if (value < ptr->value) {
				path += "->Left";
				parent = ptr;
				ptr = ptr->left;
			}
			else {
				if (ptr->left == nullptr && ptr->right == nullptr) {
					if (ptr == root){
						if (ptr == root) {
							delete root;
							root = nullptr;
							return output(true, path);
						}
					}
					if (ptr == parent->left) {
						delete ptr;
						parent->left = nullptr;
						return output(true, path);
					}
					else {
						delete ptr;
						parent->right = nullptr;
						return output(true, path);
					}
				}
				else if (ptr->left == nullptr || ptr->right == nullptr) {
					
					if (ptr == root) {
						if (ptr->left != nullptr) {
							root = root->left;
						}
						else {
							root = root->right;
						}
						delete ptr;
						return output(true, path);
					}

					if (ptr == parent->right) {
						if (ptr->right != nullptr) {
							parent->right = ptr->right;
							delete ptr;
							return output(true, path);
						}
					}
					else {
						if (ptr->left != nullptr) {
							parent->left = ptr->left ;
							delete ptr;
							return output(true, path);
						}
					}
				}
				else  {
					auto biggestLeft = ptr->left;
					while (biggestLeft->right != nullptr) {
						biggestLeft = biggestLeft->right;
					}
					ptr->value = biggestLeft->value;
					value = biggestLeft->value;
					parent = ptr;
					ptr = ptr->left;
					path += "->left";
				}

			}
		}
		return output(false, path);
	}

	void DFS(BSTNode<T>* ptr) {
		/*auto ptr = root;*/
		if (ptr == nullptr) {
			return;
		}
		cout << ptr->value << " ";  //preorder
		DFS(ptr->left);
		DFS(ptr->right);
	}
	void displayDFS() {
		DFS(root);
	}

	void BFS(){
		queue<BSTNode<T>*> queueBST;

		queueBST.push(root);
		while (!queueBST.empty()) {
			BSTNode<T>* frontNode = queueBST.front();
			if (frontNode->left != nullptr) {
				queueBST.push(frontNode->left);
			}

			if (frontNode->right != nullptr) {
				queueBST.push(frontNode->right);
			}
			cout << frontNode->value << " ";
			queueBST.pop();
		}
	}

	void insertDFS(BSTNode<T>* ptr) {
		if (ptr == nullptr) {
			return;
		}
		insert(ptr->value);
		insertDFS(ptr->left);
		insertDFS(ptr->right);
	}
	BST(const BST& copyBST) {
		root = nullptr;
		auto ptr = copyBST.root;
		insertDFS(ptr);
	}
	void operator=(BST copyBST) {
		while (!isEmpty()) {
			//cout << root->value << " ";
			erase(root->value);
		}
		root = nullptr;
		auto ptr = copyBST.root;
		insertDFS(ptr);
	}

	~BST(){
		while (!isEmpty()) {
			cout << root->value << " ";
			erase(root->value);
		}
	}
};

