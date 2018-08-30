#include <iostream>
using namespace std;

// compile in terminal with with
// g++ -o NewFile filename.cpp
// ./NewFile

//int A(int param1) {
//  int param1 = 3;
//}

// EXAMPLE 1
// int main() {
//  int val = 4;
//  if (true) {
//    int val = 3;
//    val = 1;
//  }
//  cout << "val: " << val << endl;
// }

// EXAMPLE 2
// int main() {
//   int val = 4;
//   int* x = &val;
//   cout << "val: " << val << " and is at address " << x << endl;
// }

// EXAMPLE 3
// void changeX(int* pX) {
//   *pX = 5;
// }
//
// int main() {
//   int x = 1;
//   changeX(&x);
//   cout << x << endl;
// }

// EXAMPLE 4
void changeX(int& pX) {
  pX = 5;
}

int main() {
  int x = 1;
  changeX(x);
  cout << x << endl;
}
