//Read in a text file with a number on each line, like this:
       // 451
       // 652
       // 875853
       // 44
       // 8009
       // etc...
// add the sum of digits for each number and return it per line on the output.

#include <cstdlib>
#include <iostream>
#include <string>  //to use the string data type

using namespace std;

int main(int argc, char *argv[])
{
    string readLine;             
        while (getline(cin, readLine)) //Makes sure to end our operations after reading the last line.
        {
              int buffer[readLine.length()];           //Create an array that is long enough to hold the number
              int value = atoi(readLine.c_str());      //convert that number (which is read in as a string) into an int value

              for (int j = readLine.length()-1; j >= 0; j--) //Load each number from the value into an array
              {
                  buffer[j] = value % 10;       //puts the last number of the value into the array
                  value /= 10;                  //removes the last number of the value from the value
              }
              int total = 0;
              for(int i = 0; i < readLine.length(); i++)
              {
                      total += buffer[i];           //sequentially adds each value from each position in the array into a single value
              }
              cout << total << endl;       
        }                                          
    //system("PAUSE");
    return EXIT_SUCCESS;
}
