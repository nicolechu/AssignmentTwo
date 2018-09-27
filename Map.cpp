/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * The Map class contains methods that build and initialize cell maps, obtain map information from user input files,
   and pause output.
 */

#include <iostream>
#include "Map.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

Map::Map()
{
}

Map::~Map()
{
}

/*
 * GetHeight
 *
 * This function returns the height value from the user's map file. An ifstream variable is used to open
   the file. A while loop is then used to loop through the file to obtain the first line of the file and
   assigns that line to a string variable. The string is then converted to an int using a stringstream object.
   https://www.geeksforgeeks.org/converting-strings-numbers-cc/
 */
int Map::GetHeight(string filePath)
{
  int height;
  string h;
  ifstream inputFile;
  inputFile.open(filePath);

  string line;
  int count = 0;
  while(getline(inputFile,line) && count < 2)
  {
    count++;
    if(count == 1)
    {
      h = line;
      stringstream h1(h);
      h1 >> height;
    }
  }

  return height;
}

/*
 * GetWidth
 *
 * This function returns the width value from the user's map file. An ifstream variable is used to open
   the file. A while loop is then used to loop through the file to obtain the second line of the file and
   assigns that line to a string variable. The string is then converted to an int using a stringstream object.
   https://www.geeksforgeeks.org/converting-strings-numbers-cc/
 */
int Map::GetWidth(string filePath)
{
  int width;
  string w;
  ifstream inputFile;
  inputFile.open(filePath);

  string line;
  int count = 0;

  while(getline(inputFile,line) && count < 2)
  {
    count++;
    if(count == 2)
    {
      w = line;
      stringstream w1(w);
      w1 >> width;
    }
  }

  return width;
}

/*
 * CreateMap
 * This method builds and returns an empty cell map (2d array) as a pointer with a given height and width.
 * https://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function
 */
char** Map::CreateMap(int height, int width)
{
  char** arr;
  arr = new char*[height];

  for (int h = 0; h < height; h++)
  {
    arr[h] = new char[width];

    for (int w = 0; w < width; w++)
    {
      arr[h][w] = '-';
    }
  }

  return arr;
}

/*
 * InitializeRandomMap
 * This function calls the GetRandomCell method in order to randomly initialize an empty 2d array.
 * The array's population density (provided by the user) is passed as an argument to be used to initialze
   the array in the GetRandomCell function.
 */
void Map::InitializeRandomMap(char** arrCurrent, int height, int width, float density)
{
  for(int h = 1; h < height-1; h++)
  {
    for(int w = 1; w < width-1; w++)
    {
        arrCurrent[h][w] = GetRandomCell(density);
    }
  }
}

/*
 * InitializeMapFile
 * This method initializes an empty 2d array using a map file provided by the user. It reads through the user's
   map file and reads through its lines (past the first 2 lines which contain height and width values) to obtain
   the map's configuration. If the line contains an 'X' at a given index, an 'X' is assigned to the corresponding
   location in arrCurrent.
 */
void Map::InitializeMapFile(char** arrCurrent, int width, string filePath)
{
  ifstream inputFile;
  string line;
  int count = 0;
  inputFile.open(filePath);
  while(getline(inputFile,line))
  {
    count++;
    if(count > 2)
    {
      for(int c = 0; c < width-1; c++)
      {
        if(line[c] == 'X' || line[c] == 'x')
        {
          arrCurrent[count-2][c+1] = 'X';
        }
      }
    }
  }
}

/*
 * GetRandomCell
 * This function uses a density argument to return a '-' or 'X' character to a randomly generated array.
   It generates a random number between 0 and 1 (using the rand function, seeded by the time function in main)
   to weight the probability of the type of cell character that is returned.
 */
char Map::GetRandomCell(float density)
{
  float randNum = (rand()%100 + 1)/100.0;
  char cell = '0';

  if(randNum > 0 && randNum <= density)
    cell = 'X';
  if(randNum > density && randNum <= 1)
    cell = '-';

  return cell;
}

/*
 * EqualArrays
 * This method tests if two 2d array arguments are equivalent. It returns a boolean value and is used to determine
   if the cell maps are stable.
 */
bool Map::EqualArrays(char** arrCurrent, char** arrNextGen, int height, int width)
{
  bool equal = true;
  for(int h = 1; h < height-1; h++)
  {
    for(int w = 1; w < width-1; w++)
    {
      if(arrCurrent[h][w] != arrNextGen[h][w])
      {
        equal = false;
      }
    }
  }

  return equal;
}

/*
 * myPause
 * This function pauses program activity for 5 seconds. It is used if the user wants a brief pause in between
   generations as they are being output.
 * https://ubuntuforums.org/showthread.php?t=1357606
 */
void Map::myPause()
{
  clock_t endwait;
  endwait = clock () + 5 * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
