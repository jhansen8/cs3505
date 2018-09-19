#include <iostream>
#include "point.h"
using namespace std;

  Point::Point() {;}
  Point::Point(double initx, double inity) : x(initx), y(inity) {
    //x = initx;
    //y = inity;
  }
  int Point::get_x() {
    return x;
  }
  int Point::get_y() {
    return y;
  }
  void Point::set_x(double newVal) {
    if (x > 0.0)
    x = newVal;
  }

  Point operator*(double scaleFactor) {
    Point res(scaleFactor * x, scaleFactor * y);
    // Point res;
    // res.x = x * scaleFactor;
    // res.y = y * scaleFactor;

    return res;
  }

  friend ostream& operator<<(ostream& output, Point pt);
};

Point operator*(double lhs, Point rhs) {
  Point res(lhs*rhs.get_x(), lhs*rhs.get_y());
  return res;
}

// example of overloading
ostream& operator<<(ostream& output, Point pt) {
  output << "(" << pt.x << "," << pt.y << ")";
  return output;
}

int main() {
  Point p;
  Point p2(10.0, 5.0);
  Point* pPtr = &p2;

  p2.set_x(2.0);

  Point newPt = 2.0 * p2;
  cout << newPt << endl;
  // Point newPt = p2 * 2.0;
  // newPt = pt.operator*(2.0);
}
