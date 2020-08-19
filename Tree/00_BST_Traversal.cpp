/*
 * File : 00_BST_Traversal.cpp
 * author : apadhi
 * data   : 19th August 2020
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

// create a tree!
void create(Node*& root, int x) {
	if(root == NULL) {	
		root = new Node(x);
	} else if(root->data > x) {
		create(root->left, x);
	} else {
		create(root->right, x);
	}
}

// heightOfTree
int heightOfTree(Node* root) {
    if(root == NULL) return 0;
    
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    return 1 + std::max(lh, rh);
}

// Various Tree traversals
// 1. inorder tree traversal
void inorder(Node* root) {
	
	if(root != NULL) {
    	inorder(root->left);
    	cout << root->data << " ";
    	inorder(root->right);
	}
}

// 2. preorder tree traversal
void preorder(Node* root) {
	
	if(root != NULL) {
        cout << root->data << " ";
    	preorder(root->left);
    	preorder(root->right);
	}
}

// 3. postorder tree traversal
void postorder(Node* root) {
	
	if(root != NULL) {
    	postorder(root->left);
    	postorder(root->right);
    	cout << root->data << " ";
	}
}

// 3a. postorder traversal iterative approach (two stacks)
void postorder2stk(Node* root) {
	if(root == NULL) return;
	
	std::stack<Node*> st1;
	std::stack<Node*> st2;
	
	st1.push(root);
	
	while (root != NULL && !st1.empty()) {
		root = st1.top();
		st1.pop();
		
		if(root->left != NULL) st1.push(root->left);
		if(root->right != NULL) st1.push(root->right);
		
		st2.push(root);
	}
	while(!st2.empty()) {
		cout << st2.top()->data << " ";
		st2.pop();
	}
	cout << endl;
}

// 3b. postorder traversal iterative approach (one stack)
void postorder1stk(Node* root) {
	if (root == NULL) return;

	Node* curr = root;
	std::stack<Node*> st;

    while(curr != NULL || !st.empty()) {
    	
		while(curr != NULL) {
			if(curr->right != NULL) {
				st.push(curr->right);
			}
			st.push(curr);
			curr = curr->left;
		}

		curr = st.top();
		st.pop();

		if(curr->right != NULL && !st.empty() && curr->right->data == st.top()->data) {
			st.pop();
			st.push(curr);
			curr = curr->right;
		} else {
			cout << curr->data << " ";
			curr = NULL;
		}
	}
	cout << endl;
}

// 4. level order traversal of a binary tree..
void levelOrderTraversal(Node* root) {
    if(root == NULL) return;
    
    std::queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        root = q.front();
        cout << root->data << " ";
        q.pop();
        
        if(root->left) 
            q.push(root->left);
        if(root->right) 
            q.push(root->right);
    }
    cout << endl;
}

// 4a. level order traversal of a binary tree (without using queue)
void printGivenOrder(Node* root, int level) {
    if(root == NULL) return;
    
    if(level == 1) {
    	cout << root->data << " ";
    } else {
        printGivenOrder(root->left, level-1);
        printGivenOrder(root->right, level-1);
    }
}

void levelOrderTraversalWOQueue(Node* root) {
    if (root == NULL) return;
    
    int height = heightOfTree(root);
    
    for(int i = 1; i <= height; ++i) {
        printGivenOrder(root, i);
    }
}

// --------------------------------------------------------------------------------------

int main() {	
	// your code goes here
	Node* root = NULL;
	create(root, 30);
	create(root, 20);
	create(root, 25);
	create(root, 10);
	create(root, 40);
	create(root, 45);
	create(root, 50);
	create(root, 70);

	cout << "Inorder traversal : ";
	inorder(root); 
	cout << endl;
	
	cout << "Preorder traversal : ";
	preorder(root);
	cout << endl;

	cout << "Postorder traversal : ";
	postorder(root);
	cout << endl;
	
	cout << "Postorder traversal two stacks : ";
	postorder2stk(root);
	
	cout << "Postorder traversal one stacks : ";
	postorder1stk(root);

    // cout << "Level-order traversal using queue : ";
    // levelOrderTraversal(root);

    cout << "Level-order traversal without using queue : ";
    levelOrderTraversalWOQueue(root);
	
	return 0;
}

