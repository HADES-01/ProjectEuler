#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Pandigital multiples
//
//Problem 38
//Take the number 192 and multiply it by each of 1, 2, and 3:
//
//192 × 1 = 192
//192 × 2 = 384
//192 × 3 = 576
//By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
//
//The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
//
//What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

vector<int> digits;
int n = 9;

bool check_pandigital(vector<int> digit)
{
	sort(digit.begin(), digit.end());
	for(int i = 1 ;i <= 9; i++)
	{
		if(digit[i-1] != i)
		{
			return 0;
		}
	}
	return 1;
}

void make_digits(int no)
{
	int number = no, multiplier = 1;
	while(number)
	{
		number /= 10;
		multiplier *= 10;
	}
	multiplier /= 10;
	while(no > 0)
	{
		digits.push_back(no / multiplier);
		no %= multiplier;
		multiplier /= 10;
	}
}

int main(){

	for(int i = 1; i < 10000; i++)
	{
		digits.clear();
		for(int j = 1; j <= 9; j++)
		{
			make_digits(i * j);
			if(digits.size() == 9)
			{
				if(check_pandigital(digits))
				{
					cout<<i<<" - ";
					for(auto k : digits)
					{
						cout<<k;
					}
					cout<<endl;
				}
			}
		}
	}

	return 0;
}

