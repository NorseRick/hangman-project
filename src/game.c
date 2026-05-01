#include "game.h"

char normalize_letter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int update_display(const char *secret, char guess, char display[]) {
    int hit = 0;

    for (int i = 0; secret[i] != '\0'; i++) {
        if (secret[i] == guess) {
            display[i] = guess;
            hit = 1;
        }
    }

    return hit;
}

int check_win(const char display[]) {
    for (int i = 0; display[i] != '\0'; i++) {
        if (display[i] == '_') {
            return 0;
        }
    }
    return 1;
}
