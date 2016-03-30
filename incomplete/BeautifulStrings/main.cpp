/*

When John was a little kid he didn't have much to do. There was no internet, no 
Facebook, and no programs to hack on. So he did the only thing he could... he 
evaluated the beauty of strings in a quest to discover the most beautiful string 
in the world. 

Given a string s, little Johnny defined the beauty of the string as the sum of 
the beauty of the letters in it. The beauty of each letter is an integer between 
1 and 26, inclusive, and no two letters have the same beauty. Johnny doesn't 
care about whether letters are uppercase or lowercase, so that doesn't affect 
the beauty of a letter. (Uppercase 'F' is exactly as beautiful as lowercase 'f', 
for example.) 

You're a student writing a report on the youth of this famous hacker. You found 
the string that Johnny considered most beautiful. What is the maximum possible 
beauty of this string?

*/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <locale>
#include <map>

using namespace std;

//Prototypes
void printCharVector(vector<char>& charVector);
vector<char> convertCharVectorToLower(vector<char>& charVector);
map<char,int> initializeLetterList(map<char,int> letterList);
char getLetterWithHighestCount(map<char, int> letterList);
string removePunctuationAndSpaces(string input);

int main(int argc, char *argv[]) {
	string inputString = "";
	while(getline(cin,inputString)){
		//remove spaces and punctuation from input string
		inputString = removePunctuationAndSpaces(inputString);
		
		//Store string in a vector
		vector<char> inputVector(inputString.begin(), inputString.end());
		
		//convert string to all lowercase
		vector<char> lowercaseInputVector;
		lowercaseInputVector = convertCharVectorToLower(inputVector);
		
		//Count how many of each character
		map<char,int> letterList;
		letterList = initializeLetterList(letterList);
		for(int i = 0; i < lowercaseInputVector.size(); i++){
			letterList[lowercaseInputVector[i]]++;
		}
	
		//Assign values to highest count starting at 26 and decreasing afterwards
		map<char, int> letterValue;
		letterValue = initializeLetterList(letterValue);
		for(int valueAssignment = 26; valueAssignment > 0; valueAssignment--){
			char mostFrequentLetter = getLetterWithHighestCount(letterList);
			letterValue[mostFrequentLetter] = valueAssignment * letterList[mostFrequentLetter]; //value of each letter * number of each letter
			letterList[mostFrequentLetter] = 0; //Set quantity to 0 so it doesn't register again
		}
		int totalBeauty = 0;
		for(char letter = 'a'; letter <= 'z'; letter++){
			if(letterValue[letter] != 0){
				totalBeauty += (letterValue[letter]);
			}
		}
		cout << totalBeauty << "\n";
	}
	return 0;
}

void printCharVector(vector<char>& charVector){
	for(int q = 0; q < charVector.size(); q++){
		cout << charVector[q];
	}
}

vector<char> convertCharVectorToLower(vector<char>& charVector){
	for(int q = 0; q < charVector.size(); q++){
		charVector[q] = tolower(charVector[q]);
	}
	return charVector;
}

map<char,int> initializeLetterList(map<char,int> letterList){
	for(char letter = 'a'; letter <= 'z'; letter++){
		letterList[letter] = 0;
	}
	return letterList;
}

char getLetterWithHighestCount(map<char, int> letterList){
	char letterWithHighestCount;
	int highestCount = 0;
	for(char letter = 'a'; letter <= 'z'; letter++){
		if(letterList[letter] > highestCount){
			highestCount = letterList[letter];
			letterWithHighestCount = letter;
		}
	}
	return letterWithHighestCount;
}

string removePunctuationAndSpaces(string input){
	for (int r = 0, len = input.size(); r < len; r++){
        if ((ispunct(input[r])) || input[r] == ' '){
            input.erase(r--, 1);
            len = input.size();
        }
    }
	return input;
}
