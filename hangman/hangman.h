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

void print_word(char *pretty_word, char *correct, char *incorrect) {
	if (strlen(correct) == 0 && strlen(incorrect) == 0)
		return;

	size_t p_len = strlen(pretty_word);
	char *pretty = malloc((p_len+1) * sizeof(char));
	for (size_t i = 0; i < p_len; i++) {
		char c = pretty_word[i];
		size_t len = strlen(pretty);
		if (c == ' ' || strchr(correct, c))
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
	size_t c_len = strlen(correct), inc_len = strlen(incorrect);
	int s_len = ((c_len?c_len:1)*(inc_len?inc_len:1) + 1);
	char s[s_len];
	memset(s, 0, s_len * sizeof(char));
	if (c_len) {
		strcpy(s, correct);
		if (inc_len)
			strcat(s, incorrect);
	} else if (inc_len)
		strcpy(s, incorrect);
	int i = 0, len = s_len*2 + 1;
	char *p = s, *guesses = malloc(sizeof(char) * len);
	for (int ch = 'a'; ch <= 'z'; ch++) {
		for (int c = 0; c < len; c++) {
			if (strchr(guesses, ch) == NULL && *p == ch) {
				guesses[i++] = ch;
				guesses[i++] = ' ';
				guesses[i] = '\0';
			}
			p++;
		}
		p = s;
	}
	printf("%s\n", guesses);
	free(guesses);
}

#endif
