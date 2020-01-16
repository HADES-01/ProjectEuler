#include<iostream>
#include<conio.h>
#include<iomanip>

//Smallest multiple
//   
//Problem 5
//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

int main()
{
	int a=0,div=1,arr[8]={2,3,5,7,11,13,17,19};
	std::cout<<"Program to Print  No div by all the no till 20 ";
	for(int i=0;i<8;i++)
	{
		float a=20,c=0;
		while(a>arr[i])
		{
			a/=arr[i];
			div*=arr[i];
		}
	}
	std::cout<<std::endl<<std::endl<<"Required divisor is"<<" "<<div;
	return 0;
}
