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
	char *print_state = malloc(sizeof(char) * 10);
	for (int i = 0; i < HANG_LEN; i++) {
		strncpy(print_state, HANG_STATES[i] + state*10, 10);
		print_state[10] = '\0';
		printf("%s\n", print_state);
	}
}

int main(int argc, char *argv[]) {
	// Initializes word(s) based off of command line argument(s)
	char *word = malloc(sizeof(char) * 1024);
	strcpy(word, argv[1]);
	for (int i = 2; i < argc; i++) {
		printf("\n!%s!\n", argv[i]);
		for (size_t j = 0; j < strlen(argv[i]); j++) {
			char c = argv[i][j];
			if (strchr(word, c) == NULL) {
				size_t len = strlen(word);
				word[len] = c;
				word[len+1] = '\0';
			}
		}
	}
	lower_string(word);
	printf("\n%s\n\n", word);


	char *correct_guesses = malloc(sizeof(char) * strlen(word)), 
		*incorrect_guesses = malloc(sizeof(char) * 65);
	char guess;
	int current_state = 0;

	while (1) {
		print_hangman(current_state);

		printf("\nGuess: ");
		scanf(" %c", &guess);
		guess = tolower(guess);
		printf("%c\n", guess);
		if (strchr(correct_guesses, guess)) {
			printf("\nYou've already guessed %c!\n", guess);
		} else if (strchr(incorrect_guesses, guess)) {
			printf("\nYou've already guessed %c!\n", guess);
		} else if (strchr(word, guess)) {
			size_t len = strlen(correct_guesses);
			correct_guesses[len] = guess;
			correct_guesses[len+1] = '\0';
			printf("\n%c is correct!\n", guess);
			// printf("\n%ld, %ld\n", len+1, strlen(word));
			if (len+1 == strlen(word)) {
				printf("\nYou won!\n");
				break;
			}
		} else {
			size_t len = strlen(incorrect_guesses);
			incorrect_guesses[len] = guess;
			incorrect_guesses[len+1] = '\0';
			printf("\n%c is wrong!\n", guess);
			if (current_state++ == HANG_LEN) {
				print_hangman(current_state);
				printf("\nYou lost!\n");
				break;
			}
		}
	}

  return 0;
}
