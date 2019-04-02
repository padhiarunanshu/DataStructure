
#include <TreeTraversal.h>

TreeTraversal::TreeTraversal() {}
~TreeTraversal::TreeTraversal() {}

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
