#include<iostream>
using namespace std;

//Concealed Square
//
//Problem 206
//Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
//where each “_” is a single digit.

bool check(long long int x){
	auto square = x * x;
	int a[] = {0,9,8,7,6,5,4,3,2,1}, i = 0;
	do{
		auto dig = square % 10;
		if(dig != a[i++]){
			return false;
		}
		square /= 100;
	}while(square > 0);
	return true;
}

int main()
{
	long long int min = 1010101010, max=1389026620;
	for(int i = max; i >= min; i -= 10){
		if(check(i)){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

