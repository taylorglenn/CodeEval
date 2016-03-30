/*
  Name: Self-Describing Numbers
  Copyright: 
  Author: Taylor Glenn
  Date: 26/01/16 10:41
  Description: 
               A number is self-describing when (assuing digit positions are 
               labeled 0 to N-1) the digit in each position is equal to the 
               number of times that digit appears in the number.
               
               Input Sample:
                     2020
                     22
                     1210
                     
               Output Sample:
                      if the number is a self-describing number, print out 1, 
                      if not, print out 0
                      1
                      0
                      1
               
               Clarification:
                      2020 is a self-describing numer because position '0' has 
                      value 2 and there are two 0's int he number.  Position '1' 
                      has value 0 because there are no 1's in the nmumber.  
                      Position '2' has value 2 and there are two 2's.  Position 
                      '3' has value 0 and there are 0 3's.
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> convertStringIntoIntVector(string input);
int countOfIntInVector(vector<int>& inputVector, int intToFind);

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         int output = 1;
         vector<int> number = convertStringIntoIntVector(input);
         for(int i = 0; i < number.size(); i++){
              if(countOfIntInVector(number, i) != number[i]){
                   output = 0;
                   break;
              }
         }
         cout << output << "\n";
    }
    return EXIT_SUCCESS;
}

vector<int> convertStringIntoIntVector(string input){
    vector<int> output;
    int convertedNumber = atoi(input.c_str());
    for(int i = 0; i < input.length(); i++){
         output.insert(output.begin(), (convertedNumber % 10));
         convertedNumber /= 10;
    }
    return output;
}

int countOfIntInVector(vector<int>& inputVector, int intToFind){
    int output = 0;
    for(int i = 0; i < inputVector.size(); i++){
         if(inputVector[i] == intToFind){
              output++;
         }
    }
    return output;
}
