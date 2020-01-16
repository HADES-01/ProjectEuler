#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
#include<process.h>

//Largest palindrome product
//   
//Problem 4
//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
//Find the largest palindrome made from the product of two 3-digit numbers.

int palindrome(double a)
{
	int b=a,rev=0;
	int rem=0;
	while(b>0)
	{
		rem=fmod(b,10);
		rev=rev*10+rem;
		b/=10;
	}
	if(rev==a)
		return 1;
	else
		return 0;
}
int main()
{
	double num=1,no;
	int c;
	for(int i=999;i>0;i--)
	{
		for(int j=999;j>0;j--)
		{
			no=i*j;
			c=palindrome(no);
			if(c==1&&num<no)
			{
				num=no;
			}
		}
	}
	std::cout<<num;
	getch();
	return 0;
}
