#include<iostream>
#include<conio.h>
#include<iomanip>
#include<vector>

//Power digit sum
//   
//Problem 16
//215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
//What is the sum of the digits of the number 21000?

int main()
{
	std::vector<std::vector<unsigned int>> cache;
	cache.push_back({ 1 });
	std::cout<<"Program to print th sum of digits of powers of 2";
	std::cout<<"PE 1000";
	std::cout<<"\n\nEnter the Power : ";
	int exponent=1000;
	std::cin>>exponent;
	for(int i=cache.size();i<=exponent;i++)
	{
		auto power=cache.back();
		int car=0;
		for(auto& j : power)
		{
			j=j*2+car;
			if(j<=10)
				car=0;
			if(j>=10)
			{
				j-=10;
				car=1;
			}
		}
		if(car!=0)
			power.push_back(car);
		cache.push_back(power);
	}
	int sum=0;
	std::cout<<"\n2^"<<exponent<<" is : ";
	std::vector<unsigned int> ans;
	for(auto j:cache[exponent])
	{		
		auto it = ans.begin();
    	it = ans.insert(it, j);;
		sum+=j;
	}
	for(auto k : ans)
		std::cout<<k;
	std::cout<<"\n\nRequired sum is : "<<sum;
	getch();
	return 0;
}
