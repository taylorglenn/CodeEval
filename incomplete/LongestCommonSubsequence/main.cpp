//2 strings separated by a semicolon.
//find the largest common substring between them.
//it does not have to be contiguous.

//input sample:
        //XMJYAUZ;MZJAXU
//output sample:
         //MJAU

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void printCharVector(vector<char>&);
vector<char> returnContiguousStringBetweenVectors(vector<char>&, vector<char>&, int = 0);

void printIntVector(vector<int>&);
int findInVector(vector<char>&, char, int = 0);

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         string strA = input.substr(0, input.find(";"));
         string strB = input.substr(input.find(";") + 1, input.length());
         string strC = "";
         vector<char> vecA(strA.begin(), strA.end());
         vector<char> vecB(strB.begin(), strB.end());
         vector<char> vecC;
         for(int i = 0; i < vecA.size(); i++){
              vecC = returnContiguousStringBetweenVectors(vecA, vecB, findInVector(vecB, vecA[i], 0));
         }
         printCharVector(vecC);
    }
    return EXIT_SUCCESS;
}

void printCharVector(vector<char>& input){
    for(int i = 0; i < input.size(); i++){
         cout << input[i];
    }
    cout << "\n";
}
vector<char> returnContiguousStringBetweenVectors(vector<char>& vectorA, vector<char>& vectorB, int vectorBStartingPoint){
    vector<char> outputVector;
    
    for(int i = 0; i < vectorA.size(); i++){
         for(int j = vectorBStartingPoint; j < vectorB.size(); j++){
              if(vectorA[i] == vectorB[j]){
                   outputVector.push_back(vectorA[i]);
              }
         }
    }
    return outputVector;
}







void printIntVector(vector<int>& input){
    for(int i = 0; i < input.size(); i++){
         cout << input[i];
    }
    cout << "\n";
}

int findInVector(vector<char>& input, char charToFind, int startingPoint){
    int output = -1;
    for(int i = startingPoint; i < input.size(); i++){
         if(input[i] == charToFind){
              output = i;
         }
    }
    return output;
}
