/**********************************************************
Programmer: Brianna Besinaiz
Program Title: Unique Strings
Program Description: Program determines whether a sting has
					 all unique characters
***********************************************************/
#include <iostream>
#include <string>

using namespace std;

bool stringUnique(string);

int main()
{
	string userResponse;
	bool flag = false;
	
	cout << "Please enter a string: ";
	cin >> userResponse;
	
	while(!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter only a string!" << endl;
	}
	
	//Call function to evaluate
	flag = stringUnique(userResponse);
	if(flag == true)
	{
		cout << "\nThe string: '" << userResponse << "' contains all unique characters" << endl;
	}
	else
		cout << "\nThe string: '" << userResponse << "' DOES NOT contain unique characters" << endl;
		
	return 0;	
}

bool stringUnique(string word)
{
	for(int i = 0; i < word.length(); i++)
	{
		for(int j = i + 1; j < word.length(); j++)
		{
			if(word[i] == word[j])
				return false;
		}
	}
	
	return true;
}
