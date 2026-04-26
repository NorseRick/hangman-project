#include <stdio.h>                                                              // printf, scanf
#include <stdlib.h>                                                             // rand, srand
#include <string.h>                                                             // strlen
#include <time.h>                                                               // time, difftime, clock

int main(int argc, char *argv[]) {

    // List of possible secret words (Array of strings)
    const char *words[] = {
        "computer",
        "keyboard",
        "mouse",
        "monitor",
        "laptop"
    };

    int num_words = 5;                                                          // Total number of words

    srand(time(NULL));                                                          // Initialize random numbers
    const char *secret = words[rand() % num_words];                             // Choose a random word pointing to secret varable

    int len = strlen(secret);                                                   // Length of the secret word
    char display[50];                                                           // Word shown to the player
    int lives = 6;                                                              // Number of lives
    int won = 0;                                                                // Win flag (0 = no, 1 = yes)
    char input[10];                                                             // User input
    char guess;                                                                 // Single valid letter

    // Fill display with underscores
    for (int i = 0; i < len; i++) {
        display[i] = '_';
    }
    display[len] = '\0';                                                        // End of string

    // Start time measurement
    time_t real_start = time(NULL);                                             // Start real time
    clock_t cpu_start = clock();                                                // Start CPU time

    printf("--- HANGMAN ---\n");
    printf("Guess the word (one letter only).\n\n");

    // Main game loop
    while (lives > 0) {

        // Show current word
        printf("Word: ");
        for (int i = 0; i < len; i++) {
            printf("%c ", display[i]);
        }
        printf("\n");

        // Show lives and ask for a letter
        printf("Lives: %d\n", lives);
        printf("Letter: ");
        scanf("%9s", input);                                                    // Read user input

        // Check that only one character was entered
        if (strlen(input) != 1) {
            printf("Enter only ONE letter.\n\n");
            continue;                                                           // Skip turn
        }

        guess = input[0];                                                       // Get the character

        // Check if input is a letter
        if ((guess < 'A' || guess > 'Z') &&
            (guess < 'a' || guess > 'z')) {
            printf("Enter a valid letter.\n\n");
            continue;                                                           // Skip turn
        }

                                                                                // Convert uppercase letter to lowercase
        if (guess >= 'A' && guess <= 'Z') {
            guess = guess + ('a' - 'A');
        }

        int hit = 0;                                                            // Check if letter was found

        // Compare guessed letter with the secret word
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess) {
                display[i] = guess;                                             // Reveal letter
                hit = 1;
            }
        }

        // Lose a life if letter was not found
        if (!hit) {
            lives--;
        }

        // Check if the whole word is guessed
        won = 1;
        for (int i = 0; i < len; i++) {
            if (display[i] == '_') {
                won = 0;
                break;
            }
        }

        if (won) {
            break;                                                              // Exit game loop
        }

        printf("\n");
    }

    // End time measurement
    time_t real_end = time(NULL);                                               // End real time
    clock_t cpu_end = clock();                                                  // End CPU time

    double real_seconds = difftime(real_end, real_start);                       // Total real time
    double cpu_seconds =
        (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC;                         // Total CPU time

    // Show final result
    if (won) {
        printf("\nYou Win! The word was: %s\n", secret);
    } else {
        printf("\nYou Lose! The word was: %s\n", secret);
    }

    // Show time results
    printf("\n TIME RESULTS \n");
    printf("Real time: %.2f seconds\n", real_seconds);
    printf("CPU time:  %.5f seconds\n", cpu_seconds);

    printf("\nThanks for playing!\n");

    return 0;                                                                   // End of program
}

	
