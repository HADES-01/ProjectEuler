#include <iostream>
#include <conio.h> 

//Longest Collatz sequence
//   
//Problem 14
//The following iterative sequence is defined for the set of positive integers:
//
//n ? n/2 (n is even)
//n ? 3n + 1 (n is odd)
//
//Using the rule above and starting with 13, we generate the following sequence:
//
//13 ? 40 ? 20 ? 10 ? 5 ? 16 ? 8 ? 4 ? 2 ? 1
//It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
//Which starting number, under one million, produces the longest chain?
//
//NOTE: Once the chain starts the terms are allowed to go above one million.

int main()
{
	long a=1000000;
	int ctr=1,max=0;
	long long no=0,coll_no=0;
	std::cout<<"Program to find a number under a limit with greatest collatz sequence";
	std::cout<<"\nPE 1000000";
	std::cout<<"\n\nEnter the Limit : ";
	std::cin>>a;
	for(long i=a-1;i>2;i--)
	{
		no=i;
		ctr=1; 
		while(no!=1)
		{
			if(no%2==0)
				no/=2;
			else
				no=no*3+1;
			ctr++;	
		}
		if(max<ctr)
		{
			max=ctr	;
			coll_no=i;
		}
	}
	std::cout<<"\n\nRequired no. with greatest collatz sequence = "<<coll_no<<"\n";
	std::cout<<"Number of Elemnts in its collatz sequence is  =  "<<max<<"\n\n";
	no=coll_no;
	while(no!=1)
	{	
		if(no%2==0)
		{
			no/=2;
			std::cout<<no<<" : ";
		}
		else
		{
			no=no*3+1;
			std::cout<<no<<" : ";	
		}	
	}
	std::cout<<"\b\b\b";
	getch();
	return 0;
}
