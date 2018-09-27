/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * The ProcessMap class contains methods used to generate the next generation map, copy this map to the current generation
   map to be printed, and print the map. 
 */

#include "ProcessMap.h"
#include <iostream>
#include <fstream>

using namespace std;

ProcessMap::ProcessMap()
{
}

ProcessMap::~ProcessMap()
{
}

/*
 * LiveOrDie
 * This function takes an array of cell neighbors and the character/cell being evaluated as its arguments. It
   evaluates the neighbors to determine how many living cells surround the evaluated cell. A count variable is
   used to count how many living neighbors there are. This count number is then used to see whether the evaluated
   cell lives or dies based on the rules of the game.
 */
char ProcessMap::LiveOrDie(char arrN[], char cell)
{
  int count = 0;
  for(int i = 0; i < 8; i++)
  {
    if(arrN[i] == 'X')
      count++;
  }

  if(count == 2)
    return cell;
  else if(count == 3)
    return 'X';

  return '-';
}

/*
 * PrintMap
 * This function prints a 2d array arr to the screen using a for loop.
 */
void ProcessMap::PrintMap(char** arr, int height, int width)
{
  for(int h = 1; h < height-1; h++)
  {
    for(int w = 1; w < width-1; w++)
    {
      cout << arr[h][w];
    }
    cout << "\n";
  }
}

/*
 * GenerateNextGen
 * This function loops through the arrCurrent and arrNextGen arrays and creates a character array neighbors which
   contains the 8 neighbors of the cell in arrCurrent being evaluated. The function LiveOrDie is called and passed
   the neighbors array as well as the evaluated cell from arrCurrent. The character returned by the LiveOrDie function
   is assigned to a corresponding cell in arrNextGen.
 */
void ProcessMap::GenerateNextGen(char** arrCurrent, char** arrNextGen, int height, int width)
{
  for(int h = 1; h < height-1; h++)
  {
    for(int w = 1; w < width-1; w++)
    {
      char neighbors[] = {arrCurrent[h-1][w-1], arrCurrent[h-1][w], arrCurrent[h-1][w+1], arrCurrent[h][w-1],
         arrCurrent[h][w+1], arrCurrent[h+1][w-1], arrCurrent[h+1][w], arrCurrent[h+1][w+1]};
      char current = arrCurrent[h][w];
      char next = LiveOrDie(neighbors, current);
      arrNextGen[h][w] = next;
    }
  }
}

/*
 * CopyMap
 * This method copies the contents of arrNextGen into arrCurrent using a for loop.
 */
void ProcessMap::CopyMap(char** arrCurrent, char** arrNextGen, int height, int width)
{
  for(int h = 1; h < height-1; h++)
  {
    for(int w = 1; w < width-1; w++)
    {
      arrCurrent[h][w] = arrNextGen[h][w];
    }
  }
}
