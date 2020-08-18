
int height(Node* root) {
    if( (root == NULL) ||
        (root->left == NULL && root->right == NULL) ) {
        return 0;
    }
            
    int leftH = height(root->left);
    int rightH = height(root->right);

    return ( (leftH > rightH) ? leftH+1 : rightH+1 );
}
