/******************************************************************************
 * Program : Implement a stack using templates
*******************************************************************************/
#include <iostream>

using namespace std;

#define MAX 100
// stack data structure. LIFO

template<typename T>
class stack {
 private:
  int top;
  T data[MAX];
 
 public:
   stack() { top = -1; }
   ~stack() {}
   
   bool push(T iData);
   T pop();
   T peek();
   bool isEmpty();
   int getTop() { return top; }

};

template<typename T>
bool stack<T>::push(T iData) {
  bool status = false;
  if(top >= MAX - 1) {
      cout << "Stack overflow\n";
  } else {
     data[++top] = iData;
     status = true;
  }
  return status;
}

template<typename T>
T stack<T>::pop() {
  T res = 0;
  if(top == -1) {
    cout << "Stack underflow\n";
  } else {
    res = data[top--];
  }
  return res;
}

template<typename T>
bool stack<T>::isEmpty() {
  bool empty = false;
  (top == -1) ? empty = true : empty = false;
  return empty;
}

template<typename T>
T stack<T>::peek() {
  return data[top];
}

int main()
{
    stack<int> st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << st.pop() << " | " << st.peek() << endl;
    cout << st.pop() << " | " << st.peek() << endl;
    cout << st.pop() << " | " << st.peek() << endl;

    return 0;
}
