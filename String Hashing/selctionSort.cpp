#include<iostream>
using namespace std;

void selectionSort(int n, int arr[]) {
	for(int i = 0; i < n; i++) {
		int ind = i;
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[ind]) ind = j;
		}
		if(ind != i) {
			int temp = arr[i];
			arr[i] = arr[ind];
			arr[ind] = temp;
		}
	}
}

int main() {
	int arr[7] = {6,2,4,1,5,7,3};
	selectionSort(7, arr);
	for(int i = 0; i < 7; i++) cout << arr[i] << " ";
}
