#include<iostream>
#include<conio.h>
#include<math.h>
#include<cstring>

//10001st prime
//   
//Problem 7
//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
//What is the 10 001st prime number?

void runEratosthenesSieve(int upperBound) {

      int req_prime=upperBound;
	  upperBound*=100;
	  int sum=0;
	  int *prime;
	  prime= new  int[upperBound];
	  int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      std::memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) 
	  {
			if (!isComposite[m]) 
			{
				sum++;
				prime[sum]=m;
				for (int k = m * m; k <= upperBound; k += m)
					isComposite[k] = true;
			}
      }
      for (int m = upperBoundSquareRoot; m <= upperBound; m++)
            if (!isComposite[m])
			{
           		sum++;	
           		prime[sum]=m;
		    }
      delete [] isComposite;
      std::cout<<std::endl<<"Required Prime No is : "<<prime[req_prime];
      delete [] prime;
}
int main()
{
	int i;
	std::cout<<"Enter The Rank of Prime Number : ";
	std::cin>>i;
	runEratosthenesSieve(i);
	getch();
	return 0;
}
