#ifndef GAME_H
#define GAME_H

/**
 * @brief Converts uppercase letters to lowercase.
 * 
 * @param c Character to normalize.
 * @return char Normalized lowercase character.
 */
char normalize_letter(char c);

/**
 * @brief Checks if a character is a valid alphabet letter.
 * 
 * @param c Character to check.
 * @return int Returns 1 if it is a letter, otherwise 0.
 */
int is_letter(char c);

/**
 * @brief Updates the display word with the guessed letter.
 * 
 * @param secret Secret word.
 * @param guess Letter entered by the player.
 * @param display Current visible word display.
 * @return int Returns 1 if the guess was correct, otherwise 0.
 */
int update_display(const char *secret, char guess, char display[]);

/**
 * @brief Checks if the player has guessed the whole word.
 * 
 * @param display Current visible word display.
 * @return int Returns 1 if the player won, otherwise 0.
 */
int check_win(const char display[]);

#endif
