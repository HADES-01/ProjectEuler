#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

//Double-base palindromes
//
//Problem 36
//The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
//
//Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
//
//(Please note that the palindromic number, in either base, may not include leading zeros.)

bool check_palin_base_10(int no){
	int number = no, reverse = 0;
	while(number > 0){
		reverse = (reverse * 10) + (number % 10);
		number /= 10;
	}
	if(reverse == no){
		return true;
	}
	else{
		return false;
	}
}

bool check_palin_base_2(int no){
	int number = no;
	bool temp = 0;
	vector<bool> binary, binary_rev;
	while(number > 1){
		if(number % 2 == 0){
			binary.push_back(0);
		}
		else{
			binary.push_back(1);
		}
		number /= 2;
	}
	binary.push_back(1);
	for(auto j = binary.end() - 1; j >= binary.begin(); j--){
		binary_rev.push_back(*j);
	}
	for(auto i = binary.begin(), j = binary_rev.begin(); i < binary.end(); i++, j++){
		if(*i != *j)
			return false;
	}
	return true;
}

int main(){
	int limit = 1000000, sum = 0, k = 0;
	cout<<"Enter the Limit upto which you wnt to check for such no (PE 1000000) :: ";
	cin>>limit;
	for(int i = 1; i < limit; i++)
	{
		if(check_palin_base_10(i) && check_palin_base_2(i))
		{
			k++;
			cout<<k<<" . "<<i<<endl;
			sum+=i;
		}
	}
	cout<<endl<<"SUM OF ALL SUCH NUMBERS IS :: "<<sum;
	getch();
	return 0;
}

