/*
  S - Start (This is your initial position)
  F - Finish (This is the point wher eyou need to lead the army to)
  P - Port (The plac where the army ets on board a ship, or gets off a ship onto land)
  ^ - Mountains (Which you should bypass)
  * - Empty cells (where you can safely move by ship or by land)
  
  Each step to a new cell takes 2 hours by land or 1 hour by sea, 
  gettng on the ship and landing the army also take 1 hour each.
  Calculate the shortest ammount of time you can take.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string input = "";
    
    ifstream inputFile("C:\\Dev-Cpp\\Projects\\WWIF\\Map.txt");
    if(inputFile.is_open())
    {
         while(getline(inputFile,input))
         {
              vector<char> map;
              char map1[3][3];
              int mapr = 0;
              int mapx = 0;
              int mapy = 0;
              string::iterator i;
              for(i = input.begin(); i < input.end(); i++)
              {
                    if((*i == 'S') || (*i == 'F') || (*i == 'P') || (*i == '^') || (*i == '*'))
                    {
                         map1[mapx][mapy] = *i;
                         map.push_back(*i);
                         mapx++;
                         if(mapx > 3)
                         {
                               mapx = 0;
                         }
                         if((((mapr % 4) == 0)) && (mapy !=0))
                         {
                              mapy++; 
                         }
                         mapr++;
                    }
              }
              /*
              for(int r = 0; r < map.size(); r++)
              {
                    if(r % 4 == 0)
                    {
                         cout << "\n";
                    }
                    cout << map.at(r);
              }
              */
              for(int y = 0; y < 3; y++)
              {
                      for(int x = 0; x < 3; x++)
                      {
                              cout << map1[x][y];
                      }
                      cout << "\n";
              }
              cout << "\n";
         }
         inputFile.close();
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
