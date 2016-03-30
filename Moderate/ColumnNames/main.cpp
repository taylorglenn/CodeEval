/*
Microsoft Excel uses a special convention to name its column headers. The first 
26 columns use the letters 'A' to 'Z'. Then, Excel names its column headers 
using two letters, so that the 27th and 28th column are 'AA' and 'AB'. After 
'ZZ', Excel uses three letters.

Write a function that takes as input the number of the column, and returns its 
header. The input will not ask for a column that would be greater than 'ZZZ'.

INPUT SAMPLE:

The first argument is a path to a file. Each line of the input file contains 
one test case represented by one integer.

52
3702
OUTPUT SAMPLE:

For each test case your program must print one line containing the Excel column 
heading corresponding to the integer in the input.

AZ
ELJ

CONSTRAINTS:

The number of test cases is 40.
The input will not ask for a column that would be greater than 'ZZZ'.
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string inputString = "";
    char baseLine = 'A' - 1;
    char decade = 'Z' + 1;
    while(getline(cin,inputString)){
         int input = atoi(inputString.c_str());
         char header[3] = {baseLine, baseLine, baseLine};
         int headerPosition = 0;
         for(int i = 0; i < input; i++){
              header[0]++;
              for(int h = 0; h < sizeof(header); h++){
                      if(header[h] == decade){
                           header[h] = 'A';
                           header[h + 1]++;
                      }
              } 
         }
         for(int r = 3; r >= 0; r--){
              if(header[r] > baseLine){
                   cout << header[r];
              }
         }
         cout << "\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
