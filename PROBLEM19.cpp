#include<iostream>
#include<vector>
#include<math.h>
#include<conio.h>

//Counting Sundays
//   
//Problem 19
//You are given the following information, but you may prefer to do some research for yourself.
//
//1 Jan 1900 was a Monday.
//Thirty days has September,
//April, June and November.
//All the rest have thirty-one,
//Saving February alone,
//Which has twenty-eight, rain or shine.
//And on leap years, twenty-nine.
//A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
//How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

int main()
{
	std::vector<int> week[7];
	int day=0,year_1,year_2;
	std::cout<<"Program to Count all days on 1st b/w 1901-2000";
	for(int k=1901;k<=2000;k++)
	{
		for(int  i=1;i<=12;i++)
		{	
//			std::cout<<"\n";
			for(int j=1;j<=31;j++)
			{	
				day=(day%7);
				week[day].push_back(j);
				day++;	
//				std::cout<<day<<" "<<j<<"\n";
				if((j==30)&&(i==4||i==6||i==9||i==11))
				{
					break;
				}
				if(i==2&&j==28&&k%4!=0)
				{
					break;
				}
				if(i==2&&j==29&&k%4==0)
				{
					break;	
				}	
			}
		 }
	}
	int ctr=0;
	char days[7][20]={"Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","Monday"};
	std::cout<<"\n";
	for(int i=0;i<7;i++)
	{
		std::cout<<"\n";
		ctr=0;
		for(auto j : week[i])
		{
			if(j==1)
			{
				ctr++;
			}
		}
		for(auto k : days[i])
			std::cout<<k;
		std::cout<<" - "<<ctr;
	}
	getch();
	return 0;
}
