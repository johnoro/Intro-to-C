#ifndef lib_h
#define lib_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int string_length(char *s) {
    return strlen(s);
}

void string_copy(char *x, char *y) {
    char *to = x, *from = y;
    while (*from)
        *to++ = *from++;
    *to = '\0';
}

#endif
