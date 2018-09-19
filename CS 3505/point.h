class Point {
private:
  double x,y;
public:
  Point();
  Point(double initx, double inity);
  int get_x();
  int get_y();
  void set_x(double newVal);
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
