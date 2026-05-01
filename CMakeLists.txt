cmake_minimum_required(VERSION 3.5)

project(HangmanProject C)

set(CMAKE_C_STANDARD 99)

add_executable(hangman
    src/main.c
    src/game.c
    src/word_strategy.c
)

add_executable(test_game
    tests/test_game.c
    src/game.c
)

enable_testing()

add_test(NAME GameTests COMMAND test_game)
