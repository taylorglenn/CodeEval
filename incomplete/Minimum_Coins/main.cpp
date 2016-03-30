/*
CODEEVAL CHALLENGE:
         
         
You are given 3 coins of value 1, 3 and 5. You are also given a total which you 
have to arrive at. Find the minimum number of coins to arrive at it.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Each line 
in this file contains a positive integer number which represents the total you 
have to arrive at. E.g.

11
20
OUTPUT SAMPLE:

Print out the minimum number of coins required to arrive at the total. E.g.

3
4

*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class CoinPurse
{     
      public:
             int pennyValue, nickelValue, dimeValue, quarterValue;
             int pennyCount, nickelCount, dimeCount, quarterCount;
      
             CoinPurse(int,int,int,int);
             void addCoin(string);
             void removeCoin(string);
             int returnValue();
             int returnPennyCount();
             int returnNickelCount();
             int returnDimeCount();
             int returnQuarterCount();
             int coinCount();
             };
CoinPurse::CoinPurse(int p, int n, int d, int q){
     pennyValue = p;
     nickelValue = n;
     dimeValue = d;
     quarterValue = q;
     
     pennyCount = 0;
     nickelCount = 0;
     dimeCount = 0;
     quarterCount = 0;
     }
void CoinPurse::addCoin(string coinName){   
     if (coinName == "penny"){
        pennyCount++;
        }
     if (coinName == "nickel"){
        nickelCount++;
        }
     if (coinName == "dime"){
        dimeCount++;
        }
     if (coinName == "quarter"){
        quarterCount++;
        }
     }
void CoinPurse::removeCoin(string coinName){
     if (coinName == "penny"){
        pennyCount--;
        }
     if (coinName == "nickel"){
        nickelCount--;
        }
     if (coinName == "dime"){
        dimeCount--;
        }
     if (coinName == "quarter"){
        quarterCount--;
        }
     }
int CoinPurse::returnValue(){
    return((pennyCount * pennyValue) + (nickelCount * nickelValue) + (dimeCount * dimeValue) + (quarterCount * quarterValue));
    }
int CoinPurse::coinCount(){
    return(pennyCount + nickelCount + dimeCount + quarterCount);
    }
int CoinPurse::returnPennyCount(){
    return pennyCount;
    }
int CoinPurse::returnNickelCount(){
    return nickelCount;
    }
int CoinPurse::returnDimeCount(){
    return dimeCount;
    }
int CoinPurse::returnQuarterCount(){
    return quarterCount;
    }
int main(int argc, char *argv[])
{
    int target = 0;
    cout << "What is your target value?: ";
    cin >> target;
    
    CoinPurse pocket (1,3,5,0); //no quarters will be used
    /*
    while ((pocket.returnValue() + pocket.quarterValue) <= target){
          pocket.addCoin("quarter");
          }
    //*/
    while ((pocket.returnValue() + pocket.dimeValue) <= target){
          pocket.addCoin("dime");
          }
    while ((pocket.returnValue() + pocket.nickelValue) <= target){
          pocket.addCoin("nickel");
          }
    while ((pocket.returnValue() + pocket.pennyValue) <= target){
          pocket.addCoin("penny");
          }
    
    cout << "Your target is " << target << " cents." << endl;
    cout << "Your pocket has " << pocket.returnValue() << " cents worth of change in it." << endl;
    cout << "Your pocket has " << pocket.coinCount() << " coins in it." << endl;
    cout << "There are " << pocket.returnPennyCount() << " " << pocket.pennyValue << " cent coins in your pocket." << endl;
    cout << "There are " << pocket.returnNickelCount() << " " << pocket.nickelValue << " cent coins in your pocket." << endl;
    cout << "There are " << pocket.returnDimeCount() << " " << pocket.dimeValue << " cent coins in your pocket." << endl;
    cout << "There are " << pocket.returnQuarterCount() << " " << pocket.quarterValue << " cent coins in your pocket." << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
