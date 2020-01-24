#include<iostream>
#include<cstring>
#include<math.h>
#include<set>
using namespace std;

//Circular primes
//
//Problem 35
//The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
//
//There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
//
//How many circular primes are there below one million?

long limit = 1000, ctr = 2;
bool *isprime = new bool[limit + 1];

int is_circ_prime(int no)
{
	set<int> circ_prime;
	int multiplier = 1, count_dig = 0;
	int d = 0, number = no;
	while(number > 0)
	{
		d = number % 10;
		if(d % 2 == 0 || d == 5)
		{
			isprime[no] = 0;
			return 0;
		}
		number /= 10;
		count_dig++;
		multiplier *= 10;
	}
	multiplier /= 10;
	number = no;
	for(int i = 0; i < count_dig; i++)
	{
		d = number % 10;
		number = (d * multiplier) + (number / 10);
		if(isprime[number])
		{
			circ_prime.insert(number);
			isprime[number] = 0;
		}
		else if(circ_prime.find(number) == circ_prime.end())
		{
			return 0;
		}
	}
	for(auto i : circ_prime)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return circ_prime.size();
}

int main()
{
	memset(isprime, 1, sizeof(bool) * (limit+1));
	for(int i = 2; i <= (int)sqrt(limit); i++)
	{
		for(int j = i * i; j <= limit; j += i)
		{
			isprime[j] = false;
		}
	}

	for(int i = 2; i < limit; i++)
	{
		if(isprime[i])
		{
			ctr += is_circ_prime(i);
		}
	}
	cout<<endl<<ctr;
	return 0;
}

