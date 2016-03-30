#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int hexStringToDecimalInt(string);
int findInVector(vector<char>&, char);
vector<char> initializeHexTableVector();
int exponential(int, int);

int main(int argc, char *argv[])
{
    //ifstream stream(argv[1]);
    string input;
    while(getline(cin,input)){
    //while(getline(stream,input)){
         vector<char> testVector(input.begin(), input.end());
         int decimalNumber = hexStringToDecimalInt(input);
         cout << decimalNumber << "\n";
    }
    return EXIT_SUCCESS;
}

int hexStringToDecimalInt(string hex){
    int decimal = 0;
    vector<char> hexTableVector = initializeHexTableVector();
    vector<char> hexVector(hex.begin(), hex.end());
    for(int i = 0; i < hexVector.size(); i++){
         int positionInVector = (hexVector.size() - 1) - i;
         int decimalValueOfHexChar = findInVector(hexTableVector, hexVector[i]);
         decimal += decimalValueOfHexChar * (exponential(16,positionInVector));
    }
    return decimal;
}

int findInVector(vector<char>& inputVector, char charToFind){
    int output = -1;
    for(int i = 0; i < inputVector.size(); i++){
         if(inputVector[i] == charToFind){
              output += inputVector.size() - i;
              break;
         }
    }
    return output;
}

vector<char> initializeHexTableVector(){
    vector<char> outputVector;
    for(char i = '0'; i <= '9'; i++){
         outputVector.insert(outputVector.begin(), i);
    }
    for(char a = 'a'; a < 'g'; a++){
         outputVector.insert(outputVector.begin(), a);
    }
    return outputVector;
}

int exponential(int base, int power){
    int product = 1;
    for(int i = 0; i < power; i++){
         product *= base;
    }
    return product;
}
