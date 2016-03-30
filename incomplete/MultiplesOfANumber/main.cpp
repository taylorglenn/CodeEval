/*
  Name: Multiples Of A Number
  Copyright: na
  Author: Taylor Glenn
  Date: 15/01/16 15:16
  Description: Given numbers x and n, where n is a power of 2, print out the smallest
  multiple of n which is greater than or equal to x.  Do not use the division or
  modulo operator.
  
  Input Sample:
        13,8
        17,16
  
  Output Sample:
         16
         32
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         string delimeter = ",";      
         int x = atoi((input.substr(0,input.find(delimeter)).c_str()));
         input.erase(0,input.find(delimeter) + 1);
         int n = atoi((input).c_str());
         for(int i = 1;;i++){
         	if((n * i) >= x){
         		cout << (n * i) << "\n";
         		break;
         	}
         }
    }
    return EXIT_SUCCESS;
}
