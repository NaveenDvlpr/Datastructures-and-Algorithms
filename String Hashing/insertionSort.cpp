#include<iostream>
using namespace std;

void insertionSort(int n, int arr[]) {
	for(int i = 1; i < n; i++) {
		int val = arr[i], j;
		for(j = i-1; j >= 0 && val < arr[j]; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = val;
	}
}

int main() {
	int arr[7] = {6,2,4,1,5,7,3};
	insertionSort(7, arr);
	for(int i = 0; i < 7; i++) cout << arr[i] << " ";
	return 0;
}

