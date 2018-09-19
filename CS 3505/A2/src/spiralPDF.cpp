/**
  Jared Hansen
  CS3505
  Assignment 2: Classes and Facades
  This program takes in input from the user executing the program around
  displays the input in a spiral shape within a PDF file. Its current
  implementation displays the angle and radius at each iteration. Files will
  be saved to current directory with name given as program name.
*/

#include <string.h>
#include <iostream>
#include "HaruPDF.h"
#include "Spiral.h"

using namespace std;

/**
  Main will initaite the program and run when executed
*/
int main (int argc, char **argv)
{
  char fname[256];
  char text[256];
  unsigned int i;
  strcpy (fname, argv[0]);
  strcpy (text, argv[1]);

  // Make a Spiral object to use as guide in PDF
  Spiral sp(210, 300, 40, 240);

  // Create a PDF and do initial Setup
  HaruPDF myPdf(fname);
  myPdf.addPage();

  // Set up page in different warranty
  // myPdf.addPage("Letter", "Landscape");

  // Set up for writing to file
  myPdf.setFont();
  myPdf.beginText();


  for (i = 0; i < strlen(text); i++) {
    // Demonstrate the functionality of the overload operator.
    cout << sp << endl;

    // Write each character from input argument into the PDF
    myPdf.writeChar(text[i],sp.getTextX(),sp.getTextY(),sp.getTextAngle());

    // Demonstrate the overload operator and increase spiral
    sp++;
  }

  // Save PDF
  myPdf.save();

  // Save PDF with different file named
  //myPdf.saveAs("newName");

  return 0;
}
