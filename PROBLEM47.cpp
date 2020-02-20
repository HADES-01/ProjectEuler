#include<iostream>
#include<vector>
using namespace std;

//Distinct primes factors
//
//Problem 47
//The first two consecutive numbers to have two distinct prime factors are:
//
//14 = 2 × 7
//15 = 3 × 5
//
//The first three consecutive numbers to have three distinct prime factors are:
//
//644 = 2² × 7 × 23
//645 = 3 × 5 × 43
//646 = 2 × 17 × 19.
//
//Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

int limit = 1000000;
vector<int> primeFactors(limit + 1, 0);
void generatePrimeFactors()
{
	for(int i = 2; i < limit; i++)
	{
		if(primeFactors[i] == 0)
		{
			for(int j = i ; j <= limit; j+=i)
			{
				primeFactors[j]++;
			}
		}
	}
}

bool checkConsecutive(int no, int n){
	bool ans = true;
	for(int i = no; (i < no + n) && ans; i++)
	{
		ans *= (primeFactors[i] >= n);
	}
	return ans;
}

int main()
{
	generatePrimeFactors();
	cout<<"Enter The no Factors :: ";
	int n = 0, ctr = 0 ;
	bool flag = 0;
	cin>>n;
	for(int i = 1; i < limit; i++)
	{
		if(checkConsecutive(i, n))
		{
//			cout<<i<<" "<<endl;
			ctr++;
			flag = 1;
		}
	}
	if(flag == 0)
	{
		cout<<"\nNo Such Number Exist upto "<<limit;
	}
	else
	{
		cout<<"\nCount of such Number upto "<<limit<<" :: "<<ctr;
	}
	return 0;
}

