#include <iostream>
using namespace std;

int main() {
	
	int arr[] = {2, 0, 2, 1, 1, 2, 0, 0, 1, 2, 1, 2};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 0;
	
	for(int i = 0, j = size - 1; i <= j; ) {
		if(arr[i] == 0) {
			swap(arr[i++], arr[k++]);
		} else if (arr[i] == 1) {
			i++;
		} else {
			swap(arr[i],arr[j--]);
		}
	}
	
	for(int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	
	return 0;
}
