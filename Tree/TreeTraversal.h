/*
 * File : TreeTraversal.cpp
 * author : apadhi
 * data   : 2nd April 2019
 */

#include <iostream>

class TreeTraversal {
  public:
    struct Node {
      int data;
      Node* left;
      Node* right;

      Node(int d) : data(d), left(NULL), right(NULL) {}
    };
  
    TreeTraversal() = default;
    ~TreeTraversal() = default;

    void createTree(Node* root, int data);

    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    void postorder1stk(Node* root);
    void postorder2stk(Node* root);
    void levelOrderTraversal(Node* root);
    void levelOrderTraversalWOQueue(Node* root);

};
