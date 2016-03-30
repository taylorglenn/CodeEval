#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> decimalToBinary(int decimalNumber);
void printIntVector(vector<int> vectorToPrint);

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         int decimalInput = atoi(input.c_str());
         vector<int> binaryNumber = decimalToBinary(decimalInput);
         cout << binaryNumber.size() << "\n";
         printIntVector(binaryNumber);
    }
    return 0;
}

vector<int> decimalToBinary(int decimalNumber){
    vector<int> binaryNumber;
    binaryNumber.push_back(0);
    for(int i = 0; i <= decimalNumber; i++){
         binaryNumber[0]++;
         for(int bit = 0; bit < binaryNumber.size(); bit++){
              if(binaryNumber[bit] == 2){         
                   if(bit == (binaryNumber.size() - 1)){
                        binaryNumber.push_back(0);
                   }
                   binaryNumber[bit] == 0;
                   binaryNumber[bit + 1]++;
              }
         }
    }
    return binaryNumber;
}

void printIntVector(vector<int> vectorToPrint){
    for(int i = 0; i < vectorToPrint.size(); i++){
         cout << vectorToPrint[i];
    }
    cout << "\n";
}
