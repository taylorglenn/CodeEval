/*

The input file contains multiple lines.  The first line tells you how many lines
to output.  Output however many lines you're told of the longest lines.

Input exmaple:
      2
      Hello world
      CodeEval
      Quick Fox
      A
      San Francisco
      
output example:
       San Francisco
       Hello World
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Prototypes
bool doesMyVectorAlreadyContainThisLine(vector<string>& lines, string line);
string getLongestLineInVector(vector<string>& lines);
string getShortestLineInVector(vector<string>& lines);
int findLineInVector(vector<string>& lines, string stringToSearchFor);
void printLinesInVectorLongestToShortest(vector<string>& lines);

int main(int argc, char *argv[])
{
    //ifstream inputFile;
    //inputFile.open("LongestLines.txt");
    ifstream stream(argv[1]);
    int currentLineNumber = 0;
    int numberOfLines;
    string input;
    vector<string> lines;
    while(getline(stream, input)){
         currentLineNumber++;
         if(currentLineNumber == 1){
              numberOfLines = atoi(input.c_str());
         } else {
              if(lines.size() < numberOfLines){
                   lines.push_back(input);
              } else {
                   string shortestLineInVector = getShortestLineInVector(lines);
                   if(input.length() > shortestLineInVector.length()){
                        lines[findLineInVector(lines, shortestLineInVector)] = input;
                   }
              }
         }
    }
    printLinesInVectorLongestToShortest(lines);
    //if(inputFile.is_open()){
    //     inputFile.close();
    //}
    system("PAUSE");
    return EXIT_SUCCESS;
}

bool doesMyVectorAlreadyContainThisLine(vector<string>& lines, string line){
    for(int i = 0; i < lines.size(); i++){
         if(lines[i] == line){
              return true;
         } else { 
              return false;
         }
    }
}

string getLongestLineInVector(vector<string>& lines){
    string longestLine = "";
    for(int i = 0; i < lines.size(); i++){
         if(lines[i].length() > longestLine.length()){
              longestLine = lines[i];
         }
    }
    return longestLine;
}

string getShortestLineInVector(vector<string>& lines){
    string shortestLine = "";
    shortestLine = getLongestLineInVector(lines);
    for(int i = 0; i < lines.size(); i++){
         if(lines[i].length() < shortestLine.length()){
              shortestLine = lines[i];
         }
    }
    return shortestLine;
}

int findLineInVector(vector<string>& lines, string stringToSearchFor){
    int position = 0;
    for(int i = 0; i < lines.size(); i++){
         if(lines[i] == stringToSearchFor){
              position = i;
         }
    }
    return position;
}

void printLinesInVectorLongestToShortest(vector<string>& lines){
    string lineToPrint = "";
    for(int i = 0; i < lines.size(); i++){
         lineToPrint = getLongestLineInVector(lines);
         cout << lineToPrint << "\n";
         lines[findLineInVector(lines, lineToPrint)] = "";
    }
}
