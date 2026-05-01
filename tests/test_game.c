#include <stdio.h>
#include "../src/game.h"

int main() {
    int failed = 0;

    if (normalize_letter('A') != 'a') {
        printf("Test failed: normalize_letter\n");
        failed++;
    }

    if (!is_letter('z')) {
        printf("Test failed: is_letter\n");
        failed++;
    }

    char display[20] = "________";
    int hit = update_display("computer", 'o', display);

    if (!hit || display[1] != 'o') {
        printf("Test failed: update_display\n");
        failed++;
    }

    char win_display[] = "computer";

    if (!check_win(win_display)) {
        printf("Test failed: check_win\n");
        failed++;
    }

    if (failed == 0) {
        printf("All tests passed!\n");
        return 0;
    }

    return 1;
}
