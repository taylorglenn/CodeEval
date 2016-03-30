
/*
  the first argument is a path to a file.  
  The file contains the series of spaced delimited characters followed 
  by an integer.  
  The integer represents and index in the list (1-based), one per line.
  if the int is larger than the list, ignore that input

  for example:
      a b c d 4
      e f g h 2
   output sample:
      a
      g

*/
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> createVectorFromCharDelimetedString(string, char = ' ');

int main(int argc, char *argv[])
{
    ifstream stream(argv[1]);
    string input;
    while(getline(stream,input)){
         vector<string> inputVector = createVectorFromCharDelimetedString(input,' ');
         int m = atoi(inputVector[inputVector.size() - 1].c_str());
         if(m < inputVector.size()){
              string mthToLastElement = inputVector[(inputVector.size() - 1) - m];
              cout << mthToLastElement << "\n";
         }
    }
    return EXIT_SUCCESS;
}

vector<string> createVectorFromCharDelimetedString(string input, char delimeter){
    vector<string> outputVector;
    string x;
    stringstream ss(input);
    while(ss >> x){
         outputVector.push_back(x);
         if(ss.peek() == delimeter){
              ss.ignore();
         }
    }
    return outputVector;
}
