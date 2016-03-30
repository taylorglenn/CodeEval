//Find the largest - sub 1000 - palindrome number (hint: it's 929!)

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Prototypes
bool primeCheck(int number);
bool palindromeCheck(string itemToCheck);
bool isNumberEven(int number);

using namespace std;

int main(int argc, char *argv[])
{
    int output = 0;
    for(int i = 1; i < 1000; i++)
    {
            stringstream ss;
            ss << i;

            if(primeCheck(i) && palindromeCheck(ss.str()))
            {
                  output = i;    
            }
    }
    cout << output << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}

bool primeCheck(int number)
{
     //A prime number is only divisible by 1 and itself
     bool isPrime = true;
     for(int j = 2; j < number; j++)
     {
             if((number % j) == 0)
             {
                   isPrime = false;
             }
     }
     return isPrime;
}

bool palindromeCheck(string itemToCheck)
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
     bool isPalindrome = true;
     for(int q = 0; q < (number.size()/2); q++)
     {
           if(number.at(q) != number.at((number.size() - 1) - q))
           {
               isPalindrome = false;
           }
     }
    return isPalindrome;
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
