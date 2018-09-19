// #include <iostream>
//
// #define print(x) std::cout << x << std::endl
//
// int main (){
//   int vals[3] = {1,2,3};
//   print(vals[4]);
// }

#include <iostream>

int main() {
  int* val = new int(4);
  int* same_mem = val;

  std::cout << *val << *same_mem << std::endl;
  delete val;
  delete val;
}
