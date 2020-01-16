#include<iostream>
#include<cstring>
#include<conio.h>
#include<vector>

//Reciprocal cycles
//   
//Problem 26
//A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
//
//1/2	= 	0.5
//1/3	= 	0.(3)
//1/4	= 	0.25
//1/5	= 	0.2
//1/6	= 	0.1(6)
//1/7	= 	0.(142857)
//1/8	= 	0.125
//1/9	= 	0.(1)
//1/10	= 	0.1
//Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
//
//Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

using namespace std;
int cycleGenerator(int i)
{	
	int dividend=1,position=1,rem=0;
	vector<int> pos(i,0);
	while(true)
	{
		rem=dividend%i;
		if(pos[rem]!=0)
		{
			return position-pos[rem];
		}
		pos[rem]=position;
		position++;
		dividend=rem*10;
	}
}
int main()
{
	int no=1000,longestCycle=0,longestDenominator=0;
	cout<<"PROGRAM TO FIND NUMBER B/W 1 TO N WITH GREATEST REPEATING CYLE\nPE 1000";
	cout<<"\n\nEnter the value for N : ";
	cin>>no;
	bool *prime = new bool[no + 1];
	memset(prime,1,sizeof(bool)*(no+1));
	for(int i=2;i*i<=no+1;i++)
	{
		if(prime[i])
		{
			for(int k=i*i;k<=no+1;k+=i)
				prime[k]=false;
		}
	}
	for(int i=1;i<=no;i++)
	{
		if(prime[i]==true)
		{
			auto length=cycleGenerator(i);
			if(length>longestCycle)
			{
				longestCycle=length;
				longestDenominator=i;
			}
		}
	}
	cout<<"\nThe Number with Greatest Repeating decimal Cycle : "<<longestDenominator;
	getch();
	return 0;
}
