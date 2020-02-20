#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

//The prime 41, can be written as the sum of six consecutive primes:
//
//41 = 2 + 3 + 5 + 7 + 11 + 13
//This is the longest sum of consecutive primes that adds to a prime below one-hundred.
//
//The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
//
//Which prime, below one-million, can be written as the sum of the most consecutive primes?

int limit = 10000000;
vector<int> primes;
bool *isPrime = new bool[limit + 1];
long no_primes = 0, result = 0;
vector<long> primeSums;
void consecPrimes(){
	primeSums.push_back(0);
	for(int i = 0; i < primes.size(); i++){
		primeSums.push_back(primes[i] + primeSums[i]);
	}
	for(int i = no_primes; i < primes.size(); i++){
		for(int j = i - (no_primes + 1); j >= 0; j--){
			if(primeSums[i] - primeSums[j] > limit){
				break;
			}
			if(binary_search(primes.begin(), primes.end(), primeSums[i] - primeSums[j])){
				no_primes = i - j;
				result = primeSums[i] - primeSums[j];
			}
		}
	}
}

int main(){
	int ctr = 0;
	memset(isPrime, 1, sizeof(bool) * (limit + 1));
	for(int i = 2; i<= sqrt(limit); i++){
		for(int j = i * i; j <= limit; j += i){
			isPrime[j] = false;
		}
	}
	isPrime[0] = false; isPrime[1] = false;
	for(int i = 0; i <= limit; i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	consecPrimes();
	cout<<"Number having "<<no_primes<<" Consecutive Primes as its Sum :: "<<result;
	return 0;
}

