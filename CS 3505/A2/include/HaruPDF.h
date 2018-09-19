/**
  Jared Hansen
  CS3505
  Assignment 2: Classes and Facades
  This class manages creation, set up, print to, and saving of a PDF
  file. It allows the caller to customize the document, in specific the
  class is good for setting up specific location and orientation when printing
  to a page.
*/

#ifndef HaruPDF_H
#define HaruPDF_H
#include "hpdf.h"


class HaruPDF {
private:
  HPDF_Doc  pdf;
  HPDF_Page page;
  char fname[256];
  HPDF_Font font;
public:

  /**
    Constructor of a PDF object, it sets up a default name for
    the file and does internal set up of PDF.
  */
  HaruPDF(char* fileName);

  /**
    This adds a standard page and sets sizes to the document, A5 portrait
  */
  void addPage();

  /**
    This adds a page and sets sizes and orientation according to input.
    It can be A5, A4 Letter, Portrait, or Landscape.
  */
  void addPage(char* pageSize, char* orientation);

  /**
    Sets default fault to Helvetica, black, and size to 20
  */
  void setFont();
  // void setFont(char* font, double size); // taken out for now

  /**
    Writes a character to the PDF document accoring to the angle given
    and the coordinates given. Caller is responsible to make sure it lands
    on the page.
  */
  void writeChar(char c, float x, float y, float angle);

  /**
    Overload operator for the << operation. It will send the angle
    and radius to output in an organized way.
  */
  void beginText();

  /**
    Default saves the document with the name given at the constructor
  */
  void save();

  /**
    Allows the caller to specify a new name to the document and saves it.
  */
  void saveAs(char* fileName);
};

#endif
