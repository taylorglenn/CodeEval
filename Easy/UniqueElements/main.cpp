/*
  Name: 
  Copyright: 
  Author: 
  Date: 22/01/16 09:38
  Description: 
               You are given a sorted list of numbers with duplicates. Print out 
               the sorted list with duplicates removed.
               
               INPUT SAMPLE:
               File containing a list of sorted integers, comma delimited, one 
               per line. 
               1,1,1,2,2,3,3,4,4
               2,3,4,5,5
               
               OUTPUT SAMPLE:
               Print out the sorted list with duplicates removed, one per line. 
               1,2,3,4
               2,3,4,5
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> intVectorFromDelimitedString(string input, char delimiter = ',');
vector<int> removeDuplicatesFromIntVector(vector<int>& inputVector);
void printIntVector(vector<int>& vectorToPrint, char delimiter = ',');

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         vector<int> inputVector = intVectorFromDelimitedString(input, ',');
         vector<int> outputVector = removeDuplicatesFromIntVector(inputVector);
         printIntVector(outputVector);
    }
    return EXIT_SUCCESS;
}

vector<int> intVectorFromDelimitedString(string input, char delimiter){
     stringstream ss(input);
     int number;
     vector<int> outputVector;
     while(ss >> number){
          outputVector.push_back(number);
          if(ss.peek() == delimiter){
               ss.ignore();
          }
     } 
    return outputVector;
}

vector<int> removeDuplicatesFromIntVector(vector<int>& inputVector){
    vector<int> outputVector;
    for(int i = 0; i < inputVector.size(); i++){
         bool isThisIntAlreadyInThisVector = false;
         for(int r = 0; r < outputVector.size(); r++){
              if(outputVector[r] == inputVector[i]){
                   isThisIntAlreadyInThisVector = true;
                   break;
              }
         }
         if(isThisIntAlreadyInThisVector == false){
              outputVector.push_back(inputVector[i]);
         }
    }
    return outputVector;
}

void printIntVector(vector<int>& vectorToPrint, char delimiter){
    for(int i = 0; i < vectorToPrint.size(); i++){
         if(i != 0){
              cout << delimiter;
         }
         cout << vectorToPrint[i];
    }
    cout << "\n";
}
