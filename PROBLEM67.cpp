#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//Maximum path sum II
//
//Problem 67
//By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//
//3
//7 4
//2 4 6
//8 5 9 3
//
//That is, 3 + 7 + 4 + 9 = 23.
//
//Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'),
//a 15K text file containing a triangle with one-hundred rows.
//
//NOTE: This is a much more difficult version of Problem 18.
//It is not possible to try every route to solve this problem, as there are 299 altogether!
//If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all.
//There is an efficient algorithm to solve it. ;o)

int maxOfTwo(int a, int b)
{
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main()
{
	char ch;
	int no = 0, dig = 0, max = 1, n = 0;
	vector<vector<int>> triangle;
	fstream file("p067_triangle.txt");
	vector<int> row;
	while(!file.eof())
	{
		if(n == max)
		{
			max++;
			triangle.push_back(row);
			row.clear();
			n = 0;
		}
		if(dig == 2)
		{
			n++;
			row.push_back(no);
//			cout<<no<<" ";
			no = 0;
			dig = 0;
		}
		file>>ch;
		no = no*10 + ((int)ch - 48);
		dig++;
	}
	triangle.push_back(row);
	int path_sum = 0, j = 0;
	int line = triangle.size();
	for(int i = line - 2; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			triangle[i][j] += maxOfTwo(triangle[i+1][j], triangle[i+1][j + 1]);
		}
	}
	cout<<"Path sum :: "<<triangle[0][0];
	return 0;
}

