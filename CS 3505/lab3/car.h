#ifndef Car_H
#define Car_H

class Car {
  double speed;

public:
  Car(double speed);
  void drive();
  void slow();
  void speedUp();
};

#endif
