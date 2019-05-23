#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int isFizzy(int n) {
    return n % 3 == 0;
}

int isBuzzy(int n) {
    return n % 5 == 0;
}

int fizzbuzz(int n) {
    int count = 0;
    printf("\n");
    do {
        printf("%d: ", n);
        if (isFizzy(n)) {
            if (isBuzzy(n))
                printf("FizzBuzz");
            else
                printf("Fizz");
        } else if (isBuzzy(n))
            printf("Buzz");
        else
            count++;
        printf("\n");
    } while (--n > 0);
    printf("\n");
    return count;
}

#ifndef TESTING
int main(void) {
    fizzbuzz(20);

    return 0;
}
#endif
