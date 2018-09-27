/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * This is the header file for DoughnutMode.cpp
 */

#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include <iostream>

using namespace std;

class DoughnutMode
{
public:
  DoughnutMode();
  ~DoughnutMode();

  //boundary editor w/ args (char** arrCurrent, arrNextGen)
  char** Boundary(char** arr, int height, int width);
private:

};

#endif
