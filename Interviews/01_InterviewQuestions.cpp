// Trapping rain water.cpp 
#include <iostream>
using namespace std;

int trapped_water(int array[],int size){
    int amount = 0;
    int left[size],right[size];
    left[0] = array[0]; right[size-1] = array[size-1];
    for(int i = 1; i < size; i++){
        left[i] = max(left[i-1],array[i]);
    }
    for(int i = size-2; i >=0; i--){
        right[i] = max(right[i+1],array[i]);
    }
    for(int i = 0  ; i < size;i++){
        amount += min(left[i],right[i]) - array[i];
    }
    return  amount;
}

int main(){
    int array[] = {1,0,3,4,5,0,5,7,7,8,9,0};
    int size = sizeof(array) / sizeof(int);
    cout << trapped_water(array,size);
    return  0;
}

// 31  C++/Dynamic Programming/Longest Common Substring.cpp 
#include <iostream>
using namespace std;

int longest_common_substring(string x,string y){
    int m =  x.size();
    int n =  y.size();
    int lcs[m+1][n+1];
    for(int i = 0 ; i < m; i++){
        lcs[i][0] = 0;
    }
    for(int j = 0; j < n; j++){
        lcs[0][j] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <=n; j++){
            if(x[i-1] == y[j-1]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else{
                lcs[i][j] = 0;
            }
        }
    }
    return lcs[m][n];
}
int main(){
    string x,y;
    cin >> x >> y;
    cout << longest_common_substring(x,y);
    return 0;
} 

// 27  C++/Dynamic Programming/Longest palindromic Subsequence.cpp 
#include <iostream>
using namespace std;
int longest_palindromic_subsequence(string str){
    int table[str.size()][str.size()];
    for(int i = 0 ; i < str.size(); i++){
        table[i][i] = 1;
    }
    for(int l = 1 ; l < str.size() ; l++){
        int i = 0, j = l;
        while(j != str.size()){
            if(str[i] == str[j]){
                table[i][j] = 2 + table[i+1][j-1];
            }
            else{
                table[i][j] = max(table[i+1][j],table[i][j-1]);
            }
            i++;j++;
        }
    }
    return table[0][str.size()-1];
}
int main(){
    string str;
    cin >> str;
    cout << longest_palindromic_subsequence(str);
    return  0;
} 

// 31  C++/Heaps - Priority Queues/K-th Largest element of the stream.cpp 
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,k;
    priority_queue<int,vector<int>,greater<int>>Q;
    cout << "Enter the the value of K : ";
    cin >> k;
    while(cin >> n){
        cout << k << "-th largest element of the stream : ";
        if(Q.size() < k){
            Q.push(n);
            if(Q.size() == k){
                cout  << Q.top() 3<< endl;
            }
            else{
                cout << "NULL" << endl;
            }
        }
        else{
            if(Q.top() < n){
                Q.pop();
                Q.push(n);
            }
            cout << Q.top() << endl;
        }
        cout << "Enter next element of the stream : ";
    }
    return  0;
}

// 3  C++/Linked List/Reverse a linked list recursively.cpp 
// void reverse_list(list_node *head){
//     list_node *
// }

// 19  C++/Recursion/Partition of array on the pivot.cpp 
#include<iostream>
using namespace std;
void partition(int array[],int low,int high){
    int i = low-1, pivot = array[high-1];
    for(int j = low ; j < high ; j++){
        if(array[j] <= pivot){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[high-1]);
}
int main(){
    int n;
    cin >> n;
    int array[n];
    partition(array,0,n);
    return 0;
}

// 23  C++/Recursion/Permutation of a string.cpp 
#include <iostream>
using namespace std;

void permutation(char str[],int k,int n){
    if(k == n){
        for(int j = 0; j < n; j++){
            cout << str[j];
        }
        cout << endl;
    }
    else{
        for(int i = k ; i < n; i++){
            swap(str[i],str[k]);
            permutation(str,k+1,n);
            swap(str[i],str[k]);
        }
    }
}

int main(){
    char str[] = {'A','B','C','D'};
    permutation(str,0,4);
    return  0;
}

// 86  C++/Stacks - Queue/CircularQueue.cpp 

#include <iostream>
using namespace std;
class circular_queue
{
	private :
		int *array ;
		int front, back ;
		int MAX;
	public :
		circular_queue( int maxsize = 10 ) ;
		void enqueue ( int item ) ;
		int dequeue( ) ;
		void display( ) ;
} ;

circular_queue :: circular_queue( int maxsize )
{
	MAX = maxsize ;
	array = new int [ MAX ];
	front = back = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
		array[i] = 0 ;
}
void circular_queue :: enqueue(int item){
	if((back+1)%MAX == front){
		cout << "Queue is full" << endl;
		return ;
	}
	back = ( back + 1 ) % MAX;
	array[back] = item ;
	if ( front == -1 )
		front = 0 ;
}
int circular_queue :: dequeue(){
	int data ;
	if ( front == -1 )
	{
		cout << "\nQueue is empty" ;
		return NULL ;
	}

	data = array[front] ;
	array[front] = 0 ;
	if ( front == back )
	{
		front = -1 ;
		back = -1 ;
	}
	else
		front = ( front + 1 ) % MAX;
	return data ;
}
void circular_queue :: display()
{
	cout << endl ;
	for ( int i = 0 ; i < MAX ; i++ )
		cout << array[i] << "  " ;
	cout << endl ;
}

int main(){
	circular_queue cq(10) ;
	cq.enqueue(14);
	cq.enqueue(22);
	cq.enqueue(13);
	cq.enqueue(-6);
	cq.enqueue(25);
	cout << "\nElements in the circular queue: " ;
	cq.display();
	int i = cq.dequeue() ;
	cout << "Item deleted: " << i ;
	i = cq.dequeue();
	cout << "\nItem deleted: " << i ;
	cout << "\nElements in the circular queue after deletion: " ;
	cq.display();
	cq.enqueue(21);
	cq.enqueue(17);
	cq.enqueue(18);
	cq.enqueue(9);
	cq.enqueue(20);
	cout << "Elements in the circular queue after addition: " ;
	cq.display();
	cq.enqueue(32);
	cout << "Elements in the circular queue after addition: " ;
	cq.display();
	return 0;
}
