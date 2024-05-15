// UMBC - CMSC 341 - Fall 2023 - Proj0
// Title: bingo.cpp
// Author: Andrew Tang
// Date: 9/12/2023
// Description: This is a implementation file for bingo.cpp

#include "bingo.h"


// Name - Bingo()
// Desc - The default constructor; sets object to empty object
// Preconditions - None
// Postconditions - Makes an empty object
Bingo::Bingo(){
    // Initialize member variables with null values
    m_trackCols = nullptr;
    m_trackRows = nullptr;
    m_helper = nullptr;
    m_helperSize = 0;
    m_card = nullptr;
    m_numRows = 0; 
    m_numCols = 0; 
    m_minBallVal = 0; 
    m_maxBallVal = 0; 
}


// Name - Bingo(int rows, int columns, int min, int max)
// Desc - The overloaded constructor; initializes all member variables and it allocates required memory if neccessary. 
// If the user passes invalid parameters such as a negative size the constructor creates an empty object.
// Preconditions - None
// Postconditions - Initializes the members of an object
Bingo::Bingo(int rows, int columns, int min, int max){
    // Check if the parameters satisfy the requirements
    if (rows < 2 || rows > 15 || columns != 5 || min < 1 || max < min || (max - min + 1) % 5 != 0) {
        // When there are invalid parameters, create an empty object by setting all values to null
        m_trackCols = nullptr;
        m_trackRows = nullptr;
        m_helper = nullptr;
        m_helperSize = 0;
        m_card = nullptr;
        m_numRows = 0; 
        m_numCols = 0;
        m_minBallVal = 0;
        m_maxBallVal = 0;
        return;
    }

    // Set the number of rows, columns, min, and max values
    m_numRows = rows;
    m_numCols = columns;
    m_minBallVal = min;
    m_maxBallVal = max;

    m_helperSize = m_maxBallVal + 1;

    // Allocate the memory
    m_trackCols = new int[m_numCols];
    m_trackRows = new int[m_numRows];
    m_helper = new Cell[m_helperSize];


    // Allocate memory for card
    m_card = new Cell*[m_numRows];
    for (int i = 0; i < m_numRows; i++) {
        m_card[i] = new Cell[m_numCols];
    }
}


// Name - reCreateCard(int rows, int columns, int min, int max)
// Desc -  Initializes a new card with randomly generated numbers. Generally we call this function after calling clear().
// Preconditions - The object is empty
// Postconditions - Initializes the members of an object and populates the data structures
bool Bingo::reCreateCard(int rows, int columns, int min, int max){
    // Check if there is memory left
    if (m_trackCols != nullptr || m_trackRows != nullptr || m_helper != nullptr || m_card != nullptr) {
        return false; 
    }

    // Check if the parameters satisfy the requirements
    if (rows < 2 || rows > 15 || columns != 5 || min < 1 || max < min || (max - min + 1) % 5 != 0) {
        return false;
    }

    // Initialize member variables with the provided values
    m_numRows = rows;
    m_numCols = columns;
    m_minBallVal = min;
    m_maxBallVal = max;

    m_helperSize = m_maxBallVal + 1;

    // Allocate the memory
    m_trackCols = new int[m_numCols];
    m_trackRows = new int[m_numRows];
    m_helper = new Cell[m_helperSize];

    // Allocate memory for the card
    m_card = new Cell*[m_numRows];
    for (int i = 0; i < m_numRows; i++) {
        m_card[i] = new Cell[m_numCols];
    }

    initCard();
    return true; // Success
}


// Name - ~Bingo()
// Desc -  Deallocate any dynamically allocated memory
// Preconditions - None
// Postconditions - The object's memory will be deallocated
Bingo::~Bingo(){
    // Deallocate the trackCols and trackRows arrays
    delete[] m_trackCols;
    delete[] m_trackRows;

    // Deallocate the helper array
    delete[] m_helper;

    // Deallocate the card and its contents
    if (m_card != nullptr) {
        for (int i = 0; i < m_numRows; i++) {
            delete[] m_card[i];
        }
        delete[] m_card;
    }
}


