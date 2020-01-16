#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>

//Largest prime factor
//   
//Problem 3
//The prime factors of 13195 are 5, 7, 13 and 29.
//
//What is the largest prime factor of the number 600851475143 ?

int main()
{
	double b=600851475143;
	double a=b;
	//double a=24517;
	int factor=2;
	double l_factor=0;
	std::cout<<"Program to print largest prime factor for a given no";
	std::cout<<"PE 600851475143";
	std::cout<<"\n\nEnter the no : ";
	std::cin>>a;
	while(factor<=sqrt(a))
	{
		if(fmod(a,factor)==0)
		{
			a/=factor;
			l_factor=factor;
		}
		else
		       factor++;
	}
	if(a>l_factor)
		l_factor=a;
	std::cout<<"\nThe Largest Prime Factor is :  "<<l_factor;
	getch();
	return 0;
}
