#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//Powerful digit sum
//
//Problem 56
//A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
//
//Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?

double PowerDigitSum(int n)
{
	int num = n;
	double max = 0, pow = 0;
	vector<int> powers;
	powers.push_back(1);
	double sum = 0;
	for(int i = 1; i <= 100; i++)
	{
		int carry = 0;
		for(auto &x : powers)
		{
			x = x * num + carry;
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
		if(carry < 10 && carry != 0)
		{
			powers.push_back(carry);
		}
		else
		{
			while(carry)
			{
				powers.push_back(carry % 10);
				carry /= 10;
			}
		}
		sum = 0;
		for(auto x:powers)
		{
			sum += x;
		}
		if(sum > max)
		{
			max = sum;
			pow = i;
		}
	}
	return max;
}

int main()
{
	int max = 0, max_term = 0;
	for(int i = 1; i <= 100; i++)
	{
		int x = PowerDigitSum(i);
		if(max < x)
		{
			max_term = i;
			max = x;
		}
	}
	cout<<setprecision(20);
	cout<<max<<" "<<max_term;
	return 0;
}

