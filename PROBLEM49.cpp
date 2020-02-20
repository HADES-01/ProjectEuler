#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;

int limit = 10000;
typedef vector<int> array;
//Prime permutations
//
//Problem 49
//The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
//
//There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
//
//What 12-digit number do you form by concatenating the three terms in this sequence?

bool *isPrime = new bool[limit + 1];

bool sumDigits(int a, int b, int c){
	set<int> dig_a, dig_b, dig_c;
	while(a){
		dig_a.insert(a % 10);
		dig_b.insert(b % 10);
		dig_c.insert(c % 10);
		a /= 10;
		b /= 10;
		c /= 10;
	}
	return (dig_a == dig_b) && (dig_b == dig_c);
}

void checkPrimePermutations(int no){
	for(int i = 1000; i <= 10000; i++){
		int perm_1 = no + i;
		if(perm_1 < 10000 && isPrime[perm_1]){
			int perm_2 = perm_1 + i;
			if(perm_2 < 10000 && isPrime[perm_2]){
				if(sumDigits(no, perm_1, perm_2)){
					cout<<no<<" "<<perm_1<<" "<<perm_2<<endl;
				}
			}
		}
	}
}

int main(){
	memset(isPrime, 1, sizeof(bool) * (limit + 1));
	for(int i = 2; i<= sqrt(limit); i++)
	{
		for(int j = i * i; j < limit; j += i){
			isPrime[j] = false;
		}
	}
	
	for(int i = 1000; i <= 10000; i++){
		if(isPrime[i]){
			checkPrimePermutations(i);
		}
	}
	return 0;
}

