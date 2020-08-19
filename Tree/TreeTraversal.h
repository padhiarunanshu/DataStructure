/*
 * File : TreeTraversal.cpp
 * author : apadhi
 * data   : 2nd April 2019
 */

#include <iostream>

class TreeTraversal {
  private:
    struct Node {
      int data;
      Node* left;
      Node* right;

      Node(int d) : data(d), left(NULL), right(NULL) {}
    };
    
  public:
    TreeTraversal() = default;
    ~TreeTraversal() = default;

    void createTree(Node* root, int data);

    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);

};
