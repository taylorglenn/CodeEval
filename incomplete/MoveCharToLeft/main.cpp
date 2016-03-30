#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string shiftStringToRight(string);

int main(int argc, char *argv[]){
    string input = "abcd";
    string newString = input;
    string output = "";
    for(int i = 0;i < input.length(); i++){      
         for(int j = 0; j < input.length(); j++){
              cout << newString << "\n";
              output = shiftStringToRight(newString);
              newString = output;
         }
         cout << "---------\n";
    }
    system("PAUSE");
    return 0;
}

string shiftStringToRight(string input){
    vector<char> inputVector(input.begin(), input.end());
    string output = "";
    output += inputVector[inputVector.size() - 1];
    for(int i = 0; i < inputVector.size() - 1; i++){
         output += inputVector[i];
    }
    return output;
}
