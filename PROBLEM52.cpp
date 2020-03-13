#include<iostream>
#include<vector>
using namespace std;

//Permuted multiples
//
//Problem 52
//It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
//
//Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

vector<int> Digits(int num)
{
	vector<int> dig;
	while(num)
	{
		dig.push_back(num % 10);
		num /= 10;
	}
	return dig;
}

bool checkEqual(vector<int> dig1, vector<int>dig2)
{
	if(dig1.size() != dig2.size())
	{
		return false;
	}
	for(int i = 0; i < dig1.size(); i++)
	{
		bool found = false;
		for(int j = 0; j < dig1.size(); j++)
		{
			if(dig1[i] == dig2[j])
			{
				found = true;
			}
		}
		if(!found)
		{
			return false;
		}
	}
	return true;
}

bool checkPermutedMultiples(int num)
{
	vector<int> dig = Digits(num);
	for(int i = 1; i<= 6; i++)
	{
		vector<int> newDig = Digits(i * num);
		if(!checkEqual(dig, newDig)){
			return false;
		}
//		for(auto x: dig)
//		{
//			cout<<x<<" ";
//		}
//		cout<<endl;
	}
	return true;
}


int main()
{
	int i = 0;
	while(1)
	{
		i++;
		if(checkPermutedMultiples(i))
		{
			cout<<i;
			break;
		}
	}
//	vector<int> dig1 = {1, 0, 7, 5, 3}, dig2 = {5, 3, 0, 1, 7};
//	cout<<checkEqual(dig1, dig2);
	return 0;
}

