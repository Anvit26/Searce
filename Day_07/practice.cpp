#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};
Node* root = nullptr;

void insetNode(int data) {
	Node* tmpNode = new Node();
	Node* curr;
	Node* parent;

	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;

	if (root == nullptr) {
		root = tmpNode;
	}
	else {
		curr = root;
		parent = nullptr;
		while (1) {
			parent = curr;
			if (data < curr->data) {
				curr = curr->left;

				if (curr == nullptr) {
					parent->left = tmpNode;
					return;
				}
			}
			else {
				curr = curr->right;
				if (curr == nullptr) {
					parent->right = tmpNode;
					return;
				}
			}
		}
	}
}

Node* searchNode(int key) {
	Node* curr = root;
	while (curr->data != key) {
		if (curr != NULL) {
			cout << curr->data<<" ";
		}

		if (curr->data > key) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}

		if (curr == nullptr) {
			return nullptr;
		}
		return curr;
	}
}

// left, root, right
void inOrder(Node* localRoot) {
	if (localRoot != nullptr) {
		inOrder(localRoot->left);
		cout << localRoot->data<<" ";
		inOrder(localRoot->right);
	}
}

// root, left, right
void preOrder(Node* localRoot) {
	if (localRoot != nullptr) {
		cout << localRoot->data << " ";
		preOrder(localRoot->left);
		preOrder(localRoot->right);
	}
}

// left, right, root
void postOrder(Node* localRoot) {
	if (localRoot != nullptr) {
		postOrder(localRoot->left);
		postOrder(localRoot->right);
		cout << localRoot->data << " ";
	}
}

int main(){
    const int s = 7;
	int arr[s]{ 27,35,31,42,14,10,19 };
	cout << "My ARR: \n";
	for (int i = 0; i < s; i++) {
		cout << arr[i]<<" ";
		insetNode(arr[i]);
	}
	cout << endl<<"inOrder: " << endl;
	inOrder(root);
	cout << endl <<"preOrder: " << endl;
	preOrder(root);
	cout << endl<<"postOrder: " << endl;
	postOrder(root);
	return 0;
}