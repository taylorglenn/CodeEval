/*
	Name: Clean Up The Words
	Copyright: 
	Author: Taylor Glenn
	Date: 18/01/16 00:13
	Description:

	You have a list of words. Letters of these words are mixed with extra symbols, 
	so it is hard to define the beginning and end of each word. Write a program that 
	will clean up the words from extra numbers and symbols.
	
	INPUT SAMPLE:
	
	The first argument is a path to a file. Each line includes a test case with a 
	list of words: letters are both lowercase and uppercase, and are mixed with 
	extra symbols.
	
	For example:
	
	(--9Hello----World...--)
	Can 0$9 ---you~
	13What213are;11you-123+138doing7
	
	OUTPUT SAMPLE:
	
	Print the cleaned up words separated by spaces in lowercase letters.
	
	For example:
	
	hello world
	can you
	what are you doing
	CONSTRAINTS:
	
	Print the words separated by spaces in lowercase letters.
	The length of a test case together with extra symbols can be in a range from 10 to 100 symbols.
	The number of test cases is 40.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool isLetter(char character);

int main(int argc, char *argv[]) {
	string input;
	bool spaceNext = false;
	while(getline(cin,input)){
		vector<char> line(input.begin(), input.end());
		for(int i = 0; i < line.size(); i++){
			if(isLetter(line[i])){
				char letter = tolower(line[i]);
				cout << letter;
				spaceNext = true;
			}else if(spaceNext){
				cout << " ";
				spaceNext = false;
			}
		}
		cout << "\n";
	}
	return 0;
}

bool isLetter(char character){
	bool letter = false;
	for(char charsAThroughZ = 'a'; charsAThroughZ <= 'z'; charsAThroughZ++){
		if(tolower(character) == charsAThroughZ){
			letter = true;
		}
	}
	return letter;
}
