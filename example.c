#include "print.h"


int int_f() {
  return 2;
}


char *string_f() {
  return "test";
}


int main() {
  char *str = "aaa";
  int i = 9;
  float f = .1;

  print(_"Hello", _"world!", SEP "\t", END "\n\n");
  print(_"Basic types:", str, i, f, 1);
  print(_"Function returns:", int_f(), string_f());
}
