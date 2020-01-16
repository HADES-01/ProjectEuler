#include<iostream>
#include<conio.h>
#include<iomanip>

//Multiples of 3 and 5
//   
//Problem 1
//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
//Find the sum of all the multiples of 3 or 5 below 1000.

long sum(int no,int div)
{
	long s=0;
	for(float i=1;i<=(no/div);i++)
	{
		if(div*i<1000)

			s+=div*i;
	}
	return s;
}
int main()
{
	int a;
	std::cout<<"Program to Print Sum of Multiples of 3 and 5 upto n";
	std::cout<<"\nPE 1000";
	std::cout<<"\n\nEnter the no : ";
	std::cin>>a;
	std::cout<<std::endl<<"Required Sum is : "<<sum(a,3)+sum(a,5)-sum(a,15);
	getch();
}
