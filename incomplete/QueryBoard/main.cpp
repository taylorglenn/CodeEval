/*
There is a board (matrix). Every cell of the board contains one integer, which is 0 initially. 

The next operations can be applied to the Query Board: 
SetRow i x: it means that all values in the cells on row "i" have been changed to value "x" after this operation. 
SetCol j x: it means that all values in the cells on column "j" have been changed to value "x" after this operation. 
QueryRow i: it means that you should output the sum of values on row "i". 
QueryCol j: it means that you should output the sum of values on column "j". 

The board's dimensions are 256x256 
"i" and "j" are integers from 0 to 255 
"x" is an integer from 0 to 31 
INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Each line in this file contains an operation of a query. E.g.

SetCol 32 20
SetRow 15 7
SetRow 16 31
QueryCol 32
SetCol 2 14
QueryRow 10
SetCol 14 0
QueryRow 15
SetRow 10 1
QueryCol 2
OUTPUT SAMPLE:

For each query, output the answer of the query. E.g.

5118
34
1792
3571
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class board{
    public:
         int boardRows;
         int boardCols;
         int **boardMap;
         board(int,int);
         void setRow(int,int);
         void setCol(int,int);
         int queryRow(int);
         int queryCol(int);
         void erase();
         void print();
    private:
         void write(int,int,int);
         int read(int,int);
};
board::board(int i, int j){
    boardRows = i;
    boardCols = j;
    boardMap = new int * [boardRows];
    for (int r = 0; r < boardRows; r++) {
        boardMap[r] = new int [boardCols]; 
    }
}
void board::setRow(int i, int x){
    for(int j = 0; j < boardCols; j++){
         write(j,i,x);
    }
}
void board::setCol(int j, int x){
    for(int i = 0; i < boardRows; i++){
        write(j,i,x);
    }
}
int board::queryRow(int i){
    int sum = 0;
    for(int j = 0; j < boardCols; j++){
         sum += read(j,i);
    }
    return sum;
}
int board::queryCol(int j){
    int sum = 0;
    for(int i = 0; i < boardRows; i++){
         sum += read(j,i);
    }
    return sum;
}
void board::erase(){
    for(int i = 0; i < boardRows; i++){
         for(int j = 0; j < boardCols; j++){
              write(j,i,0);
         }
    }
}
void board::print(){
    for(int i = 0; i < boardRows; i++){
         for(int j = 0; j < boardCols; j++){
              cout << " [" << j << "][" << i << "] = " << read(j,i);
         }
         cout << "\n";
    }
    cout << "\n";
}
void board::write(int j, int i, int x){
    boardMap[j][i] = x;
}
int board::read(int j, int i){
    return boardMap[j][i];
}

int main(int argc, char *argv[])
{
    board queryBoard(256,256);
    queryBoard.erase();
    ifstream stream(argv[1]);
    string input = "";
    //while(getline(cin,input)){
    while(getline(stream,input)){
         string intermediateString;
         vector<string> commandParameters;
         stringstream ss(input);
         while(ss >> intermediateString){
              commandParameters.push_back(intermediateString);
         }
         string commandName = commandParameters[0];
         int argument_1 = atoi(commandParameters[1].c_str());
         int argument_2 = 0;
         if (commandParameters.size() > 2){
              argument_2 = atoi(commandParameters[2].c_str());
         }
         if(commandName == "SetCol"){
              queryBoard.setCol(argument_1, argument_2);
         } else if (commandName == "SetRow"){
              queryBoard.setRow(argument_1, argument_2);
         } else if (commandName == "QueryCol"){
              cout << queryBoard.queryCol(argument_1) << "\n";
         } else if (commandName == "QueryRow"){
              cout << queryBoard.queryRow(argument_1) << "\n";
         }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
