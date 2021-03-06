//#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;


struct Borrower
{
	string borrowFirst;		//Holds Borrower First Name
	string borrowLast;		//Holds Borrower Last Name
	string checkout;		//Holds checkout date
	string deadline;		//Holds deadline date
};

typedef list<Borrower> Borrow_History;
typedef Borrow_History::iterator list_it;	//Give alias for iterator

struct Book
{
	string Title;			//Holds Book Title
	string authorFirst;		//Holds author first name
	string authorLast;		//Holds author last name
	string Year;				//Holds Book year
	string owner;			//Owner of book
	Borrow_History Borrow;	//Holds Borrow History
};

class Bookstore
{
public:
	void InitializeStore();
	void registerBook();
	void printBooks() const;
	//Bookstore();

	vector<Book> Books;		//Vecotr array of Type Books

private:

	Book psedoDatabase();
};

void Bookstore::InitializeStore()
{
	//Setup Bookstore
	Books.push_back(psedoDatabase());
	Books.push_back(psedoDatabase());
}
void Bookstore::registerBook()
{
	//Register Book
	Book temp;

	temp.Title = "The Great Gatsby";
	temp.authorFirst = "F. Scott";
	temp.authorLast = "Fitzgerald";
	temp.Year = "1925";
	temp.owner = "Jimmy Swansky";
	Books.push_back(temp);
	
	
}

void Bookstore::printBooks() const
{

	cout << "Book List: \n" << endl;
	cout << setw(49) << left << "Title" << setw(20) << left << "Author" << setw(18) << left << "Year" << setw(18) << left << "Owner" << endl;
	for (int i = 0; i < Books.size(); i++)
	{
		cout << setw(48) << left << Books[i].Title
			 << setw(20) << left <<Books[i].authorFirst + " " + Books[i].authorLast
			 << setw(18) << left << Books[i].Year
			 << setw(18) << left << Books[i].owner << endl;
	}
		
}


Book Bookstore::psedoDatabase()
{
	string Random;
	
	
	//Database Entries
	string fname[10] = { "James", "Michael", "Robert", "Maria", "David", "Mary", "James", "Brianna", "Tommy", "Pedro" };
	string lname[10] = { "Smith", "Garcia", "Rodriguez", "Hernandez", "Johnson", "Jones", "Jackson", "Williams", "Davis", "Angelou" };
	string BookList[8] = { "The Lord of the Rings; J.R.R; Tolkien; 1955", "Harry Potter and the Philosopher's Stone; J.K.; Rowling; 1997",
						   "And Then There Were None; Agatha; Christie; 1939", "Alice's Adventures in Wonderland; Lewis; Carroll; 1865",
						    "The Lion The Witch and The Wardrobe; C.S.; Lewis; 1950", "The Odyssey; Homer; ; 8th Century BC",
							"To Kill a Mockingbird; Harper; Lee; 1960", "Gone With the Wind; Margaret; Mitchell; 1936" };
	//Create Type of Book
	Book temp;

	//Generate Owner and assign to temp
	Random = fname[rand() % 9];
	temp.owner = Random;

	Random = lname[rand() % 9];
	temp.owner += " " + Random;

	//Generate Book to register and assign to temp
	Random = BookList[rand() % 4];
	string delimiter = ";";
	size_t pos = 0;
	string token;

	pos = Random.find(delimiter);
	temp.Title = Random.substr(0, pos);
	Random.erase(0, pos + delimiter.length());

	pos = Random.find(delimiter);
	temp.authorFirst = Random.substr(0, pos);
	Random.erase(0, pos + delimiter.length());

	pos = Random.find(delimiter);
	temp.authorLast = Random.substr(0, pos);
	Random.erase(0, pos + delimiter.length());

	temp.Year = Random;

	return temp;
}

int main()
{
	Bookstore B;
	srand(time(NULL));

	cout << "            WELCOME to the BOOKSTORE            " << endl;
	
	B.InitializeStore();
	
	cout << "\n\nBooks currently registered in store" << endl;
	B.printBooks();

	//Register a Book
	cout << "\n\nRegister a new book: " << endl;
	B.registerBook();
	B.printBooks();

	system("pause");
    return 0;
}


