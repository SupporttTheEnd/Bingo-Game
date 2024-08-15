# Bingo Game Implementation

## Overview
This project contains the implementation of a Bingo game in C++. The project includes functionalities to create, initialize, play, and manage a Bingo game.

## Files
- `bingo.h` and `bingo.cpp`: These files contain the implementation of the Bingo game class, including constructors, destructor, methods for initializing the game, playing the game, and managing memory.
- `mytest.cpp` and `driver.cpp`: These files provide test cases and a driver program to demonstrate the functionality of the Bingo game.
- `Makefile`: Contains instructions for compiling the project.

## How to Use
1. Include `bingo.h` in your C++ project.
2. Create an instance of the `Bingo` class using one of the provided constructors.
3. Initialize the Bingo card using the `reCreateCard` method.
4. Play the game using the `play` method, passing a vector of randomly drawn numbers.
5. Check the result of the game to determine the number of replacements made.
6. Optionally, use the `dumpCard` method to display the Bingo card in the terminal.

## Compilation
To compile the project, you can use the provided Makefile. Use the following commands:
- `make p`: Compiles `mytest.cpp` with `bingo.o` to create an executable named `proj0`.
- `make d`: Compiles `driver.cpp` with `bingo.o` to create an executable named `proj0`.
- `make v`: Runs `valgrind` to check for memory leaks.
- `make r`: Runs the executable `proj0`.

## Cleaning Up
To clean up object files and executables, you can use:
- `make clean`: Removes object files and temporary files.

