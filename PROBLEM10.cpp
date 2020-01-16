#include<iostream>
#include<math.h>
#include<cstring>
#include<conio.h>
#include<iomanip>

//Summation of primes
//   
//Problem 10
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

void runEratosthenesSieve(int upperBound) {

	  double sum=0;
	  int upperBoundSquareRoot = (int)sqrt((double)upperBound);

      bool *isComposite = new bool[upperBound + 1];

      std::memset(isComposite, 0, sizeof(bool) * (upperBound + 1));

      for (int m = 2; m <= upperBoundSquareRoot; m++) {

            if (!isComposite[m]) {

                  //std::cout<<m<<" ";
				  sum+=m;
                  
                  for (int k = m * m; k <= upperBound; k += m)

                        isComposite[k] = true;

            }

      }

      for (int m = upperBoundSquareRoot; m <= upperBound; m++)

            if (!isComposite[m])
			{
           		//std::cout<<m<<" ";
				sum+=m;	
            }
    std::cout<<"\nRequire sum is : ";
    std::cout.setf(std::ios::fixed);
	std::cout <<std::setprecision(0) << sum;
      delete [] isComposite;
}
int main()
{
	int no;
	std::cout<<"Program to Find the sum of all the Prime No below a Given no";
	std::cout<<"\nPE 2000000";
	std::cout<<"\n\nEnter the no : ";
	std::cin>>no;
	runEratosthenesSieve(no);
	getch();
	return 0;
}
