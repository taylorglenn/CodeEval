#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    while (getline(cin,input)){
         int total = 0;
         vector<char> intRegister(input.begin(), input.end());
         for (int i = 0; i < intRegister.size(); i++){
              int n = intRegister[i] - '0';
              total += n;
         }
         cout << total << "\n";
    }
    return EXIT_SUCCESS;
}
