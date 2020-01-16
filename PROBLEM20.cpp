#include<iostream>
#include<conio.h>
#include<iomanip>
#include<vector>

//Factorial digit sum
//   
//Problem 20
//n! means n × (n - 1) × ... × 3 × 2 × 1
//
//For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
//and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
//Find the sum of the digits in the number 100!

int main()
{
	std::vector<std::vector<unsigned int>> cache;
	cache.push_back({ 1 });
	std::cout<<"Program to print th sum of digits of a given factorial";
	std::cout<<"\nPE 100";
	std::cout<<"\n\nEnter the no : ";
	int exponent=2019;
	std::cin>>exponent;
	for(int i=cache.size();i<=exponent;i++)
	{
		auto power=cache.back();
		int car=0;
		for(auto& j : power)
		{	
			j=j*(i)+car;
			if(j<10)
				car=0;	
			if(j>=10)
			{
				car=j/10;
				j%=10;
			}
		}
		while(car!=0)
		{
			power.push_back(car%10);
			car/=10;
	 	}
	 	cache.push_back(power);
	}
	int sum=0;
	std::cout<<"\n"<<exponent<<"! is : ";
	std::vector<unsigned int> ans;
	for(auto j:cache[exponent])
	{		
		auto it = ans.begin();
    	it = ans.insert(it, j);
		sum+=j;
	}
	for(auto k : ans)
		std::cout<<k;
	std::cout<<"\n\nRequired sum is : "<<sum;
	getch();
	return 0;
}
