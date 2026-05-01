#ifndef WORD_STRATEGY_H
#define WORD_STRATEGY_H

typedef const char* (*WordSelectionStrategy)(const char **words, int num_words);

const char* random_word_strategy(const char **words, int num_words);
const char* first_word_strategy(const char **words, int num_words);

#endif
