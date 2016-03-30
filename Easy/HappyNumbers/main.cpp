#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void printIntVector(vector<int>& intVector, char delimiter = ',');

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         int inputNumber = atoi(input.c_str());
         int counter = 0;
         while((inputNumber != 1) && (counter < 100)){
              int modNumber = inputNumber;
              vector<int> numbers;
              for(int i = 0; i < input.length(); i++){
                   numbers.push_back(modNumber % 10);
                   modNumber /= 10;
              }
              int nextInputNumber = 0;
              for(int n = 0; n < numbers.size(); n++){
                      nextInputNumber += (numbers[n]*numbers[n]);
              }
              inputNumber = nextInputNumber;
              counter++;
         }
         if(inputNumber == 1){
              cout << "1\n";
         } else {
              cout << "0\n";
         }
    }
    return EXIT_SUCCESS;
}

void printIntVector(vector<int>& intVector, char delimiter){
     for(int p = 0; p < intVector.size(); p++){
             if(p > 0){
                  cout << delimiter;
             }
             cout << intVector[p];
     }
     cout << "\n";
}
