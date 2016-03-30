/*
The problem is as follows:
    Choose a number, reverse its digits, and add it to 
    the original.  If the sum is not a palindrome, repeat
    this procedure.  
    For example:
        195 (initial number) + 591 = 786
        786 + 687 = 1473
        1473 + 3741 = 5214
        5214 + 4125 = 9339 (palindrome)
        
    In this particular case, the palendrome 9339 appeared
    after the 4th addition.  Your file should accept as its 
    first argument a file path.  Each line in thsi file is one test
    casae.  Each test case will contain an integer n < 10,000.
    Assume each test case will always have an answer that is
    computable with less than 100 itterations. Output example is
    4 9339 for 195 as the input.
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Prototypes
bool palendromeCheck(string itemToCheck);
bool isNumberEven(int number);

int main(int argc, char *argv[])
{
    const int counterMax = 100;
    string input = "";
    string reverseNumberToTest = "";
    int numberToTestINT = 0;
    int reverseINT = 0;
    int newINT = 0;

    while(getline(cin,input))
    {
        int counter = 0;
        string numberToTest = input;

        while(!palendromeCheck(numberToTest))
        {     
            //create a new string that is the reverse of your input
            reverseNumberToTest = string(numberToTest.rbegin(), numberToTest.rend());
            //convert it and your input to ints
            numberToTestINT = atoi(numberToTest.c_str());
            reverseINT = atoi(reverseNumberToTest.c_str());
            //add them
            newINT = numberToTestINT + reverseINT;
            //Convert it back to a string for use with palendromeCheck function
            stringstream ss;
            ss << newINT;
            numberToTest = ss.str();
            //increment your counter
            counter++;
            //exit loop if counter is over whatever I set the max to
            if(counter >= counterMax)
            {
                 break;
            }
        }
        if(palendromeCheck(numberToTest))
        {
            cout << counter << " " << numberToTest << endl;
        } else {
            cout << "Could not resolve " << input << " in " << counter << " tries.\n";
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

bool palendromeCheck(string itemToCheck)
{
     //Store each character in a vector
     vector<char> number;
     string::iterator i;
     for(i = itemToCheck.begin(); i < itemToCheck.end(); i++)
     {
             number.push_back(*i);
             //cout << *i;
     }
     if((!isNumberEven(itemToCheck.length())) && (itemToCheck.length() > 1))
     {
          int middle = ((itemToCheck.length()/2));

          //remove the middle character, it doesn't matter
          number.erase(number.begin() + middle);
     }
     //compare the first half of the vector to the reverse of the second half
     bool isPalendrome = true;
     for(int q = 0; q < (number.size()/2); q++)
     {
           if(number.at(q) != number.at((number.size() - 1) - q))
           {
               isPalendrome = false;
           }
     }
    return isPalendrome;
}

bool isNumberEven(int number)
{
     bool answer;
     if(number % 2 == 0)
     {
          answer = true;
     } else {
          answer = false;
     }
     return answer;
}
