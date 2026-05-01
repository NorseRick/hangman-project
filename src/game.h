#ifndef GAME_H
#define GAME_H

char normalize_letter(char c);
int is_letter(char c);
int update_display(const char *secret, char guess, char display[]);
int check_win(const char display[]);

#endif
