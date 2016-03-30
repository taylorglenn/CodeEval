#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> convertDelimitedStringIntoIntVector(string input, char delimiter = ',');
int mod(int n, int m);

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         vector<int> inputVector = convertDelimitedStringIntoIntVector(input, ',');
         int N = inputVector[0];
         int M = inputVector[1];
         cout << mod(N,M) << "\n";
    }
    return EXIT_SUCCESS;
}

vector<int> convertDelimitedStringIntoIntVector(string input, char delimiter){
    vector<int> outputIntVector;
    stringstream ss(input);
    int n = 0;
    while(ss >> n){
         outputIntVector.push_back(n);
         if(ss.peek() == delimiter){
              ss.ignore();
         }
    }
    return outputIntVector;
}

int mod(int n, int m){
    return n - (m * (n/m));
}
