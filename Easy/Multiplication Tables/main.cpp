//Create a multiplication table with each item spaced evenly
/*
The first few lines would look like this:
   1   2   3   4   5   6   7   8   9  10  11  12
   2   4   6   8  10  12  14  16  18  20  22  24
   3   6   9  12  15  18  21  24  27  30  33  36
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int getNumberOfSpaces(int number){
    int spaces = 0;
    while(number != 0){
          number /= 10;
          spaces ++;
    }
    return spaces;
}

int main(int argc, char *argv[])
{
beginMain:
    char userChoice = 'n';
    int tableSize = 12; //Default of 12
    cout << "Enter the limit of your multiplication table: ";
    cin >> tableSize;
    if (tableSize > 19){
       cout << "Sorry, due to the size constraits of the console, you cannot " <<
               "have a table limit greater than 19.  Please enter again." << endl;
       goto beginMain;
    }
    cout << endl;
    for (int y = 1; y <= tableSize; y++){
        for (int x = 1; x <= tableSize; x++){
            for (int c = 0; c < ((getNumberOfSpaces(tableSize * tableSize) + 1) - getNumberOfSpaces(x * y)); c++){
                cout << " ";
            }
            cout << x * y;
        }
    cout << endl;
    }
    cout << endl << "Would you like to generate another table? (Y/N) ";
    cin >> userChoice;
    if (toupper(userChoice) == 'Y'){
       cout << endl;
       goto beginMain;
    }
    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
