#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;

//Pandigital prime
//Problem 41
//We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
//For example, 2143 is a 4-digit pandigital and is also prime.
//What is the largest n-digit pandigital prime that exists?


int limit = 9999999;
bool *sieve = new bool[limit + 1];
int SieveOfAtkin(int limit)
{
	for (int i = 0; i < limit; i++)
		sieve[i] = false;
	for (int x = 1; x * x < limit; x++) {
		for (int y = 1; y * y < limit; y++) {
			int n = (4 * x * x) + (y * y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
				sieve[n] ^= true;

			n = (3 * x * x) + (y * y);
			if (n <= limit && n % 12 == 7)
				sieve[n] ^= true;

			n = (3 * x * x) - (y * y);
			if (x > y && n <= limit && n % 12 == 11)
				sieve[n] ^= true;
		}
	}
	for (int r = 5; r * r < limit; r++) {
		if (sieve[r]) {
			for (int i = r * r; i < limit; i += r * r)
				sieve[i] = false;
		}
	}
}

bool isPrime(vector<int> digits, int no)
{
	ll n = 0;
	ll multiplier = pow(10, no - 1);
	for(int i = no; i >= 1; i--)
	{
		n += digits[no - i] * multiplier;
		multiplier /= 10;
	}
	return sieve[n];
}

void add_int(vector<int> &digs, int i)
{
	for(int j = i; j > 0; j--)
	{
		digs.push_back(j);
	}
}
vector<vector<int>>pandig_prime;
bool is_pandig(int n)
{
	for(int i = n; i >= 1; i--)
	{
		vector<int> digits;
		add_int(digits, i);
		do
		{
			if(digits.back() % 2 == 0 || digits.back() == 5)
			{
				continue;
			}
			if(isPrime(digits, i))
			{
				pandig_prime.push_back(digits);
//				for(int j = 0; j < i; j++)
//				{
//					cout<<digits[j];
//				}
//				cout<<endl;
//				return 0;
			}
		}while(prev_permutation(digits.begin(), digits.end()));
	}
}


int main()
{
	int n;
	cout<<"Enter no of digits in Pandigital Primes (PE 9) :: ";
	cin>>n;
	if(n > 4)
	{
		if(n > 7)
			n = 7;
		SieveOfAtkin(limit);
		is_pandig(n);
		cout<<endl<<"Largest Pandigital Prime is :: ";
		for(auto j : pandig_prime[0])
		{
			cout<<j;
		}
	}
	else if(n < 4)
	{
		cout<<endl<<"No Pandigital Prime is Present!!!!";
	}
	
	return 0;
}

