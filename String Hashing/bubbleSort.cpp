#include<iostream>
using namespace std;

void bubbleSort(int n, int arr[]) {
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main() {
	int arr[7] = {6,2,4,1,5,7,3};
	bubbleSort(7, arr);
	for(int i = 0; i < 7; i++) cout << arr[i] << " ";
}
