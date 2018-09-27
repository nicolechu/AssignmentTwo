/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * This is the header file for ProcessMap.cpp
 */

#ifndef PROCESSMAP_H
#define PROCESSMAP_H

#include <iostream>
#include <fstream>

using namespace std;

class ProcessMap
{
public:
  ProcessMap();
  ~ProcessMap();

  char LiveOrDie(char arrN[], char cell);
  void PrintMap(char** arr, int height, int width);
  void GenerateNextGen(char** arrCurrent, char** arrNextGen, int height, int width);
  void CopyMap(char** arrCurrent, char** arrNextGen, int height, int width);

private:

};

#endif
