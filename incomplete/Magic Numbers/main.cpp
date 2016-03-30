/*
There are two wizards, one good and one evil. The evil wizard has captured the 
princess. The only way to defeat the evil wizard is to recite a set of magic 
numbers. The good wizard has given you two numbers, A and B. Find every magic 
number between A and B, inclusive.

A magic number is a number that has two characteristics:

No digits repeat.
Beginning with the leftmost digit, take the value of the digit and move that 
number of digits to the right. Repeat the process again using the value of the 
current digit to move right again. Wrap back to the leftmost digit as necessary. 
A magic number will visit every digit exactly once and end at the leftmost digit.
For example, consider the magic number 6231.

Start with 6. Advance 6 steps to 3, wrapping around once (6->2->3->1->6->2->3).
From 3, advance to 2.
From 2, advance to 1.
From 1, advance to 6.

INPUT SAMPLE:
The input is a file with each line representing a test case.  Each
test case consists of two integers A and B on a line, separated by spaces.
For all test cases 1 <= A <= B <= 10000

10 100
8382 8841

OUTPUT SAMPLE:
For each test case print all magic numbers between A and B, inclusive, on one 
line, separated by spaces. If there is no magic number between A and B, print -1.

13 15 17 19 31 35 37 39 51 53 57 59 71 73 75 79 91 93 95 97
-1

CONSTRAINTS:

The number of test cases is 20.
*/


#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class inputTable                   
        {
          public:
            inputTable();
         //   ~inputTable();
            int getA();
            int getB();
            void setA(int inputA);
            void setB(int inputB);
            void CheckValues();
         private:
            int table[1];
            //int A;
            //int B;
        };
        //Constructor
        inputTable::inputTable()
        {
          table[0] = 1;
          table[1] = 1;
          //A = 1;
          //B = 1; 
        }
        //Destructor 
        /*
        inputTable::~inputTable()
        {
        }*/
        int inputTable::getA()
        {
            //return A;
            return table[0];
        }
        int inputTable::getB()
        {
            //Return B;
            return table[1];
        }
        void inputTable::setA(int inputA)
        {
             //A = inputA;
             if ((inputA >= 1) && (inputA <= 10000)){
                table[0] = inputA;
                }
        }
        void inputTable::setB(int inputB)
        {
             //B = inputB;
             if ((inputB >= 1) && (inputB <= 10000)){
                table[1] = inputB;
                }
        }
        void inputTable::CheckValues()
        {
           //cout << "A: " << A << "\nB: " << B << endl;
           cout << "A: " << table[0] << "\nB: " << table[1] << endl;
        }
// </Class inputTable>

int getInput()
{
    
}

int main(int argc, char *argv[])
{
    int A = 1;
    int B = 1;
    int C = 1;
    inputTable magicNumberInputTable;
    
    cout << "Please enter two whole numbers A and B where " << endl;
    cout << "  1 <= A <= B <= 10000\nEnter these numbers on one line, separated by a space." << endl;
    cin >> A;
    cin >> B;
    if((A < 1) || (A > 10000) || (A > B)){
          A = 10;
          }
    if((B < 1) || (B > 10000) || (A > B)){
          B = 100;
          }
    magicNumberInputTable.setA(A);
    magicNumberInputTable.setB(B);
    
    magicNumberInputTable.CheckValues();
    //cout << "DEBUG\nA: " << magicNumberInputTable.getA() << "\nB: " << magicNumberInputTable.getB() << endl;;
    
    //First, load each into an array
    vector<int> arrayA;
    arrayA.reserve(5); //I know the input won't be bigger than 10,000, so reserving 5 elements is enough and keeps the vector from taking up too much memory.
    while(A!=0){
                arrayA.push_back(A % 10);
                A /= 10;
                }
    vector<int> arrayB;
    arrayB.reserve(5);
    while(B!=0){
                arrayB.push_back(B % 10);
                B /= 10;
                }
    
    int iterator = 0;
    int focus = arrayA[iterator];
    int position = arrayA.size();
    vector<int> magicNumberArrayA;
    
    
    
    //do{
        for(int i = 0; i < arrayA[focus]; i++){
                magicNumberArrayA[0] = (arrayA[position]);
                if (position > 0){
                             position--;
                             } 
                else {
                             position = arrayA.size();
                             }
                cout << "FOR LOOP:\n    MN ARRAY = " << magicNumberArrayA[0] << "\n    Position = " << position << endl;
                cout << "    i = " << i << "\n    focus = " << focus << endl;
                }
        iterator++;
        focus = arrayA[iterator];
        cout << "DO LOOP:\n    Iterator = " << iterator << "\n    Focus = " << focus << endl;
        //}while(iterator <= arrayA.size());
        
                
                
                
    for (int m = 0; m < arrayA.size(); m++)
    {
        cout << arrayA[m];
    }
            
    
    C = magicNumberInputTable.getB() - magicNumberInputTable.getA();
    for(int i = 0; i < C; i++)
    {
            
    }
            
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
