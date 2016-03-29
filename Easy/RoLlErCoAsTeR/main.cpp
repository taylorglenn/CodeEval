#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
     //ifstream stream(argv[1]);
	 ifstream stream("C:\\Users\\Taylor\\Documents\\Projects\\CodeEval\\RoLlErCoAsTeR\\test.txt");
	 string inputText;
     while (getline(stream,inputText))
     {
         bool upperCase = false; //false is upper, true is lower
         char inputBuffer[inputText.size()];
         //load the inputText into an array.
         strcpy(inputBuffer, inputText.c_str());
         for(int i = 0; i <= sizeof(inputBuffer); i++)
         {
              if((!ispunct(inputBuffer[i])) && (inputBuffer[i] != ' ')) //if the character is not punctuation or a space
              {
                   if (!upperCase)inputBuffer[i] = toupper(inputBuffer[i]);
                   if (upperCase)inputBuffer[i] = tolower(inputBuffer[i]);
                   upperCase = !upperCase; //toggles uppercase to lowercase
              }
              cout << inputBuffer[i];
         }
         cout << endl;
         upperCase = false;
     }
     return EXIT_SUCCESS;
}