// Name - clear()
// Desc -  Deallocate any dynamically allocated memory  and re-initializes all member variables to default values. 
// It clears the current object to an empty object.
// Preconditions - None
// Postconditions - The object's memory will be deallocated and will be empty
void Bingo::clear(){

    // Deallocate the trackCols and trackRows arrays
    delete[] m_trackCols;
    delete[] m_trackRows;

    // Deallocate the helper array
    delete[] m_helper;

    // Deallocate the card and its contents
    if (m_card != nullptr) {
        for (int i = 0; i < m_numRows; i++) {
            delete[] m_card[i];
        }
        delete[] m_card;
    }

    // Reset member variables to their default values
    m_trackCols = nullptr;
    m_trackRows = nullptr;
    m_helper = nullptr;
    m_helperSize = 0;
    m_card = nullptr;
    m_numRows = 0; 
    m_numCols = 0; 
    m_minBallVal = 0;
    m_maxBallVal = 0; 
}


// Name - initCard()
// Desc -  This function populates the card cells with random numbers.
// Preconditions - Object has correct memory allocated.
// Postconditions - The object's card and other helper arrays will be populated
bool Bingo::initCard(){
    // Check if memory allocation for helper arrays was done
    if (m_trackCols == nullptr || m_trackRows == nullptr || m_helper == nullptr || m_card == nullptr) {
        return false; // Memory allocation failed, initialization failed
    }

    // Clear out the data in m_card if the card is already populated
    for (int i = 0; i < m_numCols; i++) {
        for (int j = 0; j < m_numRows; j++) {
            if (m_card[j][i].getVal() != EMPTYCELL) {
                m_card[j][i].setVal(EMPTYCELL);
            }
        }
    }

    // Clear out the data in m_helper
    for (int i = 0; i < m_helperSize; i++) {
        if (m_helper[i].getVal() != EMPTYCELL) {
            m_helper[i].setVal(EMPTYCELL);
        }
    }

    // Initialize trackCols and trackRows to 0
    for (int i = 0; i < m_numCols; i++) {
        m_trackCols[i] = 0;
    }
    for (int i = 0; i < m_numRows; i++) {
        m_trackRows[i] = 0;
    }

    int range = (m_maxBallVal - m_minBallVal + 1) / 5;
    int start = m_minBallVal;

    for (int i = 0; i < m_numCols; i++) {
        Random randomNumbers(start, start + range - 1, RANDOM::SHUFFLE);
        vector<int> shuffledNumbers;
        randomNumbers.getShuffle(shuffledNumbers);

        for (int j = 0; j < m_numRows; j++) {
            m_card[j][i].setRow(j);
            m_card[j][i].setCol(i);
            m_card[j][i].setVal(shuffledNumbers[j]);
            m_helper[shuffledNumbers[j]] = m_card[j][i];
        }
        start += range;
    }
    
    return true; // Initialization successful
}


// Name - drawBalls()
// Desc -  This function generates and returns a list containing randomly distributed ball numbers. 
// Preconditions - None
// Postconditions - Populates a vector
vector<int> Bingo::drawBalls(){
    vector<int> balls;
    Random randomNumbers(m_minBallVal, m_maxBallVal, RANDOM::SHUFFLE);
    randomNumbers.getShuffle(balls);
    return balls;
}


