#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Pandigital products
//   
//Problem 32
//We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
//
//The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
//
//Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
//
//HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

int n=9;

int check(vector<int> arr)
{
	for(int i = 1;i<=n;i++)
	{
		if(arr[i-1] != i)
		{
			return 0;
		}
	}
	return 1;
}

set<int> valid;

int dig_arr(int no, int no1, int no2)
{
	vector<int> temp;
	while(no > 0)
	{
		temp.push_back(no % 10);
		no /= 10;
	}
	while(no1 > 0)
	{
		temp.push_back(no1 % 10);
		no1 /= 10;
	}
	while(no2 > 0)
	{
		temp.push_back(no2 % 10);
		no2 /= 10;
	}
	if(temp.size() == n)
	{
		sort(temp.begin(), temp.end());
		return check(temp);
	}
}


int main()
{
	int total = 0;
	cout<<"Enter the no of digits you want to use(1-9) :: ";
	cin>>n;
	for(int i = 0;i < 10000; i++)
	{
		for(int j = 0;j < 100; j++)
		{
			if(dig_arr(i, j, i*j) == 1)
			{
				valid.insert(i*j);
				cout<<i<<" x "<<j<<" = "<<i*j<<endl;
			}
		}
	}
	
	for(auto i : valid)
	{
		total+=i;
	}
	cout<<endl<<"Sum of all the products is :: "<<total;
	return 0;
}

