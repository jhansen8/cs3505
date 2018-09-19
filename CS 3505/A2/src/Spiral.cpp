/**
  Jared Hansen
  CS3505
  Assignment 2: Classes and Facades
  This class sets up and maintaints a Spiral object. A spiral will take in
  a center x and y, initial desired positive radius, and an angle at which to
  start the spiral center from 12 o'clock going clockwise.
*/

#include "Spiral.h"
#include <cmath>

using namespace std;

  /**
    Constructor for Spiral object, takes care of initial internal setup
    so that spiral can be used immediately after.
  */
  Spiral::Spiral(double cX, double cY, float radius, float a) {
    centerX = cX;
    centerY = cY;

    // Enforce positive radius and at least 30
    if (radius >= 30)
      r = radius;
    else
      r = 30;

    // Set up angle according to clock descriptions
    angle = 90.0 - a;
    textAngle = (angle - 90) / 180 * M_PI;

    // Initial x y coordinates for text
    x = r * cos((angle / 180 * M_PI)) + cX;
    y = r * sin((angle / 180 * M_PI)) + cY;
  }

  /**
    Public getter for the Text X value.
  */
  float Spiral::getTextX() {
    return x;
  }

  /**
    Public getter for the Text Y value.
  */
  float Spiral::getTextY() {
    return y;
  }

  /**
    Public getter for the Text Angle value.
  */
  float Spiral::getTextAngle() {
    return textAngle;
  }

  /**
    Overload operator for the prefix ++ operation. This will step then
    the spiral to the next position and set of values needed.
  */
  Spiral& Spiral::operator++() {
    r += 1.6; // Increade radius by a constant

    // Make the change in angle dependent upon the radius, set to not allows
    // overlapping
    angle -= acos((2 * r * r - 289) / (2 * r * r)) * 180 / M_PI;

    // Calculate remaining values needed.
    float rad2 = angle / 180 * M_PI;
    textAngle = (angle - 90) / 180 * M_PI;
    x = centerX + cos(rad2) * r;
    y = centerY + sin(rad2) * r;
	  return *this;
  }

  /**
    Overload operator for the postfix ++ operation. This will step then
    the spiral to the next position and set of values needed.
  */
  Spiral Spiral::operator++(int) {
    Spiral toReturn = *this; // make a copy to return
    ++(*this); // perform the needed operations
    return toReturn;
  }

  /**
    Overload operator for the << operation. It will send the angle
    and radius to output in an organized way.
  */
  ostream& operator<<(ostream& output, Spiral sp) {
    output << "Angle: " << sp.textAngle * 180 / M_PI << "\t Radius: " << sp.r;
    return output;
}
