#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
  public:
    MinStack() = default;
    ~MinStack() = default;

    void push(int a) {
      item.push(a);
      if(minItem.empty())
        minItem.push(a);
      else {
        int m = min(a, minItem.top());
        minItem.push(m);
      }
    }

    void pop() {
      if(item.empty()) {
      	cout << "pop(item)::Stack underflow\n";
      }
      item.pop();
      
      if(minItem.empty()) {
      	cout << "pop(minItem)::Stack underflow\n";
      }
      minItem.pop();
    }

    int top() {
      if(item.empty()) {
      	return 0;
      }
      return item.top();
    }

    int getMin() {
      if(minItem.empty()) {
      	return 0;
      }
      return minItem.top();
    }

  private:
    std::stack<int> item;
    std::stack<int> minItem;
};

int main() {
	// your code goes here
	MinStack mStack;
	
	mStack.push(5);
	mStack.push(8);
	mStack.push(4);
	mStack.push(6);
	mStack.push(3);
	mStack.push(9);
	mStack.push(11);
	mStack.push(3);
	
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	cout << mStack.getMin() << endl;
	mStack.pop();
	
	cout << "----\n";
	
	cout << mStack.getMin() << endl;
	mStack.pop();
	
	return 0;
}