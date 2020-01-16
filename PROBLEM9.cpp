#include<iostream>
#include<conio.h>
#include<math.h>

//Special Pythagorean triplet
//   
//Problem 9
//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
//a2 + b2 = c2
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

int main()
{
	std::cout<<"Program TO find Pythagorean Triplet Whose sum is 1000";
	std::cout<<"\n\nRequired no are : ";
	unsigned long a,b,c,s=1000,f=0;
	for(a=1;a<s/3;a++)
	{
		for(b=a;b<s/2;b++)
		{
			c=s-(a+b);
			if(a*a+b*b==c*c)
			{
				f=1;
				break;
			}
		}
		if(f==1)
			break;
	}
	std::cout<<a<<" "<<b<<" "<<c;
	std::cout<<"\n\nTheir product is : "<<a*b*c;
	getch();
	return 0;	
}
