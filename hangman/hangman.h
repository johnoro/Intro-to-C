#ifndef hangman_h
#define hangman_h


// https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
int ascii_distance = 'a' - 'A';

void lower_string(char *s) {
  int c = 0;
  while (s[c]) {
    if (s[c] >= 'A' && s[c] <= 'Z')
      s[c] += ascii_distance;
    c++;
  }
}

#endif
