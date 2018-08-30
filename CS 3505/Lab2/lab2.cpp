#include <iostream>


class Cat {
  int lives; // Cats have 9 lives
public:
  // Construct a Cat with a number of lives
  Cat(int startLives) : lives{startLives} {
  // nothing else to do
  }
  void reportLives() {
    std::cout << "This cat has " << lives << " lives.\n";
  }
  void loseLife() {
    lives = lives -1;
  }
};

int main() {
  Cat mittens(9);
  mittens.reportLives();
  mittens.loseLife();
  mittens.reportLives();
  }
