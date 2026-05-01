# Hangman Project

This is a simple Hangman game written in C.

## Requirements Covered

- Source code
- CMake build file
- Git version control
- Strategy design pattern
- Unit tests

## Design Pattern

The project uses the Strategy Pattern for word selection.

The game does not directly choose the secret word. Instead, it uses a strategy function.

Available strategies:
- random_word_strategy
- first_word_strategy

## Project Structure

hangman_project/
├── src/
│   ├── main.c
│   ├── game.c
│   ├── game.h
│   ├── word_strategy.c
│   └── word_strategy.h
├── tests/
│   └── test_game.c
├── CMakeLists.txt
├── README.md
└── .gitignore

## Build Instructions

mkdir build
cd build
cmake ..
make

## Run the Game

./hangman

## Run Unit Tests

./test_game
ctest

## Author

Ricardo Vazquez

