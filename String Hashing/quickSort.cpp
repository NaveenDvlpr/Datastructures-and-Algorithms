#include<bits/stdc++.h>
using namespace std;

void quickSort(int l, int r, int arr[]) {
	if(l >= r) return;
	int p = l+1, q = r;
	while(p <= q) {
		while(p <= r && arr[p] <= arr[l]) p++;
		while(q >= l && arr[q] > arr[l]) q--;
		if(p<=q) {
			int temp = arr[q];
			arr[q] = arr[p];
			arr[p] = temp;
		}
	}
	int temp = arr[l];
	arr[l] = arr[q];
	arr[q] = temp;
	quickSort(l, q-1, arr);
	quickSort(q+1, r, arr);
}

int main() {
	int n = 7;
	int arr[n] = {3,7,1,4,5,2,3};
	quickSort(0, n-1, arr);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}
