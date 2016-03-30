#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int input;
    while(cin >> input){
         int output = 0;
         if((input % 2) == 0){
              output = 1;
         }
         cout << output << "\n";
    }
    return EXIT_SUCCESS;
}
