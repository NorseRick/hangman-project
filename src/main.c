#include <stdio.h>          // printf, scanf
#include <stdlib.h>         // srand
#include <string.h>         // strlen
#include <time.h>           // time, difftime, clock

#include "word_strategy.h"
#include "game.h"

int main(int argc, char *argv[]) {

    // List of possible secret words
    const char *words[] = {
        "computer",
        "keyboard",
        "mouse",
        "monitor",
        "laptop"
    };

    int num_words = 5;

    srand(time(NULL));

    // Strategy Pattern: the word selection logic is separated
    WordSelectionStrategy strategy = random_word_strategy;
    const char *secret = strategy(words, num_words);

    int len = strlen(secret);
    char display[50];
    int lives = 6;
    int won = 0;
    char input[10];
    char guess;

    for (int i = 0; i < len; i++) {
        display[i] = '_';
    }
    display[len] = '\0';

    time_t real_start = time(NULL);
    clock_t cpu_start = clock();

    printf("--- HANGMAN ---\n");
    printf("Guess the word (one letter only).\n\n");

    while (lives > 0) {

        printf("Word: ");
        for (int i = 0; i < len; i++) {
            printf("%c ", display[i]);
        }
        printf("\n");

        printf("Lives: %d\n", lives);
        printf("Letter: ");
        scanf("%9s", input);

        if (strlen(input) != 1) {
            printf("Enter only ONE letter.\n\n");
            continue;
        }

        guess = input[0];

        if (!is_letter(guess)) {
            printf("Enter a valid letter.\n\n");
            continue;
        }

        guess = normalize_letter(guess);

        int hit = update_display(secret, guess, display);

        if (!hit) {
            lives--;
        }

        won = check_win(display);

        if (won) {
            break;
        }

        printf("\n");
    }

    time_t real_end = time(NULL);
    clock_t cpu_end = clock();

    double real_seconds = difftime(real_end, real_start);
    double cpu_seconds =
        (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC;

    if (won) {
        printf("\nYou Win! The word was: %s\n", secret);
    } else {
        printf("\nYou Lose! The word was: %s\n", secret);
    }

    printf("\nTIME RESULTS\n");
    printf("Real time: %.2f seconds\n", real_seconds);
    printf("CPU time:  %.5f seconds\n", cpu_seconds);

    printf("\nThanks for playing!\n");

    return 0;
}
