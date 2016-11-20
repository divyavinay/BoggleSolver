// BoggleSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
Dictionary dict;

 Dictionary::Dictionary()
{
	
	 root = new Node();
	 for (int i = 0; i < 26; i++)
	 {
		 root->child[i] = NULL;
		 root->is_word[i] = false;
	 }
	
	 //head->prefix_count = 0;
	 root->is_end = false;
}
 
 void ReadFile(char* filename)
 {
	 ifstream inFile;
	 inFile.open(filename);
	 string line;
	 int numWords = 0;
	 if(inFile.is_open())
		 while(getline(inFile,line))
		 {
			// cout << line << endl;
			 dict.addWord(line);
		 }
	 inFile.close();
			 //call addword
 }

 void Dictionary::addWord(string word)
 {
	 Node* current = root;
	 int length = word.length();
	 for (unsigned int i = 0; i < length ; i++)
	 {
		 int let = (int)word[i] - (int)'a';
		 if (current->child[let] == NULL )
		 {
			 if (i != length - 1)
			 {
				 current->child[let] = new Node;
				 for (int j = 0; j < 26; j++)
				 {
					 current->child[let]->child[j] = NULL;
					 current->child[let]->is_word[j] = false;
				 }
				 current = current->child[let];
			 }
		 }
	 }
	 int last = (int)word[length - 1] - (int)'a';
	 current->is_word[last] = true;
 }

 bool Dictionary::isPrefix(string word)
 {
	 Node* current = root;
	 for (unsigned int i = 0; i < word.length(); i++)
	 {
		 int let = (int)word[i] - (int)'a';
		 if (current->child[let] != NULL)
			 current = current->child[let];
		 else
			 return false;
	 }
	 return true;
 }

 bool Dictionary::isWord(string word)
 {
	 Node* current = root;
	 for (unsigned int i = 0; i < word.length(); i++)
	 {
		 int let = (int)word[i] - (int)'a';
		 if (current->child[let] != NULL && i < word.length()-1)
			 current = current->child[let];
		 else
		 { 
			 return current->is_word[let];
		 }
			
	 } 
	 
 }

int main()
{
	Node* head = new Node();
	
	ReadFile("Dictionary.txt");
	
	cout << " words loaded." << endl << endl;

	string word;
	while (true) {
	cout << "Enter string: ";
	cin >> word;

	if (dict.isWord(word)) {
	cout << word << " is a valid word" << endl;
	}
	else {
	cout << word << " is NOT a valid word" << endl;
	}

	if (dict.isPrefix(word)) {
	cout << word << " is a valid prefix" << endl;
	}
	else {
	cout << word << " is NOT a valid prefix" << endl;
	}

	cout << endl;
	}
	getchar();
    return 0;
}

