#include <exception>
#include <new>
#include <cstdlib>
#include <cstdio>

#include "stacktrace.hpp"

void* operator new (size_t size) {
  void* p = malloc(size);

  if (p == 0) {
    throw std::bad_alloc();
  }

  printf("allocated %zu\n", size);
  printTrace(stdout);

  return p;
}

void operator delete (void* p) {
  free(p);
}
