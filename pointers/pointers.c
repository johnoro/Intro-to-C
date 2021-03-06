#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *to, char *from) {
    while (*from)
        *to++ = *from++;
    *to = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c) {
    while (*str) {
        if (*str == c)
            return str;
        str++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle) {
    // while haystack is not null
    while (*haystack) {
        // if first char is equal
        if (*haystack == *needle) {
            // make temp ptrs
            char *s = haystack, *n = needle;
            // check rest against the needle
            while (*++n && *++s) {
                if (*n != *s)
                    break;
            }
            // return haystack ptr if right
            if (*n == '\0')
                return haystack;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void) {
    char *hello = "hello";
    char *found_char = find_char(hello, 'e');
    printf("Unaffected: %s\n", hello);
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
