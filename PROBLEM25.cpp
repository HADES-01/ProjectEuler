#include<iostream>
#include<conio.h>
#include<iomanip>
#include<vector>
#include<process.h>

//1000-digit Fibonacci number
//   
//Problem 25
//The Fibonacci sequence is defined by the recurrence relation:
//
//Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
//Hence the first 12 terms will be:
//
//F1 = 1
//F2 = 1
//F3 = 2
//F4 = 3
//F5 = 5
//F6 = 8
//F7 = 13
//F8 = 21
//F9 = 34
//F10 = 55
//F11 = 89
//F12 = 144
//The 12th term, F12, is the first term to contain three digits.
//
//What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

int main()
{
	std::vector<std::vector<unsigned int>> cache;
	cache.push_back({ 1 });
	std::cout<<"Program to print a fibonacci number with n number of digits";
	std::cout<<"PE 1000";
	std::cout<<"\n\nEnter the no of digits : ";
	int digit=1000,k=0,a=0;
	std::cin>>digit;
	auto penultimate=cache.back();
	auto ultimate=cache.back();
	for(int i=cache.size();k!=digit;i++)
	{
		int car=0;
		for(int k=0;k<ultimate.size();k++)
		{
			auto &j=ultimate[k];
			auto h=0;
			if(k<penultimate.size())
				h=penultimate[k];
			j=j+h+car;
			if(j<=10)
				car=0;
			if(j>=10)
			{
				car=j/10;
				j%=10;
			}
		}
		while(car!=0)
		{
			ultimate.push_back(car%10);
			car/=10;
		}
		k=ultimate.size();
		penultimate=cache.back();
		cache.push_back(ultimate);
	}
	std::cout<<"\nFibonacci Number with "<<digit<<" digits is : ";
	std::vector<unsigned int> ans;
	for(auto j:cache.back())
	{		
		auto it = ans.begin();
    	it = ans.insert(it, j);
	}
	for(auto k : ans)
	{
		std::cout<<k<<" ";
	}
	std::cout<<"\n\nIndex of the Fibonnaci Number is : "<<cache.size()+1;
	getch();
	return 0;
}
