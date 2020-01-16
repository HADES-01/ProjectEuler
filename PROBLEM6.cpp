#include<iostream>
#include<iomanip>
#include<conio.h>

//Sum square difference
//   
//Problem 6
//The sum of the squares of the first ten natural numbers is,
//
//12+22+...+102=385
//The square of the sum of the first ten natural numbers is,
//
//(1+2+...+10)2=552=3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025-385=2640.
//
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

int main()
{
	int sum_square=0,sum=0,a;
	std::cout<<"Code to Print the difference Sum of Squares and square of sum ";
	std::cout<<std::endl<<std::endl<<"Enter the No upto which you want the answer : ";
	std::cin>>a;
	for(int i=1;i<=a;i++)
	{
		sum+=i;
		sum_square+=i*i;
	}
	sum*=sum;
	std::cout<<sum-sum_square;
	getch();	
	return 0;
}
