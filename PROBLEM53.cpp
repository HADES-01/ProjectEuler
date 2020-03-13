#include<iostream>
using namespace std;

//Combinatoric selections
//
//Problem 53
//There are exactly ten ways of selecting three from five, 12345:
//
//123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
//
//In combinatorics, we use the notation, (5/3)=10.
//
//In general, (nr)=n!r!/(n-r)!, where r=n, n!=n×(n-1)×...×3×2×1, and 0!=1.
//
//It is not until n=23, that a value exceeds one-million: (23/10)=1144066.
//
//How many, not necessarily distinct, values of (n/r) for 1=n=100, are greater than one-million?

double Combinations(int n, int r)
{
	int rem = n - r;
	double numer = 1, denom = 1;
	
	for(int i = rem + 1; i <= n; i++)
	{
		numer *= i;
//		cout<<i<<" "<<numer<<"\n";
	}
		
	for(int i = 1; i <= r; i++)
		denom *= i;
		
//	cout<<numer<<" "<<denom;
	
	return numer / denom;
}


int main()
{
	int ctr = 0;
	for(int n = 1; n <= 100; n++)
	{
		for(int r = 1; r <= n; r++)
		{
			if(Combinations(n, r) > 1000000)
			{
				ctr++;
			}
		}
	}
	cout<<ctr;
//	cout<<"\n"<<Combinations(23, 10);
	return 0;
}

