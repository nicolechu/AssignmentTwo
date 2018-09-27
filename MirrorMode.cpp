/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * The MirrorMode class contains a method to initialize the boundary of an array that will be evaluated in Mirror mode.
 */

#include <iostream>
#include "MirrorMode.h"

using namespace std;

MirrorMode::MirrorMode()
{
}

MirrorMode::~MirrorMode()
{
}

/*
 * Boundary
 * This method sets the boundaries of the 2d array arr. If the user chooses to evaluate their map in Mirror mode,
   this function is called. A for loop iterates through the matrix and evaluates only the outer border of the map.
   The corners are evaluated according to the instructions of the game and the remaining borders are assigned
   accordingly as well.
 * The boundaries mirror the contents of the cell map and the corners are set according to the cells diagonal to them.
 */
char** MirrorMode::Boundary(char** arr, int height, int width)
{
  for(int h = 0; h < height; h++)
  {
    for(int w = 0; w < width; w++)
    {
      //corners
      if(h == 0 && w == 0)
      {
        if(arr[h+1][w+1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == 0 && w == width-1)
      {
        if(arr[h+1][w-1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == height-1 && w == 0)
      {
        if(arr[h-1][w+1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == height-1 && w == width-1)
      {
        if(arr[h-1][w-1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      //other borders
      else if(h == 0)
      {
        if(arr[h+1][w] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(w == 0)
      {
        if(arr[h][w+1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == height-1)
      {
        if(arr[h-1][w] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(w == width-1)
      {
        if(arr[h][w-1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
    }
  }

  return arr;
}
