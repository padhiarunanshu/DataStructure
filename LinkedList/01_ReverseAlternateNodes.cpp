/* 
 * Program: Reverse alternate nodes and append at the end in a SLL.
 * input : 1->2->3->4->5->6->7->>
 * output: 1->3->5->7->6->4->2->>
 */
 
// #include <stdio.h>
#include <iostream>

using namespace std;

// self referencial structure
struct Node {
  int data;
  struct Node* next;
  
  Node(int d) : data(d), next(NULL) {}
};

void insert(Node*& head, int data) {
    if(head == NULL) {
      cout << "Initialize the list using Node constructor\n";
      return;
    }
    Node* temp = new Node(data);
    head->next = temp;
    head = temp;
    temp = NULL;
}

void displayList(Node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << ">";
}

void reverseAlternateNodes(Node* head) {
    if(!head || !head->next) 
    	return;
    
    Node* temp = head;
    Node* odd  = head;
    Node* even = head->next;
    Node* e2 = NULL;

	// logic to be corrected for odd number of elements.    
    while(odd->next != NULL && even->next != NULL) {
        odd->next = even->next;
        if(odd->next) {
          odd = odd->next;
          even->next = e2;
          e2 = even;
          even = odd->next;
        }
    }
    
    if(even->next == NULL) even->next = e2;
    odd->next = even;
}

void rearrange(Node* odd)
{
    if (odd == NULL || odd->next == NULL || odd->next->next == NULL)
        return;
    Node *even = odd->next;
    odd->next = odd->next->next;
    odd = odd->next;
    even->next = NULL;
 
    while (odd && odd->next)
    {
       Node *temp = odd->next->next;
       odd->next->next = even;
       even = odd->next;
 
       // Remove the even node from middle
       odd->next = temp;
 
       if (temp != NULL)
         odd = temp;
    }
    odd->next = even;
}


int main()
{
    Node* head = new Node(1);
    Node* temp = head;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    // insert(head, 8);
    head = temp;
    
    displayList(head);
    cout << endl;
    
    // logic not working for odd number of elements. To be checked.
    // reverseAlternateNodes(head);
    
    // this logic is working for all 
    rearrange(head);
    
    displayList(head);
    
    return 0;
}
