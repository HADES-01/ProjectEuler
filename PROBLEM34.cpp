#include<iostream>
using namespace std;

//Digit factorials
//
//Problem 34
//145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
//
//Find the sum of all numbers which are equal to the sum of the factorial of their digits.
//
//Note: as 1! = 1 and 2! = 2 are not sums they are not included.

long factorials[9];

long dig_fact_sum(int no)
{
	long sum_dig_fact = 0;
	while(no > 0)
	{
		sum_dig_fact += factorials[no % 10];
		no /= 10;
	}
	return sum_dig_fact;
}

int main()
{
	int sum = 0;
	factorials[0] = 1;
	for(int i = 1; i <= 9; i++)
	{
		factorials[i] = 1;
		for(int j = 1;j <= i; j++)
		{
			factorials[i] *= j;
		}
	}
	
	for(long int i = 3; i <= 2540160; i++)
	{
		if(i == dig_fact_sum(i))
		{
			cout<<endl<<i;
			sum += i;
		}
	}
	
	cout<<endl<<"Reqiured Sum = "<<sum;
	return 0;
}

