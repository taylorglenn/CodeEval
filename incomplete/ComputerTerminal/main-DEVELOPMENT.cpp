#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//<Prototypes>
void clearScreen();       //^c -  clear the entire screen; the cursor row and column do not change 
void resetCursor();       //^h -  move the cursor to row 0, column 0; the image on the screen is not changed 
void returnCursor();      //^b -  move the cursor to the beginning of the current line; the cursor row does not change 
void moveCursorDown();    //^d -  move the cursor down one row if possible; the cursor column does not change 
void moveCursorUp();      //^u -  move the cursor up one row, if possible; the cursor column does not change 
void moveCursorLeft();    //^l -  move the cursor left one column, if possible; the cursor row does not change 
void moveCursorRight();   //^r -  move the cursor right one column, if possible; the cursor row does not change 
void eraseLine();         //^e -  erase characters to the right of, and including, the cursor column on the 
                          //      cursor's row; the cursor row and column do not change 
bool enterInsertMode();   //^i -  enter insert mode 
bool enterOverwriteMode();//^o -  enter overwrite mode 
void writeCircumflex();   //^^ -  write a circumflex (^) at the current cursor location, exactly as if it
                          //      was not a special character; this is subject to the actions of the current mode (insert or overwrite) 
void moveCursor(int,int); //^DD - move the cursor to the row and column specified; each D represents a 
                          //      decimal digit; the first D represents the new row number, 
                          //      and the second D represents the new column number 
bool isCharDecimal(char);
void writeCharacter(char,bool);
void eraseCharacter(int,int);
//</Prototypes>

//<Global variables>
char screen[10][10];
int cursorX = 0;
int cursorY = 0;
//</Global variables>

int main(int argc, char *argv[])
{
    ifstream sampleInput(argv[1]);
    string input;
    bool mode = enterOverwriteMode();
    while(getline(sampleInput,input)){
         for(string::iterator i = input.begin(); i < input.end(); i++){
              if(*i == '^'){
                   char controlCharacter1 = *(i+1);
                   char controlCharacter2 = *(i+2);
                   if(isCharDecimal(controlCharacter1) && isCharDecimal(controlCharacter2)){
                        moveCursor(controlCharacter2 - '0', controlCharacter1 - '0');
                        i++;
                   }
                   else if(controlCharacter1 == 'c'){
                        clearScreen();
                   }
                   else if(controlCharacter1 == 'h'){
                        resetCursor();
                   }
                   else if(controlCharacter1 == 'b'){
                        returnCursor();
                   }
                   else if(controlCharacter1 == 'd'){
                        moveCursorDown();
                   }
                   else if(controlCharacter1 == 'u'){
                        moveCursorUp();
                   }
                   else if(controlCharacter1 == 'l'){
                        moveCursorLeft();
                   }
                   else if(controlCharacter1 == 'r'){
                        moveCursorRight();
                   }
                   else if(controlCharacter1 == 'e'){
                        eraseLine();
                   }
                   else if(controlCharacter1 == 'i'){
                        mode = enterInsertMode();
                   }
                   else if(controlCharacter1 == 'o'){
                        mode = enterOverwriteMode();
                   }
                   else if(controlCharacter1 == '^'){
                        writeCharacter('^', mode);
                   }
                   i++;              
              } else{
                   writeCharacter(*i, mode);
              }
         } 
    }
    return EXIT_SUCCESS;
}
void clearScreen(){
    //^c -  clear the entire screen; the cursor row and column do not change 
    for(int y = 0; y < 10; y++){
         for(int x = 0; x < 10; x++){
              eraseCharacter(x,y);
         }
    }
}
void resetCursor(){
    //^h -  move the cursor to row 0, column 0; the image on the screen is not changed 
    cursorX = 0;
    cursorY = 0;
}
void returnCursor(){
    //^b -  move the cursor to the beginning of the current line; the cursor row does not change 
    cursorX = 0;
}
void moveCursorDown(){
    //^d -  move the cursor down one row if possible; the cursor column does not change 
     if(cursorY < 9){
         cursorY++;
     }
}
void moveCursorUp(){
    //^u -  move the cursor up one row, if possible; the cursor column does not change 
     if(cursorY > 0){
         cursorY--;
     }
}
void moveCursorLeft(){
    //^l -  move the cursor left one column, if possible; the cursor row does not change 
     if(cursorX > 0){
         cursorX--;
     }
}
void moveCursorRight(){
    //^r -  move the cursor right one column, if possible; the cursor row does not change 
     if(cursorY < 9){
         cursorY++;
     }
}
void eraseLine(){
    //^e -  erase characters to the right of, and including, the cursor column on the 
    //      cursor's row; the cursor row and column do not change 
    for(int x = cursorX; x < 10; x++){
        screen[x][cursorY] = '\0';
    }
}
bool enterInsertMode(){
    //^i -  enter insert mode
    return false;
} 
bool enterOverwriteMode(){
    //^o -  enter overwrite mode 
    return true;
}
void writeCircumflex(){
    //^^ -  write a circumflex (^) at the current cursor location, exactly as if it
    //      was not a special character; this is subject to the actions of the current mode (insert or overwrite) 
    screen[cursorX][cursorY] = '^';
}
void moveCursor(int x,int y){
    //^DD - move the cursor to the row and column specified; each D represents a 
    //      decimal digit; the first D represents the new row number, 
    //      and the second D represents the new column number 
    cursorX = x;
    cursorY = y;
}
bool isCharDecimal(char input){
    bool output;
    if(((input - '0') > -1) && ((input - '0') < 10)){
        output = true;
    } else {
        output = false;
    }
    return output;
}
void writeCharacter(char character, bool mode){
    //overwriteMode = true, insertMode = false 
    if(!mode){
         for(int x = 9; x > cursorX; x--){
              screen[x][cursorY] = screen[x-1][cursorY];
         }
    }
    screen[cursorX][cursorY] = character;
    moveCursorRight();
}
void eraseCharacter(int x, int y){
    screen[x][y] = '\0';
}
