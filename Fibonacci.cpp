/**********************************************************
Programmer: Brianna Besinaiz
Program Title: Fibonacci nth Element
Program Description: Program iteratively returns the nth 
					 term of a Fibonacci sequence
***********************************************************/

#include <iostream>
#include <string>

int Calculate_Fib(int);

int main()
{
	int numTerms;	//Holds number of terms
	int nthTerm;	//Holds nth term
	
	//Ask user
	std::cout << "Please enter the number of Fibonacci Terms" << std::endl;
	std::cin >> numTerms;
	
	//Input validation
	while(!std::cin || numTerms <= 1)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please enter an integer number greater than 1!" << std::endl;
		std::cin >> numTerms;
	}
	
	//Assign nth term value	
	nthTerm = Calculate_Fib(numTerms);
	
	//Print to user
	std::cout << "Nth term of a " << numTerms << " term Fibonacci sequence: " << nthTerm << std::endl;
	
	return 0;
}

//Funcation calcuates nth term of sequence
int Calculate_Fib(int n) 
{ 
   if (n <= 1)
      return n; 
   return Calculate_Fib(n-1) + Calculate_Fib(n-2); 
} 

