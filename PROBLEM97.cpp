#include<iostream>
#include<vector>
using namespace std;

//Large non-Mersenne prime
//
//Problem 97
//The first known prime found to exceed one million digits was discovered in 1999,
//and is a Mersenne prime of the form 26972593-1; it contains exactly 2,098,960 digits.
//Subsequently other Mersenne primes, of the form 2p-1, have been found which contain more digits.
//
//However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.
//
//Find the last ten digits of this prime number.


vector<int> power2;
void PowerOf2()
{
	int power = 7830457;
	power2.push_back(1);
	for(int i = 1; i <= power; i++)
	{
		int carry = 0, dig_count = 0;
		for(auto &x : power2)
		{
			if(dig_count >= 10)
			{
				carry = 0;
				break;
			}
			x = x * 2 + carry;
			if(x >= 10)
			{
				carry = x / 10;
				x %= 10;
			}
			else
			{
				carry = 0;
			}
			dig_count++;
		}
		if(carry != 0)
		{
			power2.push_back(carry);
		}
	}
}

void multiply()
{
	int carry = 0;
	for(auto &x : power2)
	{
		x = x * 28433 + carry;
		if(x >= 10)
		{
			carry = x / 10;
			x %= 10;
		}
		else
		{
			carry = 0;
		}
	}
	while(carry)
	{
		power2.push_back(carry % 10);
		carry /= 10;
	}
	power2[0] += 1;
	for(int i = 0; i <= 10; i++)
	{
	 cout<<power2[10 - i];
	}
}

int main()
{
	PowerOf2();
	multiply();
	return 0;
}

