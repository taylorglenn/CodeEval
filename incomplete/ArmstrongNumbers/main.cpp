/*
  Name: Armstrong Numbers
  Copyright: 
  Author: Taylor Glenn
  Date: 09/02/16 06:29
  Description: 
    An Armstrong number is an n-digit number that is equal to the sum of the 
    n'th powers of its digits. Determine if the input numbers are Armstrong numbers.
    
    INPUT SAMPLE:
        6
        153
        351
    OUTPUT SAMPLE:
        Print out True/False if the number is an Armstrong number or not. E.g.
        
        True
        True
        False

*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int exponentialFunction(int,int);
vector<int> convertIntIntoVector(int);

int main(int argc, char *argv[])
{
    int input;
    while(cin >> input){
         vector<int> intVector = convertIntIntoVector(input);
         int sum = 0;
         int n = intVector.size();
         for(int i = 0; i < n; i++){
              sum += exponentialFunction(intVector[i], n);
         }
         string pass;
         if(input == sum){
              pass = "True";
         }else{
              pass = "False";
         }
         cout << pass << "\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

int exponentialFunction(int base, int exponent){
    int product = 1;
    for(int i = 0; i < exponent; i++){
         product *= base;
    }
    return product;
}
vector<int> convertIntIntoVector(int input){
    vector<int> outputVector;
    while(input != 0){
         outputVector.insert(outputVector.begin(),(input % 10));
         input /= 10;
    }
    return outputVector;
}
