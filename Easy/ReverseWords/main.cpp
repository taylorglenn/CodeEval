#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    string input = "";
    while(getline(cin, input)){
         istringstream stream(input);
         vector<string> words;
         string word;
         while(stream >> word){
              words.push_back(word);
         }
         for(int i = (words.size() - 1); i >= 0; i--){
              cout << words[i] << " ";
         }
         cout << "\n";
    }
    return EXIT_SUCCESS;
}
