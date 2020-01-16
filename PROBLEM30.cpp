#include<iostream>
using namespace std;

//Digit fifth powers
//   
//Problem 30
//Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
//
//1634 = 14 + 64 + 34 + 44
//8208 = 84 + 24 + 04 + 84
//9474 = 94 + 44 + 74 + 44
//As 1 = 14 is not a sum it is not included.
//
//The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
//Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

int fifth_pow(int no)
{
	int pow5=1;
	for(int i=0;i<5;i++)
	{
		pow5*=no;
	}
	return pow5;
}
int main()
{
	int result=0;	
	for(int i=2;i<355000;i++)
	{
		int sum=0,no=i;
		while(no>0)
		{
			sum+=fifth_pow(no%10);
			no=no/10;
		}
		if(sum==i)
		{
			result+=i;
		}
	}
	cout<<"sum is :: "<<result;
	return 0;
}

