#include<iostream>
using namespace std;

//PROBLEM 31
//In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
//
//1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
//It is possible to make £2 in the following way:
//
//1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
//How many different ways can £2 be made using any number of coins?

int main(){
	int total=200;
	cout<<"Enter the amount to make changes of :: ";
	cin>>total;
	
//	BRUTE FORCE
//	int ways=0;
//	for(int a=total;a>=0;a-=200)
//		for(int b = a;b>=0;b-=100)
//			for(int c = b;c>=0;c-=50)
//				for(int d = c;d>=0;d-=20)
//					for(int e = d;e>=0;e-=10)
//						for(int f=e;f>=0;f-=5)
//							for(int g=f;g>=0;g-=2)
//							{
//								ways++;
//							}
	
//	DYNAMIC-PROGRAMMING
	int *ways = new int[total+1];
	int denominations[] = {1,2,5,10,20,50,100,200};
	
	for(int k=0;k <= total + 1;k++)
	{
		ways[k] = 0; 
	}
	
	ways[0] = 1;
	
	for (int i = 0; i < sizeof(denominations)/sizeof(int); i++) 
	{
    	for (int j = denominations[i]; j <= total; j++)
		{
        	ways[j] += ways[j - denominations[i]];
    	}
	}
	cout<<"\n\nTotal no of ways are :: "<<ways[total];

	return 0;
}

