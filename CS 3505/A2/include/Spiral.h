/**
  Jared Hansen
  CS3505
  Assignment 2: Classes and Facades
  This class sets up and maintaints a Spiral object. A spiral will take in
  a center x and y, initial desired positive radius, and an angle at which to
  start the spiral center from 12 o'clock going clockwise.
*/

#ifndef SPIRAL_H
#define SPIRAL_H

#include <iostream>

class Spiral {
private:
  double centerX,centerY;
  float x,y,r,angle,textAngle;
public:

  /**
    Constructor for Spiral object, takes care of initial internal setup
    so that spiral can be used immediately after.
  */
  Spiral(double centerX, double centerY, float radius, float angle);

  /**
    Public getter for the Text X value.
  */
  float getTextX();

  /**
    Public getter for the Text Y value.
  */
  float getTextY();

  /**
    Public getter for the Text Angle value.
  */
  float getTextAngle();

  // Operators

  /**
    Overload operator for the prefix ++ operation. This will step then
    the spiral to the next position and set of values needed.
  */
  Spiral& operator++();

  /**
    Overload operator for the postfix ++ operation. This will step then
    the spiral to the next position and set of values needed.
  */
  Spiral operator++(int);

  /**
    Overload operator for the << operation. It will send the angle
    and radius to output in an organized way.
  */
  friend std::ostream& operator<<(std::ostream& output, Spiral sp);
};

#endif
