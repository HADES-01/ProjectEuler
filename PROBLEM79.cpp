#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

//Passcode derivation
//
//Problem 79
//A common security method used for online banking is to ask the user for three random characters from a passcode.
//For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
//
//The text file, keylog.txt, contains fifty successful login attempts.
//
//Given that the three characters are always asked for in order,
//analyse the file so as to determine the shortest possible secret passcode of unknown length.

int act_hash[10] = {0};
int search(int n){
	for(int i = 0; i < 10; i++){
		if(act_hash[i] == n)
		{
			return i;
		}
	}
}

int main()
{
	int no = 0, i = 0;
	char ch;
	vector<vector<int>> trials;
	vector<int> trial;
	fstream file("p079_keylog.txt");
	while(!file.eof())
	{
		if(i == 3)
		{
			trials.push_back(trial);
			trial.clear();
			i = 0;
			continue;
		}
		file >> ch;
		no = ((int)ch - 48);
  		trial.push_back(no);
		i++;
	}
	int hash[10][3] = {0};
	for(int k = 0; k < 3; k++)
	{
		for(int i = 0; i < trials.size(); i++)
		{
			hash[trials[i][k]][k]++;
		}
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
   			hash[i][j] *= 3 - (j);
		}
		for(int k = 0; k < 3; k++)
		{
			if(hash[i][k] > act_hash[i])
			{
				act_hash[i] = hash[i][k];
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < 10; i++)
	{
		ans.push_back(act_hash[i]);
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for(auto x: ans)
	{
		cout<<search(x);
	}
	return 0;
}

