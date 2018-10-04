/**********************************************************
Programmer: Brianna Besinaiz
Program Title: Stack Sort
Program Description: Program uses only the stack data structure
					 to sort a sequence of number from lowest
					 to highest
***********************************************************/
#include<iostream>
#include<string>
#include <stdlib.h>		//srand
#include <time.h>		//seed srand
#include <stack>

using namespace std;

void generateStack(stack<int> &, int);
void printStack(stack<int>);
void sortStack(stack<int> &);
bool checkSort(stack<int>);

int main()
{
	int numGenerate;
	srand (time(NULL));
	stack<int> s;
	
	cout << "Please enter the amount of numbers to generate for the stack: ";
	cin >> numGenerate;
	
	//Input validation
	while(!cin || numGenerate <= 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nPlease enter an integer number greater than 1!" << endl;
		cin >> numGenerate;
	}
	
	//Generate stack of random numbers
	generateStack(s, numGenerate);
	
	//Print stack
	cout << "\n\nStack before sorting: " << endl;
	printStack(s);
	
	//Sort stack
	sortStack(s);
	
	//Print stack
	cout << "\n\nStack after sorting: " << endl;
	printStack(s);
	
	return 0;
}

void generateStack(stack<int> &s, int num)
{
	int counter = 0;
	int random;
	
	while(counter < num)
	{
		random = rand() % 1000;
		s.push(random);
		counter++;
	}
}

void printStack(stack<int> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}

void sortStack(stack<int> &s)
{
	stack<int> temp;
	int value;
	bool sorted = false;
	
	//Get top element
	value = s.top();
	s.pop();
	while(!s.empty())
	{
	
		if(value < s.top())
		{
			temp.push(value);
			value = s.top();
			s.pop();
		}
		else
		{
			temp.push(s.top());
			s.pop();
			
		}		
	}
	temp.push(value);
	while(!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
	
	sorted = checkSort(s);
	if(sorted == false)
		sortStack(s);
}

bool checkSort(stack<int> s)
{
	int temp;
	
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		
		if((!s.empty()) && (temp > s.top()))
		{
			return false;
		}			
	}
	return true;
}





