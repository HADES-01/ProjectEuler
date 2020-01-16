#include<iostream>
#include<conio.h>
#include<algorithm>

//Lexicographic permutations
//   
//Problem 24
//A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
//
//012   021   102   120   201   210
//
//What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

using namespace std;
int main()
{
	unsigned int numPerm = 1000000;
	cout<<"PROGRAM TO FIND LEXICOGRAPHIC PERMUTATIONS OF 0-9";
	cout<<"\nPE : 1000000";
	cout<<"\n\nEnter the Rank of Permutation : ";
	cin>>numPerm;
  	string current = "0123456789";
 	while (--numPerm)
 	{
 		next_permutation(current.begin(), current.end()); 	
	}
 	cout<<endl<<current<<endl;
 	getch();
	return 0;
}
