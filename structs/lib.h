#ifndef lib_h
#define lib_h

#include <string.h>

char *strdup(const char *);

char *string_dup(char *src) {
  // NOTE: Using `strdup` here causes a compiler warning due to the usage of -std=c99 in mainbuild.mk.
  // This also causes it to run with an incorrect function declaration, one which expects it to return an int. The above function declaration takes care of that.
  // More info. here: https://stackoverflow.com/questions/26284110/strdup-confused-about-warnings-implicit-declaration-makes-pointer-with
  return strdup(src);
}

#endif
