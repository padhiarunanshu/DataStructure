
#include <TreeTraversal.h>
#include <queue>
#include <stack>

void TreeTraversal::create(Node*& root, int data) {
    if(root == NULL) {    
        root = new Node(data);
    } else if(root->data > data) {
        create(root->left, data);
    } else {
        create(root->right, data);
    }
}

void TreeTraversal::inorder(Node* root) {	
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void TreeTraversal::preorder(Node* root) {	
    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void TreeTraversal::postorder(Node* root) {	
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";

    }
}

void TreeTraversal::postorder1stk(Node* root) {
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

void TreeTraversal::postorder2stk(Node* root) {
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

void TreeTraversal::levelOrderTraversal(Node* root) {
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

void printGivenOrder(Node* root, int level) {
    if(root == NULL) return;
    
    if(level == 1) {
    	cout << root->data << " ";
    } else {
        printGivenOrder(root->left, level-1);
        printGivenOrder(root->right, level-1);
    }
}

void TreeTraversal::levelOrderTraversalWOQueue(Node* root) {
    if (root == NULL) return;
    
    int height = heightOfTree(root);
    
    for(int i = 1; i <= height; ++i) {
        printGivenOrder(root, i);
    }
}
