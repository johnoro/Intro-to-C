#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"

#define HANG_LEN 7

char HANG_STATES[HANG_LEN][10 * 9] = {
	"             +         +----     +----     +----     +----     +----     +----     +----  ",
	"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
	"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
	"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
	"             |         |         |         |         |         |         |  /      |  / \\ ",
	"             |         |         |         |         |         |         |         |      ",
	"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "
};

void print_hangman(int state) {
	printf("\n");
	char *print_state = malloc(sizeof(char) * 10);
	for (int i = 0; i < HANG_LEN; i++) {
		strncpy(print_state, HANG_STATES[i] + state*10, 10);
		print_state[10] = '\0';
		printf("%s\n", print_state);
	}
	free(print_state);
}

int main(int argc, char *argv[]) {
	// Initializes word(s) based off of command line argument(s)
	char *word = malloc(sizeof(char) * 256),
		*pretty_word = malloc(sizeof(char) * 256);
	strcpy(pretty_word, argv[1]);
	for (int i = 1; i < argc; i++) {
		if (i > 1) {
			strcat(pretty_word, " ");
			strcat(pretty_word, argv[i]);
		}

		for (size_t j = 0; j < strlen(argv[i]); j++) {
			char c = argv[i][j];
			if (strchr(word, c) == NULL)
				append_char(word, c);
		}
	}
	lower_string(word);


	char *correct_guesses = malloc(sizeof(char) * (strlen(word)+1)),
		*incorrect_guesses = malloc(sizeof(char) * 65);
	char guess;
	int current_state = 0;

	while (1) {
		print_hangman(current_state);
		print_word(pretty_word, correct_guesses, incorrect_guesses);

		printf("\nGuess: ");
		scanf(" %c", &guess);
		guess = tolower(guess);
		if (strchr(correct_guesses, guess) || strchr(incorrect_guesses, guess))
			printf("\nYou've already guessed %c!\n", guess);
		else if (strchr(word, guess)) {
			size_t len = append_char(correct_guesses, guess);
			printf("\n%c is correct!\n", guess);
			
			if (len == strlen(word)) {
				print_word(pretty_word, correct_guesses, incorrect_guesses);
				printf("\nYou won!\n");
				break;
			}
		} else {
			append_char(incorrect_guesses, guess);
			printf("\n%c is wrong!\n", guess);

			if (current_state++ == HANG_LEN) {
				print_hangman(current_state);
				printf("\nYou lost!\n");
				break;
			}
		}

		print_guesses(correct_guesses, incorrect_guesses);
	}

	free(word);
	free(pretty_word);
	free(correct_guesses);
	free(incorrect_guesses);

  return 0;
}
