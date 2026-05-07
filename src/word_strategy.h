#ifndef WORD_STRATEGY_H
#define WORD_STRATEGY_H

/**
 * @brief Function pointer type for a word selection strategy.
 *
 * This type represents a strategy function that selects one word
 * from an array of available words.
 *
 * @param words Array of available words.
 * @param num_words Number of words in the array.
 * @return const char* Selected word.
 */
typedef const char* (*WordSelectionStrategy)(const char **words, int num_words);

/**
 * @brief Selects a random word from the word list.
 *
 * @param words Array of available words.
 * @param num_words Number of words in the array.
 * @return const char* Randomly selected word.
 */
const char* random_word_strategy(const char **words, int num_words);

/**
 * @brief Selects the first word from the word list.
 *
 * @param words Array of available words.
 * @param num_words Number of words in the array.
 * @return const char* First word in the list.
 */
const char* first_word_strategy(const char **words, int num_words);

#endif
