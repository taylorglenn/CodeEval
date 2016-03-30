#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string filePath;
    cin >> filePath; //gets the path of the file from the user
    ifstream fileInQuestion;
    fileInQuestion.open(filePath.c_str(), ios::binary | ios::ate); //opens the file and places the cursor at the end
    cout << fileInQuestion.tellg();       //returns the cursor's position (i.e. the length of the file in bytes)
    //system("PAUSE");               
    return EXIT_SUCCESS;
}
