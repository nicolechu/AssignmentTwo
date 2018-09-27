/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #2
 */

/*
 * This is the main file. It prompts the user for their program preferences, declares two 2d arrays to represent the
   current and next generations of cells, and outputs the concurrent generations based on the user's preferences.
 * The main function makes calls to supplemental classes in order to initiate, process and output the 2d arrays properly.
 */

#include <iostream>
#include <fstream>
#include <ctime>

#include "Map.cpp"
#include "MirrorMode.cpp"
#include "DoughnutMode.cpp"
#include "ProcessMap.cpp"

using namespace std;

int main(int argc, char **argv)
{
  string map;
  string filePath;
  string oFileName;
  int height, width;
  float density;

  //objects to process user's input & output files
  ifstream inputFile;
  ofstream outputFile;

  //pointers used to create 2d arrays
  char** arrCurrent;
  char** arrNextGen;

  Map obj;
  ProcessMap process;
  MirrorMode mirror;
  DoughnutMode doughnut;

  /*
   * These prompts ask the user how they would like the program to run.
   * The first question asks which boundary mode they would like the data to be evaluated in.
   * The second asks what kind of break they want in between output data or if they'd like to output to a file.
   * The last question asks if the user would like to use their own map file.
   */
  string mode;
  cout << "Which boundary mode would you like? (classic/doughnut/mirror): ";
  cin >> mode;

  string output;
  cout << "Would you like to pause between generations, press enter to display the next generation, or output to a file? (pause, enter, file): ";
  cin >> output;

  cout << "Would you like to use your own map file? (Y/N): ";
  cin >> map;

  if(map == "Y" || map == "y")
  {
    /*
     * If the user chooses to use their own map file, they are prompted to enter the file path.
       The file path is then saved to a string which will be passed to the Map class to obtain
       height and width values.
     */
    cout << "Please enter your file path: ";
    cin >> filePath;

    /*
     * This block of code creates a Map object to obtain the height and width from the user's map file using
       the GetHeight and GetWidth functions.
     * I added 2 to the height and width variables in order to create a matrix that contains an extra border
       around the cell map for ease of evaluating the current generation and generating the next generation.
     */
     height = obj.GetHeight(filePath);
     width = obj.GetWidth(filePath);

     height += 2;
     width += 2;

    /*
     * The two pointers, representing the current generation and the next generation, are initialized here by
       calling the CreateMap function from the Map class which creates and initializes 2 empty cell maps. The
       InitializeMapFile function is then called to initialize arrCurrent to the map configuration provided in
       the user's map file.
     */
     arrCurrent = obj.CreateMap(height, width);
     arrNextGen = obj.CreateMap(height, width);

     obj.InitializeMapFile(arrCurrent, width, filePath);

  }
  else if(map == "n" || map == "N")
  {
    /*
     * If the user wants a randomly generated cell map, they are prompted for their desired height, width, and
       population density. Each of the values they enter are then assigned to corresponding variables.
     */
    cout << "Please enter the height of your grid: ";
    cin >> height;
    height += 2;
    cout << "Please enter the width of your grid: ";
    cin >> width;
    width += 2;
    cout << "Enter a decimal (0 < x <= 1) for the population density: ";
    cin >> density;

    /*
     * The user's random maps are then created using the same CreateMap function used above. The two 2d arrays
       are built and initialized as empty.
     */
    arrCurrent = obj.CreateMap(height, width);
    arrNextGen = obj.CreateMap(height, width);

    /*
     * To initiate the user's random map, I used the srand function to seed the random number generator in my
       InitializeRandomMap function from the Map class. This function will randomly build a cell map according
       to the population density provided by the user and assign this map to arrCurrent.
     */
    srand(time(0));
    obj.InitializeRandomMap(arrCurrent, height, width, density);
  }

  /*
   * If the user chooses to output their data to a file, they are prompted here to provide the name of their
     output file. The file is opened using the ofstream object declared above.
   */
  if(output == "file" || output == "FILE")
  {
    cout << "Enter the name of the output file: ";
    cin >> oFileName;
    outputFile.open(oFileName);
  }

  /*
   * cin.ignore() is called here so that the user's key press ENTER from one of the prompts above does not
     affect the code I have below if the user chooses to press ENTER before generating the next generation.
     I found that without calling this function, an ENTER press from any of the previous prompts was read as
     a single ENTER press intended to display the next generation.
   */
  cin.ignore();

  /*
   * This while loop outputs and generates the new generations and it also implements the proper type of break the
     user specified in the above prompts.
   * Two variables are declared prior to the while loop declaration to be used within the loop. genCount is an integer
     used to keep track of the generation number to be output before each grid. arrEqual is a boolean used to test if
     arrCurrent and arrNextGen are equivalent. Once the two matrices are equivalent, arrEqual is set to false and the
     while loop ends.
   */
  int genCount = 0;
  bool arrEqual = true;
  while(arrEqual)
  {
    /*
     * If the user chooses to output to a file, this if statement contains a for loop that outputs each generation
       to the file whose name the user provided above and has already been opened using the ofstream object outputFile.
     */
    if(output == "file" || output == "FILE")
    {
      outputFile << "Generation " << genCount << endl;
      for(int h = 1; h < height-1; h++)
      {
        for(int w = 1; w < width-1; w++)
        {
          outputFile << arrCurrent[h][w];
        }
        outputFile << "\n";
      }
    }
    else
    {
      /*
       * If the user does not choose to output to a file, the output is printed to the console.
       * A ProcessMap object (process) is used to call the function PrintMap which will print the contents of arrCurrent.
       */
      cout << "Generation " << genCount << endl;
      process.PrintMap(arrCurrent, height, width);

      /*
       * If the user specifies that they would like a brief pause in between generations, the myPause function is called
         from the Map class. This will insert a 5 second pause in between output.
       */
      if(output == "pause" || output == "PAUSE")
      {
        obj.myPause();
      }
      /*
       * If the user would like to press the ENTER key to display the next generation, they are prompted to do so in
         between generations. The cin.get() function is used to detect when the user presses ENTER. Once the key press
         is detected, the program continues to create and display the next generation.
       */
      else if(output == "enter" || output == "ENTER")
      {
        cout << "\nPress ENTER for next generation";
        cin.get();
      }
      /*
       * If the user's input for the output string does not match one of the options above, the program displays an
         error message and terminates.
       */
      else
      {
        cout << "ERROR: You did not enter a valid break/output option." << endl;
        exit;
      }
    }

    /*
     * Boundary methods are called from the Mirror and Doughnut classes if the user chooses to run in either of those modes.
       These functions set the respective boundary of arrCurrent. If the user chooses Classic mode, no changes are made to
       arrCurrent as Classic mode is the default boundary mode.
     * If the user's input for the mode string does not match one of the provided options, the program displays an error
       message and terminates.
     */
    if(mode == "mirror" || mode == "MIRROR")
    {
      arrCurrent = mirror.Boundary(arrCurrent, height, width);
    }
    else if(mode == "doughnut" || mode == "DOUGHNUT")
    {
      arrCurrent = doughnut.Boundary(arrCurrent, height, width);
    }
    else if(!(mode == "classic" || mode == "CLASSIC"))
    {
      cout << "ERROR: You did not enter a valid boundary mode." << endl;
      exit;
    }

    /*
     * The GenerateNextGen function is called using the ProcessMap object. This function will initialize arrNextGen by
       evaluating each cell of arrCurrent and determining which cells of arrNextGen will live and which will die.
     */
    process.GenerateNextGen(arrCurrent, arrNextGen, height, width);

    /*
     * This if statement tests if arrCurrent and arrNextGen are equivalent. If they are not equivalent, the CopyMap function
       is called from the ProcessMap class. This function copies the contents of arrNextGen to arrCurrent to be output at the
       top of the loop and re-evaluated. genCount is also incremented to be displayed at the top of the loop.
     * If the two arrays are equivalent, suggesting that the generations have stabilized or become empty, a message is displayed
       informing the user to press ENTER to exit. Once they press ENTER, arrEqual is set to false to break out of the loop. If
       the data is being output to a file, the file is closed after the key press.
     */
    if(!obj.EqualArrays(arrCurrent, arrNextGen, height, width))
    {
      process.CopyMap(arrCurrent, arrNextGen, height, width);
      genCount++;
    }
    else
    {
      cout << "\nGenerations have stabilized. Press ENTER to exit.";
      cin.get();

      arrEqual = false;
      if(output == "file" || output == "FILE")
      {
        outputFile.close();
      }
    }
  }
  return 0;
}
