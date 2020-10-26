#include <iostream>
#include <vector>

using namespace std;



class List {

// Node* head;

public:
    struct Node {
        int data;
        Node* next;
    
        Node(int d) : data(d), next(NULL) {}
    };
    
    Node* create(Node* head, const std::vector<int>& items);

    void display(Node* head);
};

List::Node* List::create(List::Node* head, const std::vector<int>& items) {
    Node* temp = NULL, *temp1 = NULL;
    
    for(int item : items) {
        temp = new Node(item);
        if(head == NULL) {
            head = temp1 = temp;
        } else {
        	head->next = temp;
            head = temp;
        }
    }
    
    return temp1;
};

void List::display(Node* head) {
	while (head != NULL) {
		cout << head->data << "->" ;
		head = head->next;
	}
	cout << "NULL";
}

int main() {
	List s;
	vector<int> v{1, 2, 3, 4, 5};
	
	List::Node* head = NULL;
	head = s.create(head, v);

	s.display(head);
	
	return 0;
}