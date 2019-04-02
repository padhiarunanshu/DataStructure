/*
 * File : TreeTraversal.cpp
 * author : apadhi
 * data   : 2nd April 2019
 */
 
#ifdef DTS_TREETRAVERSAL_H
#define DTS_TREETRAVERSAL_H

#include <iostream>

class TreeTraversal {
  public:
    TreeTraversal();
    ~TreeTraversal();
    
    void createTree();
    
    void preorder();
    void inorder();
    void postorder();
    void postorder1stk();
    void postorder2stk();
    

  private:
    struct Node {
      int data;
      Node* left;
      Node* right;
    };
};

#endif
