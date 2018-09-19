/**
  Jared Hansen
  CS3505
  Assignment 2: Classes and Facades
  This class manages creation, set up, print to, and saving of a PDF
  file. It allows the caller to customize the document, in specific the
  class is good for setting up specific location and orientation when printing
  to a page.
*/

#include "HaruPDF.h"
#include "hpdf.h"
#include <string.h>
#include <math.h>

using namespace std;

  /**
    Constructor of a PDF object, it sets up a default name for
    the file and does internal set up of PDF.
  */
  HaruPDF::HaruPDF(char* fileName) {
    strcpy (fname, fileName);
    strcat (fname, ".pdf");

    pdf = HPDF_New (NULL, NULL);
  }

  /**
    This adds a standard page and sets sizes to the document, A5 portrait
  */
  void HaruPDF::addPage() {
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
  }

  /**
    This adds a page and sets sizes and orientation according to input.
    It can be A5, A4 Letter, Portrait, or Landscape.
  */
  void HaruPDF::addPage(char* pageSize = NULL, char* orientation = NULL) {
    page = HPDF_AddPage(pdf);

    // Check which options were chosen, upon errors, use default
    if(strcmp(pageSize, "A5") == 0) {
      if(strcmp(orientation, "Landscape") == 0)
        HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_LANDSCAPE);
      else
        HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    }
    else if(strcmp(pageSize, "A4") == 0) {
      if(strcmp(orientation, "Landscape") == 0)
        HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_LANDSCAPE);
      else
        HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
    }
    else if(strcmp(pageSize, "Letter") == 0) {
      if(strcmp(orientation, "Landscape") == 0)
        HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_LETTER, HPDF_PAGE_LANDSCAPE);
      else
        HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_LETTER, HPDF_PAGE_PORTRAIT);
    }
    else {
      HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    }
  }

  /**
    Sets default fault to Helvetica, black, and size to 20
  */
  void HaruPDF::setFont() {
    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
  }

  // void HaruPDF::setFont(char* font, double size) {
  //   font = HPDF_GetFont (pdf, font, NULL);
  //   HPDF_Page_SetFontAndSize (page, font, size);
  // }

  /**
    Writes a character to the PDF document accoring to the angle given
    and the coordinates given. Caller is responsible to make sure it lands
    on the page.
  */
  void HaruPDF::writeChar(char c, float x, float y, float angle) {
      char buf[2] = {c,0};

      // The cos/sin stuff is actually defining a 2D rotation matrix.
      HPDF_Page_SetTextMatrix(page,
                              cos(angle), sin(angle), -sin(angle), cos(angle),
                              x, y);

      // Place the char with null (0) onto PDF
      HPDF_Page_ShowText (page, buf);
  }

  /**
    Overload operator for the << operation. It will send the angle
    and radius to output in an organized way.
  */
  void HaruPDF::beginText() {
    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 30);
  }

  /**
    Default saves the document with the name given at the constructor
  */
  void HaruPDF::save() {
    HPDF_Page_EndText (page);
    HPDF_SaveToFile(pdf, fname);
    HPDF_Free (pdf);
  }

  /**
    Allows the caller to specify a new name to the document and saves it.
  */
  void HaruPDF::saveAs(char* fileName) {
    HPDF_Page_EndText (page);
    strcat (fileName, ".pdf");
    HPDF_SaveToFile(pdf, fileName);
    HPDF_Free (pdf);
  }
