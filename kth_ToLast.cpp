/**********************************************************
Programmer: Brianna Besinaiz
Program Title: kth To Last
Program Description: Program finds the kth to last element
					 of a list
***********************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>		//srand
#include <time.h>		//seed srand

using namespace std;

struct listType;
typedef listType* listPtr;

struct listType
{
	int data;
	listPtr next;
};

class KthElement
{
	public:
		void loadList(int);
		void reverseList();
		int kthPlace(int);
		void printList();
		
		KthElement();
		
	private:
		listPtr ElementList;		//Declare list to pass amongst functions
		int size;					//Variable to hold size of arrays
};

KthElement::KthElement()
{
	size = 0;
}

void KthElement::loadList(int num)
{
	ElementList = NULL;			//Set empty list to point to NULL
	listType temp;			//Creat a pointer called temp
	listPtr tempPtr;			//name temp pointer
	
	for(int i = 0; i < num; i++)
	{
		//create new node that looks like myType
		tempPtr = new listType;
		
		//Generate random value
		tempPtr->data = rand() % 1000;
		
		//Set new node to point ot what ElementList points to (NULL)
		tempPtr->next = ElementList;
		
		//ElementList now points to new node
		ElementList = tempPtr;
		
		size++;
	}
}

void KthElement::printList()
{
	for (listPtr p = ElementList; p !=NULL; p = p->next)		//Loop to print contents of list
	{
		cout << p->data << " ";				
	}
	cout << "\n";
}

int KthElement::kthPlace(int k)
{
	int kTerm;
	int counter = 1;
	int kPlace = size - k + 1;
	
	for (listPtr p = ElementList; p !=NULL; p = p->next)
	{
		if(counter == kPlace)
		{
			kTerm = p->data;
			return kTerm;
		}
		counter++;
	}
}

int main()
{
	KthElement k;
	srand (time(NULL));
	
	int numTerms;
	int kTerm;
	int value;
	
	//Ask user
	cout << "Please enter a value for the number of terms to generate in the list: ";
	cin >> numTerms;
	
	//Input validation
	while(!cin || numTerms <= 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nPlease enter an integer number greater than 1!" << std::endl;
		cin >> numTerms;
	}
	
	cout << "Please enter a value 'k' from the end of the list: ";
	cin >> kTerm;
	
	//Input validation
	while(!cin || numTerms <= 1 || kTerm > numTerms)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nPlease enter a positive integer value that is smaller than the list size!" << endl;
		cin >> kTerm;
	}
	
	
	k.loadList(numTerms);
	
	cout << "\nElements in list: " << endl;
	k.printList();
	
	value = k.kthPlace(kTerm);
	cout << "\nValue of number " << kTerm << " from end of the list: " << value;
	
	
	return 0;
}
