#include<iostream>
#include<conio.h>
#include<math.h>
#include<iomanip>

//Lattice paths
//   
//Problem 15
//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//
//
//How many such routes are there through a 20×20 grid?

double fact(int n)
{
	double fact=1;
	for(int i=1;i<=n;i++)
	{
		fact*=i;
	}
	return fact;
}
int main()
{
	int n=0,r=0;
	double prod=1;
	std::cout.setf(std::ios::fixed);
	std::cout<<std::setprecision(0);
	std::cout<<"Program to find the possible ways to complete a N X N grid";
	std::cout<<"\nPE 20";
	std::cout<<"\n\nEnter The value of N : ";
	std::cin>>n;
	r=n;n*=2;
	double nCr=fact(n)/(fact(r)*fact(n-r));
	std::cout<<nCr;
	getch();
	return 0;
}
