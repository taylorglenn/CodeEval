/*
  Name: Strings And Arrows
  Copyright: 
  Author: Taylor Glenn
  Date: 01/02/16 13:59
  Description: 
        You have a string composed of the following symbols: '>', '<', and '-'. 
        Your task is to find, count, and print to the output a number of arrows 
        in the string. An arrow is a set of the following symbols: '>>-->' or '<--<<'. 
        Note that one character may belong to two arrows at the same time. Such 
        example is shown in the line #1.
        
        INPUT SAMPLE:
            The first argument is a path to a file. Each line includes a test case 
            with a string of different length from 10 to 250 characters. The string 
            consists of '>', '<', and '-' symbols.
            For example:
                <--<<--<<
                <<>>--><--<<--<<>>>--><
                <-->>
                
        OUTPUT SAMPLE:
            Print the total number of found arrows for each test case.
            For example:
                2
                4
                0
                
        CONSTRAINTS:
            An arrow is a set of the following symbols: '>>-->' or '<--<<'.
            One symbol may belong to two arrows at the same time.
            The number of test cases is 40.
*/


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> initializeLeftArrow();
vector<char> initializeRightArrow();
void printVector(vector<char>);

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         vector<char> leftArrow = initializeLeftArrow();
         vector<char> rightArrow = initializeRightArrow();
         vector<char> inputVector(input.begin(), input.end());
         int arrowCounter = 0;
         int bufferLength = 5;
         for(int i = 0; i < inputVector.size(); i++){
              if(((inputVector[i] == '<') || (inputVector[i] == '>')) && ((i + bufferLength) <= inputVector.size())){
                   vector<char> buffer;
                   for(int j = 0; j < bufferLength; j++){
                        buffer.push_back(inputVector[i + j]);
                   }
                   cout << "Buffer: ";
                   printVector(buffer);
                   if((buffer == leftArrow) || (buffer == rightArrow)){
                        arrowCounter++;
                   }
              }
         }
         cout << "Left Arrow: ";
         printVector(leftArrow);
         cout << "Right Arrow: ";
         printVector(rightArrow);
         cout << "Count of arrows: " << arrowCounter << "\n";
    }
    return EXIT_SUCCESS;
}

vector<char> initializeLeftArrow(){
    vector<char> outputVector;
    outputVector.push_back('<');
    outputVector.push_back('-');
    outputVector.push_back('-');
    outputVector.push_back('<');
    outputVector.push_back('<');
    return outputVector;
}

vector<char> initializeRightArrow(){
    vector<char> outputVector;
    outputVector.push_back('>');
    outputVector.push_back('>');
    outputVector.push_back('-');
    outputVector.push_back('-');
    outputVector.push_back('>');
    return outputVector;
}

void printVector(vector<char> inputVector){
    for(int i = 0; i < inputVector.size(); i++){
         cout << inputVector[i];
    }
    cout << "\n";
}
