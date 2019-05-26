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

size_t append_char(char *str, char c) {
  size_t len = strlen(str);
  str[len] = c;
  str[len+1] = '\0';
  return len+1;
}

void print_word(char *pretty_word, char *correct_guesses) {
	size_t len = strlen(pretty_word);
	char *pretty = malloc((len+1) * sizeof(char));
	for (size_t i = 0; i < len; i++) {
		char c = pretty_word[i];
		size_t len = strlen(pretty);
		if (c == ' ' || strchr(correct_guesses, c))
			pretty[len] = c;
		else
			pretty[len] = '_';
		pretty[len+1] = '\0';
	}
	printf("\n%s\n", pretty);
  free(pretty);
}

void print_guesses(char *correct, char *incorrect) {
	printf("\nGuesses so far:\n");
	size_t c_len = strlen(correct);
	size_t inc_len = strlen(incorrect);
	char *s = malloc(sizeof(char) * (c_len?c_len:1) * (inc_len?inc_len:1));
	strcat(s, correct);
	strcat(s, incorrect);
	int i = 0, len = strlen(s) * 2;
	char *p = s, *res = malloc(len+1);
	for (char ch = 'a'; ch <= 'z'; ch++) {
		for (int c = 0; c < len; c++) {
			if (*p == ch) {
				res[i++] = *p;
				res[i++] = ' ';
			}
			p++;
		}
		p = s;
	}
	res[i] = '\0';
	printf("%s", res);
	printf("\n");
	free(s);
	free(res);
}

#endif
