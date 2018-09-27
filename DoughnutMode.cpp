/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * The DoughnutMode class contains a method that sets the boundaries of the 2d array according to the Doughnut mode rules.
 */

#include <iostream>
#include "DoughnutMode.h"

using namespace std;

DoughnutMode::DoughnutMode()
{
}

DoughnutMode::~DoughnutMode()
{
}

/*
 * Boundary
 * This method sets the boundaries of the 2d array arr. If the user chooses to evaluate their map in Doughnut mode,
   this function is called. A for loop iterates through the matrix and evaluates only the outer border of the map.
   The corners are evaluated according to the instructions of the game and the remaining borders are assigned
   accordingly as well.
 * The boundaries are set as if the map is wrapped around itself vertically and horizontally. The corners are set
   by evaluating the cells diagonally across the map from them.
 */
char** DoughnutMode::Boundary(char** arr, int height, int width)
{
  for(int h = 0; h < height; h++)
  {
    for(int w = 0; w < width; w++)
    {
      //corners
      if(h == 0 && w == 0)
      {
        if(arr[height-2][width-2] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == 0 && w == width-1)
      {
        if(arr[height-2][1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == height-1 && w == 0)
      {
        if(arr[1][width-2] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == height-1 && w == width-1)
      {
        if(arr[1][1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      //other borders
      else if(h == 0)
      {
        if(arr[height-2][w] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(w == 0)
      {
        if(arr[h][width-2] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(h == height-1)
      {
        if(arr[1][w] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
      else if(w == width-1)
      {
        if(arr[h][1] == 'X')
          arr[h][w] = 'X';
        else
          arr[h][w] = '-';
      }
    }
  }

  return arr;
}
