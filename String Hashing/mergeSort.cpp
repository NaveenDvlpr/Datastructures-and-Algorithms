#include<iostream>
using namespace std;

void merge(int s, int e, int arr[]) {
	int m = (s+e)/2;
	int trr[e-s+1];
	int l = s, r = m+1, ind = 0;
	while(l <= m && r <= e) {
		if(arr[l] < arr[r]) {
			trr[ind] = arr[l];
			l++;
		} else {
			trr[ind] = arr[r];
			r++;
		}
		ind++;
	} 
	while(l <= m) {
		trr[ind] = arr[l];
		l++;
		ind++;
	}
	while(r <= e) {
		trr[ind] = arr[r];
		r++;
		ind++;
	}
	for(int i = s; i <= e; i++) arr[i] = trr[i-s]; 
	// their positional references are different
}

void mergeSort(int s, int e, int arr[]) {
	if(s == e) return;
	int m = (s+e)/2;
	mergeSort(s, m, arr);
	mergeSort(m+1, e, arr);
	merge(s,e,arr);
	cout << s << " --- " << e << endl;
	for(int i = s; i <= e; i++) cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int arr[7] = {7,6,5,4,3,2,1};
	mergeSort(0, 6, arr);
	for(int i = 0; i < 7; i++) cout << arr[i] << " ";
}
