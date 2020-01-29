#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

//Integer right triangles
//
//Problem 39
//If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
//
//{20,48,52}, {24,45,51}, {30,40,50}
//
//For which value of p = 1000, is the number of solutions maximised?

int limit = 5000000;

int gcd(int a, int b)
{
	while(a > 0)
	{
		int c = a;
		a = b % a;
		b = c;
	}
	return b;
}
vector<int> count(limit + 1, 0);
int pyth_triplets()
{
	for(auto m = 1 ; 2 * m * m < limit ; m++)
	{
		for(auto n = 1; n < m; n++)
		{
			if(m % 2 == 0 && n % 2 == 0)
				continue;

			if(gcd(m, n) > 1)
				continue;

			int k = 1;
			
			while(true)
			{
				auto a = k * (m * m - n * n);
				auto b = k * (2 * m * n);
				auto c = k * (m * m + n * n);
				k++;
				auto perimeter = a + b + c;
				if(perimeter > limit)
				{
					break;
				}
				
				count[perimeter]++;
			}
		}
	}
}

int main()
{
	cout<<"Enter the Limit upto which Integer Right Triangles are to be Calculated (PE 1000) :: ";
	cin>>limit;
	auto max = 0, ans = 0;
	pyth_triplets();
	for(auto i = 0; i < limit; i++)
	{
		if(count[i] > max)
		{
			max = count[i];
			ans = i;
		}
	}
	
	cout<<endl<<"Max no of the Triangles are of :: "<<ans;

	getch();
	return 0;
}

