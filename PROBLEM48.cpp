#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//Self powers
//
//Problem 48
//The series, 11 + 22 + 33 + ... + 1010 = 10405071317.
//
//Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.

vector<vector<int>> Powers;

void calcSelfPowers(int no){
	vector<int> power;
	power.push_back(1);
	for(int i =  0; i < no; i++){
		int carry = 0;
		for(auto &j : power){
			j = j * no + carry;
			if(j < 10){
				carry = 0;
			}
			else{
				carry = j / 10;
				j %= 10;
			}
		}
		if(carry < 10 && carry != 0){
			power.push_back(carry);
		}
		else{
			while(carry){
				power.push_back(carry % 10);
				carry /= 10;
			}
		}
	}
	if(Powers.size() >= 1){
		for(int i = Powers[0].size() - power.size() - 1; i >= 0; i--){
			power.push_back(0);
		}
	}
	Powers.push_back(power);
}

vector<int> powersSum;

void sumPowers(){
	int sum = 0, carry = 0;
	for(int i = 0; i < Powers[0].size(); i++){
		sum = 0;
		sum += carry;
		for(int j = 0; j < Powers.size(); j++){
			sum += Powers[j][i];
		}
		if(sum < 10){
			carry = 0;
		}
		else{
			carry = sum / 10;
			sum %= 10;
		}
		powersSum.push_back(sum);
	}
	if(carry != 0 && carry < 10){
		powersSum.push_back(carry);
	}
	else{
		while(carry){
			powersSum.push_back(carry % 10);
			carry /= 10;
		}
	}
}

int main(){
	int no = 1000;
	cout<<"Enter the No upto which Sum of Self Powers are to Calculated (PE 1000) :: ";
	cin>>no;
	for(int i = no; i > 0; i--){
		calcSelfPowers(i);
	}
//	for(auto i : Powers){
//		for(auto j : i){
//			cout<<j<<" ";
//		}
//		cout<<endl<<endl;
//	}
	sumPowers();
	cout<<endl<<"Sum is :: ";
	for(auto i = powersSum.end(); i != powersSum.begin(); i--){
		cout<<*i;
	}
	cout<<powersSum[0];
	return 0;
}

