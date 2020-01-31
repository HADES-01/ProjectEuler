#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
using namespace std;

//Goldbach's other conjecture
//
//Problem 46
//It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
//
//9 = 7 + 2×12
//15 = 7 + 2×22
//21 = 3 + 2×32
//25 = 7 + 2×32
//27 = 19 + 2×22
//33 = 31 + 2×12
//
//It turns out that the conjecture was false.
//
//What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
int limit = 100000;
bool *isPrime = new bool[limit];
vector<int> primes;
void generatePrime()
{
	memset(isPrime, 1, sizeof(bool) * limit);
	for(int i = 2; i < sqrt(limit); i++)
	{
		for(int j = i * i; j <= limit; j+=i)
		{
			isPrime[j] = false;
		}
	}
	for(int i = 2; i < limit; i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}
}

bool checkPerfectSquare(int no)
{
	float a = sqrt(no);
	float b = a - floor(a);
	if(b == 0)
	{
		return 1;
	}
	return 0;
}

bool checkGoldbach(int no)
{
	int i = -1;
	do
	{
		i++;
		int a = no - primes[i];
		if(a % 2 == 0)
		{
			a /= 2;
			if(checkPerfectSquare(a))
			{
				return true;
			}
		}
	}while(no > primes[i]);
	return false;
}

int main(){
	generatePrime();
	for(int i = 1; i < limit; i += 2)
	{
		if(!isPrime[i])
		{
			if(!checkGoldbach(i))
			{
				cout<<"Smallest Non-Goldbach No :: "<<i;
				break;
			}
		}
	}
	return 0;
}

