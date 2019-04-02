/*
 * File : TreeTraversal.cpp
 * author : apadhi
 * data   : 2nd April 2019
 */
 
#ifdef DTS_TREETRAVERSAL_H
#define DTS_TREETRAVERSAL_H

#include <iostream>

class TreeTraversal {
  private:
    struct Node {
      int data;
      Node* left;
      Node* right;
    };
    
  public:
    TreeTraversal(){}
    ~TreeTraversal(){}

    void createTree(Node* root, int data);

    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    void postorder1stk(Node* root);
    void postorder2stk(Node* root);

};

#endif
