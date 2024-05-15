# CMSC-341 proj0

# Bingo Game Implementation

## Overview
This project implements a Bingo game in C++. It provides functionalities to create Bingo cards, draw balls, and simulate a Bingo game.

## Files
- `bingo.h`: Header file containing class declarations.
- `bingo.cpp`: Implementation file for the Bingo class.
- `main.cpp`: Sample main file demonstrating the usage of the Bingo class.

## Compilation and Execution
To compile the program, use any C++ compiler such as g++:
Or simply use the provided makefile. 

## Usage
1. Include `bingo.h` in your C++ code.
2. Create a Bingo object using the constructors provided.
3. Use member functions to initialize cards, draw balls, and simulate the game.
4. Sample usage can be found in `main.cpp`.

## Functionality
- `Bingo()`: Default constructor to create an empty Bingo object.
- `Bingo(int rows, int columns, int min, int max)`: Overloaded constructor to create a Bingo object with specified parameters.
- `reCreateCard(int rows, int columns, int min, int max)`: Initialize a new card with randomly generated numbers.
- `play(int numDraws, vector<int> rndBalls)`: Simulate a Bingo game with given draws.
- `dumpCard()`: Renders the Bingo card in the terminal for debugging.

## Author
- Andrew Tang

## Date
- September 12, 2023
