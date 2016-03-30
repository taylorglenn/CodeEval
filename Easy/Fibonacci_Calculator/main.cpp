/*******************************************************
Problem:
The fibonacci series is defined as:
    F(0) = 0;
    F(1) = 1;
    F(n) = F(n-1) + F(n-2) when n > 1.
Given a positive integer 'n', print out the F(n).

*******************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Prototypes
long fibonacci(int n);

int main(int argc, char *argv[])
{
    string inputString;
    while(getline(cin, inputString)){
         int n = atoi(inputString.c_str());
         cout << fibonacci(n) << "\n";
    }
    return 0;
}

long fibonacci(int n){
    vector<int> fibonacciTable;
    for(int i = 0; i <= (n + 1); i++){
         switch(i){
              case 0:
                   fibonacciTable.push_back(0);
                   break;
              case 1:
                   fibonacciTable.push_back(1);
                   break;
              default:
                   fibonacciTable.push_back(fibonacciTable[i-1] + fibonacciTable[i-2]);
                   break;
         }
    }
    return fibonacciTable[n];
}
