#include <cxxabi.h>
#include <libunwind.h>
#include <ostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "stacktrace.hpp"

void printTrace(ostream& out) {
  unw_cursor_t cursor;
  unw_context_t context;
  
  unw_getcontext(&context);
  unw_init_local(&cursor, &context);
  
  while (unw_step(&cursor) > 0) {
    unw_word_t offset, pc;
    char fname[200];
    size_t demangledSize = 200;
    char* demangled = (char*) malloc(demangledSize);
    
    unw_get_reg(&cursor, UNW_REG_IP, &pc);
    fname[0] = '\0';
    unw_get_proc_name(&cursor, fname, sizeof(fname), &offset);

    int status;

    char *ret = abi::__cxa_demangle(fname, demangled, &demangledSize, &status);
    if (ret) {
      // return value may be a realloc() of the input
      demangled = ret;
    }
    else {
      // demangling failed, just pretend it's a C demangled with no args
      strncpy(demangled, fname, demangledSize);
      strncat(demangled, "()", demangledSize);
      demangled[demangledSize-1] = '\0';
    }
    
    out << hex << demangled << "+0x" << offset << " [" << pc << "]" << dec << '\n';
    free(demangled);
  }
  out << endl;
}
