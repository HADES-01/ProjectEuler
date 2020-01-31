#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//Sub-string divisibility
//
//Problem 43
//The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
//
//Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
//
//d2d3d4=406 is divisible by 2
//d3d4d5=063 is divisible by 3
//d4d5d6=635 is divisible by 5
//d5d6d7=357 is divisible by 7
//d6d7d8=572 is divisible by 11
//d7d8d9=728 is divisible by 13
//d8d9d10=289 is divisible by 17
//Find the sum of all 0 to 9 pandigital numbers with this property.

int primes[7] = {2, 3, 5, 7, 11, 13, 17}, n = 0;
bool checkDivisibility(vector<int> digits)
{
	for(int i = 1; i < n - 1; i++)
	{
		int k = i, multiplier = 100, no = 0;
		while(multiplier > 0)
		{
			no += digits[k++] * multiplier;
			multiplier /= 10;
		}
		if(no % primes[i - 1] != 0)
		{
			return false;
		}
	}
	return true;
}

long long convert_vector(vector<int> digits)
{
	long long multiplier = pow(10, n), no = 0;
	int k = 0;
	while(multiplier > 0)
	{
		no += digits[k++] * multiplier;
		multiplier /= 10;
	}
	return no;
}

void add_int(vector<int> &digits, int n)
{
	for(int i = 0; i <= n; i++)
	{
		digits.push_back(i);
	}
}

long long pandigSubstring()
{
	long long sum = 0;
	vector<int> digits;
	add_int(digits, n);
	do
	{
		if(checkDivisibility(digits))
		{
			sum += convert_vector(digits);
			cout<<sum<<" ";
			for(auto i : digits)
			{
				cout<<i;
			}
			cout<<endl;
		}
		
	}while(next_permutation(digits.begin(), digits.end()));
	return sum;
}

int main()
{
	cout<<"Enter The No of Digits in Pandigital Nos (PE 10) :: ";
	cin>>n;
	cout<<endl<<"Sum of all Substring Divisible Pandigital Nos ::"<<pandigSubstring();
	return 0;
}

