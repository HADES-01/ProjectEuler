#include<iostream>
#include<cstring>
#include<math.h>
#define limit 1000000
using namespace std;

//Truncatable primes
//
//Problem 37
//The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
//
//Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
//
//NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

int multiplier = 1;
bool *primes = new bool[limit + 1];

bool truncate_prime_check_right(int no){
	multiplier = 1;
	while(no > 0){
		if(primes[no] == 1){
			no /= 10;
		}
		else{
			return 0;
		}
		multiplier *= 10;
	}
	return 1;
}

bool truncate_prime_check_left(int no){
	multiplier /= 10;
	while(no > 0)
	{
		if(primes[no] == 1){
			no %= multiplier;
		}
		else{
			return 0;
		}
		multiplier /= 10;
	}
	return 1;
}

int main(){
	
	memset(primes, 1, sizeof(bool)*(limit+1));
	primes[0] = 0; primes [1] = 0;
	for(int i = 2; i < sqrt(limit); i++)
	{
		for(int j = i*i; j <= limit; j += i)
		{
			primes[j] = 0;
		}
	}
	int k = 0, sum = 0;
	for(int i = 11; i < limit; i++)
	{
		if(truncate_prime_check_right(i) && truncate_prime_check_left(i))
		{
			k++;
			cout<<k<<" . "<<i<<endl;
			sum+=i;
		}
	}
	cout<<"SUM OF ALL THE TUNCATABLE PRIMES IS :: "<<sum;
	return 0;
}

