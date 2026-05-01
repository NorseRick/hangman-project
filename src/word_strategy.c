#include "word_strategy.h"
#include <stdlib.h>

const char* random_word_strategy(const char **words, int num_words) {
    return words[rand() % num_words];
}

const char* first_word_strategy(const char **words, int num_words) {
    return words[0];
}
