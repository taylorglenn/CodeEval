/*
Players generally sit in a circle. The first player says the number “1”, and 
each player says next number in turn. However, any number divisible by X 
(for example, three) is replaced by the word fizz, and any divisible by Y 
(for example, five) by the word buzz. Numbers divisible by both become fizz 
buzz. A player who hesitates, or makes a mistake is eliminated from the game.

Write a program that prints out the final series of numbers where those 
divisible by X, Y and both are replaced by “F” for fizz, “B” for buzz 
and “FB” for fizz buzz.

INPUT SAMPLE:

Your program should accept a file as its first argument. The file contains 
multiple separated lines; each line contains 3 numbers that are space delimited. 
The first number is the first divider (X), the second number is the second 
divider (Y), and the third number is how far you should count (Z). You may 
assume that the input file is formatted correctly and the numbers are valid 
positive integers.

For example:

1
2
3 5 10
2 7 15
OUTPUT SAMPLE:

Print out the series 1 through Z replacing numbers divisible by X with “F”, 
numbers divisible by Y with “B” and numbers divisible by both with “FB”. 
Since the input file contains multiple sets of values, your output should 
print out one line per set. Ensure that there are no trailing empty spaces 
in each line you print.

1
2
1 2 F 4 B F 7 8 F B
1 F 3 F 5 F B F 9 F 11 F 13 FB 15
CONSTRAINTS:

The number of test cases = 20
"X" is in range [1, 20]
"Y" is in range [1, 20]
"Z" is in range [21, 100]
*/


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string input;                   //3 inputs from file
    int X = 0;                      //Fizz
    int Y = 0;                      //Buzz
    int Z = 0;                      //Number to count
    
    //cout << "Please enter in FIZZ BUZZ parameters (x y z) separated by a single space: ";
    //cin >> X >> Y >> Z;
    //cout << "\nX = " << X << "\nY = " << Y << "\nZ = " << Z << endl;
    while(getline(cin,input)){
        stringstream linestream(input);
        int value;
        vector<int> XYZ;                //Vector to hold X, Y, and Z
        while(linestream >> value){
                         XYZ.push_back(value);
                         }
        X = XYZ[0]; 
        Y = XYZ[1]; 
        Z = XYZ[2];                                       
        for(int i = 1; i <= Z; i++){
                if((i % X) == 0){
                      cout << "F";
                      }
                if((i % Y) == 0){
                      cout << "B";
                      }
                if(((i % X) != 0) && ((i % Y) != 0)){
                       cout << i;
                       }
                cout << " ";
                }
        cout << endl; 
        }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
