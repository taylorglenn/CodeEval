//This Program is intended to sum the first 1000 prime numbers stariting at 0.
//A prime number is a whole number that is greater than 1 and is not divisible
//by any numbers other than 1 and itself.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isPrime(int num)
{
     if(num <= 1)
     {
          return false;
     }
     else if(num == 2)
     {
          return true;
     }
     else if(num % 2 == 0)
     {
          return false;
     }
     else
     {
          bool prime = false;
          int factorCount = 0;  
          for(int q = 3; q <= num; q++)
          {
                  if(num % q == 0)
                  {
                         factorCount++;
                         if (factorCount < 2)
                         {
                            prime = true;
                         } 
                         else 
                         {
                            prime = false;
                         }
                  }
          } 
          return prime;    
     } 
}
int main(int argc, char *argv[])
{
    int total = 0;
    int counter = 0;
    int i = 1;
    
    while (counter < 1000)
    {
          if(isPrime(i))
          {
            total += i;
            counter++;
          }
          i++;
    }
    cout << total;
    //system("PAUSE");
    return EXIT_SUCCESS;
}
