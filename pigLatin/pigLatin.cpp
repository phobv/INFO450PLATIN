// pigLatin.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

void translateToPigLatin(char word[50]);
bool conjunctionCheck(char word[50]);
void checkForVowels(char word[50]);
int main()
{
	char answer;
	//asks the user to run the program again
	do
	{
		char word[50];

		cout << "Welcome to PigLatin Translator" << endl;
		cout << "Words must be less than 50 characters" << endl;

//if the user didnt put enough characters, runs again if they want to
		do
		{
			cout << endl;
			cout << "Please enter a word: ";
			cin.getline(word, 50);
			cout << endl;

			//if first character is not a number, blank, or over 51, shows error
			
			if (!isdigit(word[0]) && strlen(word)>0 && strlen(word)<51)
			{
				translateToPigLatin(word);
				break;
			}
			else
				cout << "Your word cannot be blank, begin with a number,"
				"or be longer than 50 characters!" << endl;
			cout << "To try again enter Y/y: ";
			cin >> answer;
			cin.ignore();
			cout << endl;

		} while (answer == 'Y' || answer == 'y');

		cout << "Do you want to translate another word? (Y/y for yes): ";
		cin >> answer;
		cin.ignore();
		cout << endl;

	} while (answer == 'Y' || answer == 'y');
	return 0;
}

//this translates users word

void translateToPigLatin(char word[50])
{
	if (conjunctionCheck(word) == false)
	{
		if (strlen(word) < 3)
		{
			cout << "Your word in pig latin is: " << word << endl;
		}
		else
		{//this calls the checkForVowels function
			checkForVowels(word);
		}
	}
	else
		cout << " Your word in pig latin is: " << word << endl;
}


//this checks for conjunctions and articles

bool conjunctionCheck(char word[50])
{
	if (!strcmp(word, "the"))
	{
		return true;
	}
	if (!strcmp(word, "a"))
	{
		return true;
	}
	if (!strcmp(word, "an"))
	{
		return true;
	}
	if (!strcmp(word, "and"))
	{
		return true;
	}
	if (!strcmp(word, "but"))
	{
		return true;
	}
	if (!strcmp(word, "for"))
	{
		return true;
	}
	if (!strcmp(word, "nor"))
	{
		return true;
	}
	if (!strcmp(word, "so"))
	{
		return true;
	}
	if (!strcmp(word, "yet"))
	{
		return true;
	}
	if (!strcmp(word, "or"))
	{
		return true;
	}
	else
		return false;
}

//this checks for uppercase and lower case vowels
void checkForVowels(char word[50])
{
	int UcVowels, LcVowels;



	UcVowels = (word[0] == 'A' || word[0] == 'E' || word[0] == 'I' ||
		word[0] == 'O' || word[0] == 'U');

	LcVowels = (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||
		word[0] == 'o' || word[0] == 'u');

	if (UcVowels || LcVowels)
	{

		cout << "Your word in pig latin is: " << word << "ay" << endl;

	}

	else

	{
		char temp = word[0];
		int i;

		for (i = 0; i < 50 - 1 && word[i + 1] != 0; i++)
		{
			word[i] = word[i + 1];
		}
		word[i] = temp;
		cout << "Your word in pig latin is: " << word << "ay" << endl;
	}
}

