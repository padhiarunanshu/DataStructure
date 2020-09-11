/*
 * File : 00_BST_Construction.cpp
 * author : apadhi
 * data   : 11th September 2020
 */

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int d) : data(d), left(NULL), right(NULL) {}
};

void inorder(Node* root) {	
	if(root != NULL) {
    	inorder(root->left);
    	cout << root->data << " ";
    	inorder(root->right);
	}
}

// 01. Construct a BST from a given pre-order traversal.
Node* constructTreeUtil(const vector<int>& v, int& idx, int data, int min, int max, int size) {
    if(idx > size) return NULL;

    Node* root = NULL;
    if(data > min && data < max) {
        root = new Node(data);
        idx++;

        if(idx < size) {
            root->left = constructTreeUtil(v, idx, v[idx], min, root->data, size);
            root->right = constructTreeUtil(v, idx, v[idx], root->data, max, size);
        }
    }
    return root;
}

Node* constructTree(const vector<int>& v, int size) {
    int idx = 0;
    return constructTreeUtil(v, idx, v[idx], INT_MIN, INT_MAX, size);
}

/**********************************/
int main() {
    vector<int> vec{10, 5, 1, 7, 40, 50};
    Node *root = constructTree(vec, vec.size());  
  
    cout << "Inorder traversal of the constructed tree: \n";  
    inorder(root);  

	return 0;
}

/**********************************/