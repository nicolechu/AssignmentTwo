/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * This is the header file for Map.cpp
 */

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

class Map
{
public:
  Map();
  ~Map();

  int GetHeight(string filePath);
  int GetWidth(string filePath);
  char** CreateMap(int height, int width);
  void InitializeRandomMap(char** arrCurrent, int height, int width, float density);
  void InitializeMapFile(char** arrCurrent, int width, string filePath);
  char GetRandomCell(float density);
  bool EqualArrays(char** arrCurrent, char** arrNextGen, int height, int width);

  void myPause();
private:
  
};

#endif
