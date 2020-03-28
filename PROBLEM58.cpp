#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;

//Spiral primes
//
//Problem 58
//Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
//
//37 36 35 34 33 32 31
//38 17 16 15 14 13 30
//39 18  5  4  3 12 29
//40 19  6  1  2 11 28
//41 20  7  8  9 10 27
//42 21 22 23 24 25 26
//43 44 45 46 47 48 49
//
//It is interesting to note that the odd squares lie along the bottom right diagonal,
//but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ˜ 62%.
//
//If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.
//If this process is continued, what is the side length of the square spiral
//for which the ratio of primes along both diagonals first falls below 10%?
int high = 1000000000;
bool *is_prime = new bool[high];

int main()
{
	memset(is_prime, 1, sizeof(bool) * (high + 1));
	is_prime[1] = false;
	for(long int i = 2; i * i <= high; i++)
	{
		if(is_prime[i])
		{
			for(long int j = i * i; j <= high; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	int i = 2, noOfPrimes = 3, k = 9;
	double ans = ((double)noOfPrimes) / (2 * i + 1);
	while(ans > 0.1)
	{
		i += 2;
		for(int p = 0; p < 3; p++)
		{
			k += i;
//			cout<<k<<" ";
			if(is_prime[k])
			{
//				cout<<k<<" ";
				noOfPrimes++;
			}
		}
		k += i;
//		cout<<noOfPrimes<<" / "<<(2*i + 1)<<endl;
		ans = ((double)noOfPrimes / (2*i + 1));
//		cout<<i + 1<<" "<<ans<<endl;
	}
	cout<<i + 1;
	return 0;
}

