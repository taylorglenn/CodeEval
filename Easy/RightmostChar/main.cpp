/*
input:
      Hello World,r
      Hello CodeEval,E
output:
       8
       10
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    while(getline(cin,input)){
         vector<char> line(input.begin(), input.end());
         float positionInString = -1;
         for(int i = 0; i < (line.size() - 2); i++){
              if(line[i] == line[line.size() - 1]){
                   positionInString = i;
              }
         }
         cout << positionInString << "\n";
         
    }
    return EXIT_SUCCESS;
}
