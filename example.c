#include "print.h"


int int_f() {
  return 2;
}


char *string_f() {
  return "test";
}


int main() {
  char *str = "aaaaaaaa";
  int i = 9;
  float f = .1;

  print(_"Hello", _"world!", SEP "\t", END "\n\n");
  print(_"Basic types:", str, i, f, 1);

  int ai[] = {1, 2, 3, 4, 5};
  float af[] = {1, 2, 3, 4, 5};
  print(_"Arrays:", ai, af);
  print(_"Arrays with length:", _(str, 2), _(ai, 2), _(af, 2));
  print(_"Function returns:", int_f(), string_f());
}
