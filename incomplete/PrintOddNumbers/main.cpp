//Print all odd numbers from 1 to 99.

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    for(int x = 1; x <= 99; x += 2)
    {
        cout << x << endl;
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}
