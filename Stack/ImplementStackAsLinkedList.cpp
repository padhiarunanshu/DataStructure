// Linked-list implementation of stack
// reverse a stack without extra space

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	
	Node(int iData) : data (iData), next(NULL) {}
};

class Stack {
  private:
    Node* head;
    
  public:
  	
    Stack() : head(NULL) {}
    
    ~Stack() { delete head; }
    
    void push(int data);
    void pop();
    int top();
    void reverse();
};

void Stack::push(int data) {
	if (head == NULL) {
		head = new Node(data);
	} else {
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
		temp = NULL;
	}
}

void Stack::pop() {
	if(head == NULL) {
		cout << "Stack under-flow \n";
	} else {
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
}

int Stack::top() {
	int val = -1;
	
	(head != NULL) ? val = head->data : val = -1;
	
	return val;
}

// reverse a stack without extra space.
void Stack::reverse() {
	Node* curr, *prev, *next;
	curr = head;
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	head = prev;
}

int main() {
	
	Stack s;
	
	s.push(50);
	s.push(20);
	s.push(40);
	s.push(30);
	s.push(10);
	
	s.reverse();
	
	cout << "Popped item is : " << s.top() << endl;
	s.pop();
	cout << "Popped item is : " << s.top() << endl;
	s.pop();
	cout << "Popped item is : " << s.top() << endl;
	s.pop();
	cout << "Popped item is : " << s.top() << endl;
	s.pop();
	cout << "Popped item is : " << s.top() << endl;
	 
	return 0;
}
