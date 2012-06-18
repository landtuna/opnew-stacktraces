#include <iostream>
#include <exception>

using namespace std;

#include "Foo.hpp"

int main() {
  Foo* f = new Foo;
  f->a = 1;
  f->b = 2;

  cout << add(1, 1) << endl;
  cout << f->add() << endl;

  return 0;
}
