/**
  Jared Hansen
  Assignment 1: C++ Starter
  This program displays ASCII chart of the Lotka-Volterra computation
  for rabbit and fox populations based on initial population. The chart
  will be displayed until 500 iterations or one population dies off.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

/**
  Function signatures for each helper method in the program.
*/
void updatePopulations(double g, double p, double c, double m, double K,
                        double& numRabbits, double& numFoxes);
void plotCharacterAtPosition(int position, char character);
void plotPopulations(double numRabbits, double numFoxes, double scaleFactor);
void incrementCounter(int* counter);

/**
  Perform the calculations for Lotka-Volterra based on the parameters
  input and the current population.
  @param g rabbitGrowth
  @param p predationRate
  @param c foxPreyConversion
  @param m focMortalityRate
  @param K carryCapacity
  @param numRabbits
  @param numFoxes
*/
void updatePopulations(double g, double p, double c, double m, double K,
                        double& numRabbits, double& numFoxes) {
  double R = numRabbits;
  double F = numFoxes;
  numRabbits = R+(g*R*(1-R/K)-(p*R*F));
  numFoxes = F + (c*p*R*F - m*F);
}

/**
  Plots the specific character at desired position from the left of The
  display area.
  @param position
  @param character
*/
void plotCharacterAtPosition(int position, char character) {
  if (position >= 1)
    cout << string(position, ' ') << character;
  else
    cout << character;
}

/**
  Plots the populations of rabbits and foxes in an ASCII chart using a
  scale factor for better visualization
  @param numRabbits
  @param numFoxes
  @param scaleFactor
*/
void plotPopulations(double numRabbits, double numFoxes, double scaleFactor) {
  int rPosition = floor(numRabbits*scaleFactor) + 1;
  int foxPosition = floor(numFoxes*scaleFactor) + 1;

  // Check for which case to plot the order  and plot according to scale
  if (rPosition > foxPosition) {
    rPosition = rPosition - foxPosition;
    plotCharacterAtPosition(foxPosition, 'F');
    plotCharacterAtPosition(rPosition, 'r');
    cout << "\n";
  } else if (foxPosition == rPosition) {
    plotCharacterAtPosition(rPosition, '*');
    cout << "\n";
  } else {
    foxPosition = foxPosition - rPosition;
    plotCharacterAtPosition(rPosition, 'r');
    plotCharacterAtPosition(foxPosition, 'F');
    cout << "\n";
  }
}

/**
  This helper method uses pointers to increment any counter by one when called.
  @param counter
*/
void incrementCounter(int* counter) {
  *counter = *counter + 1;
}

/**
  Main method enters program and runs through the iterations, calling the helper
  methods as needed. Request input from the user as well as displays to user.
*/
int main(int argc, char const *argv[]) {
  // Set up variables to be used
  string instr;
  double rPop = 0;
  double foxPop = 0;
  int iter = 0;
  stringstream ss;

  // Request input from user and parse to double
  cout << "Enter initial rabbit population: ";
  getline(cin, instr);
  ss.str(instr);
  ss >> rPop;
  // Upon failure to convert, warn and exit
  if (ss.fail()) {
    cout << "Error converting to double.\n";
    exit(EXIT_FAILURE);
  }
  ss.clear();

  // Request inpur from user and parse to double
  cout << "Enter initial fox population: ";
  getline(cin,instr);
  ss.str(instr);
  ss >> foxPop;
  // Upon failure to convert, warn and exit
  if (ss.fail()) {
    cout << "Error converting to double.\n";
    exit(EXIT_FAILURE);
  }

  // Plot initial population values
  plotPopulations(rPop, foxPop, 0.1);

  // Iterate through calculations and plotting until 500 or population dies off.
  while (iter < 500 && rPop >= 1 && foxPop >= 1) {
    updatePopulations(0.2, 0.002, 0.6, 0.2, 1000, rPop, foxPop);
    plotPopulations(rPop, foxPop, 0.1);
    incrementCounter(&iter);
  }

  return 0;
}