// Name - play()
// Desc -  This function gets ball numbers from the vector rndBalls. If the ball number exists 
// in the card this function replaces the corresponding cell in the card with an empty cell, i.e. EMPTYCELL. 
// The function counts the number of replacements and at the end returns it. Among multiple players 
// who are playing with the same rndBalls vector, the player who gets the lower count is the winner.
// Preconditions - Object has memory allocated and is populated, a vector of random numbers is also provided
// Postconditions - Simulates a bingo game
int Bingo::play(int numDraws, vector<int> rndBalls){
    if (numDraws <= 0 || int(rndBalls.size()) > m_maxBallVal - m_minBallVal + 1|| numDraws > m_maxBallVal - m_minBallVal + 1 || numDraws > int(rndBalls.size())) {
        // Invalid parameters or error case, return -1
        return -1;
    }
    
    // check if memory allocation for helper arrays was done
    if (m_trackCols == nullptr || m_trackRows == nullptr || m_helper == nullptr || m_card == nullptr) {
        return -1; // Memory allocation failed, initialization failed
    }

    // makes sure that the card is populated
    for (int i = 0; i < m_numCols; i++) {
        for (int j = 0; j < m_numRows; j++) {
            if (m_card[j][i].getVal() == EMPTYCELL) {
                return -1;
            }
        }
    }

    int numReplacements = 0;

    for (int drawCount = 0; drawCount < numDraws; drawCount++) {
        int ball = rndBalls[drawCount];
        // Check if the drawn ball number exists in the card
        if(m_helper[ball].getVal() != EMPTYCELL){
            m_helper[ball].setVal(EMPTYCELL);
            m_card[m_helper[ball].getRow()][m_helper[ball].getCol()].setVal(EMPTYCELL);
            m_trackCols[m_helper[ball].getCol()]++;
            m_trackRows[m_helper[ball].getRow()]++;
            numReplacements++;
        }
        for (int i = 0; i < m_numCols; i++){
            if (m_trackCols[i] == m_numRows){
                return numReplacements;
            }
        }
        for (int i = 0; i < m_numRows; i++){
            if (m_trackRows[i] == m_numCols){
                return numReplacements;
            }
        }
    }
    return numReplacements;
}


// Name - operator=(const Bingo & rhs)
// Desc -  The assignment operator creates a deep copy of rhs. 
// Preconditions - Rhs object exists
// Postconditions - Copies rhs to lhs
const Bingo & Bingo::operator=(const Bingo & rhs){
    // Makes sure that if  lhs = rhs, then the information is not cleared
    if (this == &rhs) {
        return *this;
    }

    // Deallocate any existing memory
    clear();

    reCreateCard(rhs.m_numRows, rhs.m_numCols, rhs.m_minBallVal, rhs.m_maxBallVal);
    
    // Copy the card and helper array
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            m_card[i][j] = rhs.m_card[i][j];
        }
    }
    
    for (int i = 0; i < m_helperSize; i++) {
        m_helper[i] = rhs.m_helper[i];
    }

    // Copy the trackRows and trackCols arrays
    for (int i = 0; i < m_numRows; i++) {
        m_trackRows[i] = rhs.m_trackRows[i];
    }
    
    for (int i = 0; i < m_numCols; i++) {
        m_trackCols[i] = rhs.m_trackCols[i];
    } 
    return *this;
}


// The dump function renders the card in the terminal
// This function is provided to facilitate debugging
// Using this function as a test case will not be accepted
void Bingo::dumpCard(){
    cout << "  ";
    cout << "\033[1;35m B   I   N   G   O\033[0m";    
    cout << endl;
    for (int i=1;i <= m_numRows;i++){
        if ((i < 10))
            cout << "\033[1;35m" << "0" << i << " \033[0m";
        else
            cout << "\033[1;35m" << i << " \033[0m";
        for (int j=1;j<= m_numCols;j++){
            if (m_card[i-1][j-1].getVal() == EMPTYCELL)
                cout << "\033[1;31m" << m_card[i-1][j-1].getVal() << "\033[0m" << "  ";
            else
                cout << m_card[i-1][j-1].getVal() << "  ";
        }
        cout << endl;
    }
    cout << endl;
}


// the overloaded equality operator for the Cell object
bool operator==(const Cell & lhs, const Cell & rhs){
    return ((lhs.m_col == rhs.m_col) &&
            (lhs.m_row == rhs.m_row) &&
            (lhs.m_value == rhs.m_value));
}
