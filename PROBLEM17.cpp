#include<iostream>
#include<conio.h>
#include<vector>

//Number letter counts
//   
//Problem 17
//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
//
//
//NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
//The use of "and" when writing out numbers is in compliance with British usage.

int main()
{
	std::vector<int> arr1={3,3,4,5,5,3,5,5,4,3},arr2 ={7,8,6,6,5,5,5,7},arr3={6,5,7,7},arr4{6,6,8,8,7,7,9,8,7};
	long sum=0,no=0;
	int _1=3+3+4+5+5+4+5+5+4+3,_10=6+6+8+8+7+7+9+8+7,_100=6,_1000=9,_20=7+8+6+6+5+5+5+7;
	sum=_1*109+_10*10+_1000+_100*10+_20*10+3*900;
	std::cout<<sum;
	getch();
	return 0;
}
