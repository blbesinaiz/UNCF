/**********************************************************
Programmer: Brianna Besinaiz
Program Title: Reverse Lexical
Program Description: Program generates a list of pseudo-random
					 numbers and sorts them by reverse order.
***********************************************************/

#include <iostream>
//#include <string>
#include <list>
#include <stdlib.h>		//srand
#include <time.h>		//seed srand

using namespace std;

void Generate_List(int, list<double>&); 
void printList(list<double> list);

list<double> myNum;	
list<double>::iterator list_it;

int main()
{
	int numTerms;	//Holds number of terms
	int nthTerm;	//Holds nth term
	
	srand (time(NULL));
	
	//Ask user
	std::cout << "Please enter a value for the number of terms to generate: ";
	std::cin >> numTerms;
	
	//Input validation
	while(!std::cin || numTerms <= 1)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\nPlease enter an integer number greater than 1!" << std::endl;
		std::cin >> numTerms;
	}
	
	//Generate Terms	
	Generate_List(numTerms, myNum);
	
	//Print to user
	std::cout << "Generated List: " << endl;
	printList(myNum);
	
	//Sort List
	myNum.sort();
	
	//Reverse List
	myNum.reverse();
	
	//Print to user
	std::cout << "Sorted in Reverse lexical order: " << endl;
	printList(myNum);
	
	return 0;
}

//Funcation generates pseudo random terms
void Generate_List(int num, list<double>& numList) 
{ 
   double temp;
   
   for(int i = 0; i < num; i++)
   {
		temp = rand() % 1000;
		numList.push_back(temp);	
   }
} 

//Function prints list
void printList(list<double> list)
{
	for (list_it = list.begin();  list_it != list.end(); list_it++)
	{
		cout << *list_it << " ";
	}
	cout << "\n\n";	
}
