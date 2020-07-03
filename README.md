# Python-like `print` in ANSI C!

# How to use

```c
#include "print.h"


int main() {
  char *str = "aaa";
  int i = 9;
  float f = .1;

  print(_"Hello", _"world!");
  print(str, i, SEP "\t", END "\n");
  print(f, 1);
}
```

# Limitations
  - String literals must be precede by an underscore.

# License
Public domain, or WTFPL if you like.
