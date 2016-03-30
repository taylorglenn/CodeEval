#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin, input)){
         stringstream ss(input);
         string word;
         string longestWord = "";
         while(ss >> word){
              if(word.length() > longestWord.length()){
                   longestWord = word;
              }
         }
         cout << longestWord << "\n";
    }
    return EXIT_SUCCESS;
}
