#include<iostream>
#include<math.h>
#include<conio.h>
#include<algorithm>
#include<vector>

//Distinct powers
//   
//Problem 29
//Consider all integer combinations of ab for 2 = a = 5 and 2 = b = 5:
//
//22=4, 23=8, 24=16, 25=32
//32=9, 33=27, 34=81, 35=243
//42=16, 43=64, 44=256, 45=1024
//52=25, 53=125, 54=625, 55=3125
//If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
//
//4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
//
//How many distinct terms are in the sequence generated by ab for 2 = a = 100 and 2 = b = 100?

using namespace std;
int main()
{
	vector<double> power;
	int ctr=0;
	double result=0;
	for(int i=2;i<=100;i++)
	{
		for(int j=2;j<=100;j++)
		{
			result=pow(i,j);
			for(auto h=power.begin();h!=power.end();h++)
			{
				if(*h==result)
				{
					power.erase(h);
				}
			}
			power.push_back(result);
		}
	}
//	sort(power.begin(),power.end());
	for(auto h=power.begin();h!=power.end();h++)
	{
//		cout<<*h<<"\n";
		ctr++;
	}
	cout<<power.size()<<" ";
	cout<<ctr;
	getch();
	return 0;
}
