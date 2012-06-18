#include <exception>
#include <new>
#include <cstdlib>
#include <iostream>

#include "stacktrace.hpp"

void* operator new (size_t size) {
  void* p = malloc(size);

  if (p == 0) {
    throw std::bad_alloc();
  }

  std::cout << "allocated " << size << std::endl;
  printTrace(std::cout);

  return p;
}

void operator delete (void* p) {
  free(p);
}
