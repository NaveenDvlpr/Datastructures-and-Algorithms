#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<bool> isPrime(N, 1);
vector<int> lowPrime(N), highPrime(N);

void findPrimes() {
	isPrime[0] = isPrime[1] = false;
	
	for(int i = 2; i < N; i++) {
		if(isPrime[i]) {
			lowPrime[i] = highPrime[i] = i;
			for(int j = 2*i; j < N; j += i) {
				isPrime[j] = false;
				highPrime[j] = i;
				if(!lowPrime[j]) lowPrime[j] = i;
			}
		}
	}
}


int main() {
	findPrimes();
	int num;
	cin >> num;
	
	vector<int> primeFactors;
	while(num > 1) {
		int prime_factor = highPrime[num];
		while(num % prime_factor == 0) {
			num /= prime_factor;
			primeFactors.push_back(prime_factor);
		}
	}
	
	for(auto i : primeFactors) cout << i << " ";
	
	return 0;
}











