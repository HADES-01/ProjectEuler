#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>
#include<conio.h>

//Non-abundant sums
//   
//Problem 23
//A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
//A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
//
//As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
//
//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

using namespace std;
int sum=0,k=1;
vector<int> no1;
vector<int> factor;
bool no[60000];
int abund[7427];
void abun()
{
	for(int i=1;i<30000;i++)
	{
		sum=0;
		no1.push_back(i);
		for(int j=1;j<=i/2;j++)
		{
			if(i%j==0)
				sum+=j;
		}
		factor.push_back(sum);
	}
	for(int i=1,k=0;i<30000;i++)
	{
		if(no1[i]<factor[i])
		{
			abund[k]=no1[i];
			k++;
		}
	}
}
int main()
{
	cout<<"Program to Find sum of the Numbers which cannot be written as the sum\n of two Abundant Numbers";
	int sum=0;
	std::memset(no,false,sizeof(bool)*60000);
	abun();
	for(int i=0;i<7427;i++)
	{
		for(int j=0;j<7427;j++)
		{
			no[abund[i]+abund[j]]=true;
		}
	}
	for(int i=1;i<=30000;i++)
	{
		if(no[i]==false)
			sum+=i;
	}
	cout<<"\n\nRequired Sum is : ";
	cout<<sum;
	getch();
	return 0;
}
