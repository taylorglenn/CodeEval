/*
Write a program which finds the first non-repeated character in a string.

*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findCharInVector(vector<char>& input, char charToFind);

int main(int argc, char *argv[])
{
    string input = "";
    while(getline(cin, input)){
         vector<char> characters(input.begin(),input.end());
         char firstNonRepeatedChar;
         for(int i = 0; i < characters.size(); i++){
              if(!(findCharInVector(characters, characters[i]) > 1)){
              	   firstNonRepeatedChar = characters[i];
              	   break;
              }
         }
         cout << firstNonRepeatedChar << "\n";
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}

int findCharInVector(vector<char>& input, char charToFind){
	int output = 0;
	for(int i = 0; i < input.size(); i++){
		 if(input[i] == charToFind){
		 	  output++;
		 }
	}
	return output;
}
