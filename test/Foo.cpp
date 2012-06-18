#include "Foo.hpp"

int add(int a, int b) {
  int* c = new int;
  *c = a + b;
  return *c;
}

int Foo::add() {
  int* c = new int[4];
  c[0] = a + b;
  return c[0];
}
