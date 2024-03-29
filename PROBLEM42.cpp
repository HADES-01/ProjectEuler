#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
using namespace std;
//Coded triangle numbers
//
//Problem 42
//The nth term of the sequence of triangle numbers is given by, tn = �n(n+1); so the first ten triangle numbers are:
//
//1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
//By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
//
//Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            

bool checkTriangleNo(int no)
{
	int a = sqrt(2 * no);
	
	if((a * (a + 1)) / 2 == no)
	{
		return true;
	}
	return false;
}

int main()
{
	char ch = 'a';
	int name_sum = 0, triangle_words = 0;
	vector<int> sums;
	ifstream file("words.txt", ios::in);
	while(!file.eof())
	{
		ch = file.get();
		if(ch == ',')
		{
			sums.push_back(name_sum);
			name_sum = 0;
			continue;
		}
		else if(ch == '"')
		{
			continue;
		}
		else
		{
			name_sum += ch - 64;
		}
	}
	
	for(auto i : sums)
	{
		if(checkTriangleNo(i))\
		{
			triangle_words++;
		}
	}
	
	cout<<"No of Triangle Words :: "<<triangle_words;
	return 0;
}
