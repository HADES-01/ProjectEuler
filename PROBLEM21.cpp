#include<iostream>
#include<conio.h>
#include<vector>
#include<iomanip>
#include<cstring>
#include<math.h>

//Amicable numbers
//   
//Problem 21
//Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
//If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
//For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
//Evaluate the sum of all the amicable numbers under 10000.

double sum=0;
bool *amic;
int fact_sum(int a)
{
	int sum_fact=0,factor=2;
	for(int i=1;i<=a/2;i++)
	{
		if(fmod(a,i)==0)
		{
			sum_fact+=i;
//			std::cout<<i<<" ";
		}
	}
	return sum_fact;
}	
void am(int a)
{
	int b=fact_sum(a);
	if(a==fact_sum(b))
	{
		if(a!=b)
		{
			sum=sum+a+b;
			std::cout<<a<<" "<<b<<"\n";
			amic[b]=false;
		}	
	}
}
int main()
{
	std::cout<<"Program to search for amicable numbers under a given range";
	std::cout<<"\nPE 10000";
	int n=20000;
	std::cout<<"\n\nEnter the Upper Limit : ";
	std::cin>>n;
	std::cout<<"\nAmicable Numbers are : \n";
	amic=new bool[n];
	std::memset(amic,false,sizeof(bool)*n);
	std::cout.setf(std::ios::fixed);
	std::cout <<std::setprecision(0);
	for(int i=2;i*i<=n;i++)
	{
		if(!amic[i])
		{
			for(int j=i*i;j<=n;j+=i)
			{
				amic[j]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(amic[i]==true)
		{
			am(i);	
		}
	}
	std::cout<<"\nRequired Sum is : "<<sum;
	getch();
	return 0;
}
