#include<iostream>
#include<vector>
using namespace std;

//Square digit chains
//
//Problem 92
//A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
//
//For example,
//
//44 ? 32 ? 13 ? 10 ? 1 ? 1
//85 ? 89 ? 145 ? 42 ? 20 ? 4 ? 16 ? 37 ? 58 ? 89
//
//Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop.
//What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
//
//How many starting numbers below ten million will arrive at 89?

int limit = 10000000;
vector<vector<int>> cache = {{0}};
int squareDigitSum(int n)
{
	int sum = 0;
	while(n)
	{
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	return sum;
}

int createSquareChain()
{
	int ctr = 0;
	for(int i = 1; i <= limit; i++)
	{
		vector<int> chain;
		int no = i;
		while(1){
			int dig_sum = squareDigitSum(no);
			chain.push_back(dig_sum);
			if(dig_sum == 89){
				ctr++;
				break;
			}
			else if(dig_sum == 1){
				break;
			}
			else if(i >= 1000 && cache[dig_sum].size() != 0)
			{
				if(cache[dig_sum].back() == 89){
					ctr++;
				}
				for(auto x : cache[dig_sum]){
					chain.push_back(x);
				}
				break;
			}
			no = dig_sum;
		}
		cache.push_back(chain);
		chain.clear();
	}
	return ctr;
}

int main()
{
	cout<<createSquareChain();
	return 0;
}

