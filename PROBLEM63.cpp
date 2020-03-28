#include<iostream>
#include<vector>
using namespace std;

//Powerful digit counts
//
//Problem 63
//The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.
//
//How many n-digit positive integers exist which are also an nth power?

bool findPower(int n, int power)
{
	vector<unsigned int> powers;
	powers.push_back(1);
	for(int i = 0; i < power; i++)
	{
		int carry = 0;
		for(auto &x: powers)
		{
			x = x * n + carry;
			if(x < 10)
			{
				carry = 0;
			}
			else
			{
				carry =  x / 10;
				x = x % 10;
			}
		}
		if(carry != 0)
		{
			while(carry)
			{
				powers.push_back(carry % 10);
				carry /= 10;
			}
		}
	}
//	for(auto x:powers)
//	{
//		cout<<x;
//	}
//	cout<<" - "<<powers.size()<<endl;
	if(power == powers.size())
	{
		return true;
	}
	return false;
}

int main()
{
	int ctr = 0;
	for(int i = 1; i <= 21; i++)
	{
		for(int j = 1; j <= 21; j++)
		{
			if(findPower(i, j))
			{
				cout<<i<<"^"<<j<<endl;
				ctr++;
			}
		}
	}
	cout<<ctr;
//	cout<<findPower(7, 5);
	return 0;
}

