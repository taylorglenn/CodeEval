/*
  Name: Bit Positions
  Copyright: 
  Author: Taylor Glenn
  Date: 15/01/16 15:54
  Description: Given a number n and two integers p1 and p2, determine if the bits in 
  position p1 and p2 are the same or not.  Positions p1 and p2 are 1 based.
  
  Input Sample:
        The first argument will be a path to a filename containing a comma 
        separated list of 3 integers, one list per line.
        
        86,2,3
        125,1,2
        
  Output Sample:
         Print to stdout, 'true(lowercase) if the bills are the same, else 
         'false'(lowercase)
         
         true
         false
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         int n = atoi((input.substr(0,input.find(","))).c_str());
         input.erase(0,input.find(",") + 1);
         int p1 = atoi((input.substr(0,input.find(","))).c_str());
         input.erase(0,input.find(",") + 1);
         int p2 = atoi(input.c_str());
         
         vector<int> binaryNumber(16);
         int position = 0;
         for(int i = 0; i < n; i++){
              binaryNumber[0]++;
              for(int bit = 0; bit < binary.size(); bit++){ 
                   if(binaryNumber[bit] == 2){
                        binaryNumber[bit + 1]++;
                        binaryNumber[bit] = 0;
                   }
              }
         }
         cout << "n = " << n << "\np1 = " << p1 << "\np2 = " << p2 << "\n";
         for(int q = 0; q < binaryNumber.size(); q++){
              cout << binaryNumber[q];
         }
         cout << "\n";
    }
    return EXIT_SUCCESS;
}
