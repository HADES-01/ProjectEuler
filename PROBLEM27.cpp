#include<iostream>
#include<conio.h>
#include<cstring>
#include<math.h>

//Quadratic primes
//   
//Problem 27
//Euler discovered the remarkable quadratic formula:
//
//n2+n+41
//It turns out that the formula will produce 40 primes for the consecutive integer values 0=n=39. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.
//
//The incredible formula n2-79n+1601 was discovered, which produces 80 primes for the consecutive values 0=n=79. The product of the coefficients, -79 and 1601, is -126479.
//
//Considering quadratics of the form:
//
//n2+an+b, where |a|<1000 and |b|=1000
//
//where |n| is the modulus/absolute value of n
//e.g. |11|=11 and |-4|=4
//Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.

using namespace std;
bool prime[10000];
int main()
{
	cout<<"PROGRAM TO FIND GREATES VALUE FO A & B TO GENERATE MAX PRIME NO.\nFOR THE FORMULA N^2 + A*N + B";
	memset(prime,1,sizeof(bool)*(10000));
	for(int i=2;i*i<=10000;i++)
	{
		if(prime[i]==true)
		{
			prime[i]=true;
			for(int j=i*i;j<=10000;j+=i)
			{
				prime[j]=false;
			}
		}	
	}
	int consec=0,a=0,b=0;
	for(int i=-1000;i<=1000;i++)
	{
		for(int j=-1000;j<=1000;j++)
		{
			int n=0;
			while(prime[abs(n*n+i*n+j)]==true)
				n++;
			if(consec<n)
			{
				consec=n;
				a=i;
				b=j;
			}
		}
	}
	cout<<"\n\nValue of A : "<<a;
	cout<<"\nValue of B : "<<b;
	cout<<"\nRequired Product is : "<<a*b;
	return 0;
}
