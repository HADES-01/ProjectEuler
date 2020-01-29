#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//Champernowne's constant
//
//Problem 40
//An irrational decimal fraction is created by concatenating the positive integers:
//
//0.123456789101112131415161718192021...
//
//It can be seen that the 12th digit of the fractional part is 1.
//
//If dn represents the nth digit of the fractional part, find the value of the following expression.
//
//d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

int count_dig(int no)
{
	int ctr = 0;
	while(no > 0)
	{
		no /= 10;
		ctr++;
	}
	return ctr;
}

int upperBound_calc(int limit)
{
	int sum = 0, extra = 0;
	int n = count_dig(limit) - 1;
	for(int i = 1; i < n; i++)
	{
		sum += 9 * (pow(10, i-1) * i);
	}
	extra = limit - sum;
	extra /= (n);

	return pow(10, n-1) + extra + 1;
}

int main()
{
	int limit = 1000000000;
	vector<int> digits;
	int multiplier = 1, ans = 1;
	for(int i = 1; i <= upperBound_calc(limit); i++)
	{
		multiplier = pow(10, count_dig(i));
		multiplier /= 10;
		int no = i;
		while(no > 0)
		{
			digits.push_back(no / multiplier);
			no %= multiplier;
			multiplier /= 10;
		}
		no = i;
		if(no % 10 == 0)
		{
			while(no % 10 == 0)
			{
				digits.push_back(0);
				no /= 10;
			}
		}
	}
	for(int k = 0; k <= count_dig(limit) - 1; k++)
	{
		cout<<digits[(int)pow(10, k) - 1]<<endl;;
		ans *= digits[(int)pow(10, k) - 1];
	}
//	for(auto i : digits)
//	{
//		cout<<i;
//	}
	cout<<endl<<"Ans :: "<<ans;
	return 0;
}

