// UMBC - CMSC 341 - Fall 2023 - Proj0
// Title: mytest.cpp
// Author: Andrew Tang
// Date: 9/12/2023
// Description: This is a test file for bingo.cpp

#include "bingo.h"
class Tester{
    public:wols != nullptr || obj.m_trackRows != nullptr || obj.m_helper != nullptr || obj.m_card != nullptr) {
            result = false;
        }

        return result; 
    }

    bool constructorEdge(Bingo & obj) {
        bool result = true;

        // We expect int type member variables have the correct values
        if (obj.m_numRows != 2 || obj.m_numCols != 5 || obj.m_minBallVal != MINVAL || obj.m_maxBallVal != MAXVAL || obj.m_helperSize != MAXVAL + 1) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols == nullptr || obj.m_trackRows == nullptr || obj.m_helper == nullptr || obj.m_card == nullptr) {
            result = false;
        }

        return result; 
    }

    bool constructorEdge2(Bingo & obj) {
        bool result = true;

        // We expect int type member variables have the correct values
        if (obj.m_numRows != 15 || obj.m_numCols != 5 || obj.m_minBallVal != MINVAL || obj.m_maxBallVal != MAXVAL || obj.m_helperSize != MAXVAL + 1) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols == nullptr || obj.m_trackRows == nullptr || obj.m_helper == nullptr || obj.m_card == nullptr) {
            result = false;
        }

        return result; 
    }
    
    bool constructorNormal(Bingo & obj) {
        bool result = true;

        // We expect int type member variables have the correct values
        if (obj.m_numRows != 10 || obj.m_numCols != 5 || obj.m_minBallVal != MINVAL || obj.m_maxBallVal != MAXVAL || obj.m_helperSize != MAXVAL + 1) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols == nullptr || obj.m_trackRows == nullptr || obj.m_helper == nullptr || obj.m_card == nullptr) {
            result = false;
        }

        return result; 
    }

    bool reCreateError(Bingo & obj) {
        bool result = true;
        if (obj.reCreateCard(-5,-10,MINVAL,MAXVAL) != false){
            result = false; 
        }
         // We expect the object is empty (invalid parameters should result in an empty object)
        if (obj.m_numRows != 0 || obj.m_numCols != 0 || obj.m_minBallVal != 0 || obj.m_maxBallVal != 0 || obj.m_helperSize != 0) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols != nullptr || obj.m_trackRows != nullptr || obj.m_helper != nullptr || obj.m_card != nullptr) {
            result = false;
        }

        return result; 
    }

        
    bool reCreateError2(Bingo & obj) {
        bool result = true;

        // Capture the initial states of the variables
        int numRowsBefore = obj.m_numRows;
        int numColsBefore = obj.m_numCols;
        int minValBefore = obj.m_minBallVal;
        int maxValBefore = obj.m_maxBallVal;
        int helperSizeBefore = obj.m_helperSize;           

        if (obj.reCreateCard(5,10,MINVAL,MAXVAL) != false){
            result = false; 
        }

        // checking if the int types are still the same
        if (numRowsBefore != obj.m_numRows || numColsBefore != obj.m_numCols ||
        minValBefore != obj.m_minBallVal || maxValBefore != obj.m_maxBallVal ||
        helperSizeBefore != obj.m_helperSize) {
            result = false;
        }

        return result; 
    }

    bool reCreateEdge(Bingo & obj) {
        bool result = true;
        if (obj.reCreateCard(2,5,MINVAL,MAXVAL) != true){
            result = false;
        }
        // We expect int type member variables have the correct values
        if (obj.m_numRows != 2|| obj.m_numCols != 5 || obj.m_minBallVal != MINVAL || obj.m_maxBallVal != MAXVAL || obj.m_helperSize != MAXVAL + 1) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols == nullptr || obj.m_trackRows == nullptr || obj.m_helper == nullptr || obj.m_card == nullptr) {
            result = false;
        }

        return result; 
    }

    bool reCreateEdge2(Bingo & obj) {
        bool result = true;
        if (obj.reCreateCard(15,5,MINVAL,MAXVAL) != true){
            result = false;
        }
        // We expect int type member variables have the correct values
        if (obj.m_numRows != 15 || obj.m_numCols != 5 || obj.m_minBallVal != MINVAL || obj.m_maxBallVal != MAXVAL || obj.m_helperSize != MAXVAL + 1) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols == nullptr || obj.m_trackRows == nullptr || obj.m_helper == nullptr || obj.m_card == nullptr) {
            result = false;
        }

        return result; 
    }

    bool reCreateNormal(Bingo & obj) {
        bool result = true;
        if (obj.reCreateCard(10,5,MINVAL,MAXVAL) != true){
            result = false;
        }
        // We expect int type member variables have the correct values
        if (obj.m_numRows != 10 || obj.m_numCols != 5 || obj.m_minBallVal != MINVAL || obj.m_maxBallVal != MAXVAL || obj.m_helperSize != MAXVAL + 1) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols == nullptr || obj.m_trackRows == nullptr || obj.m_helper == nullptr || obj.m_card == nullptr) {
            result = false;
        }

        return result; 
    }

    bool initCardError(Bingo & obj) {
        bool result = true;
        if (obj.initCard() != false){
            result = false; 
        }

        // We expect the object is empty (invalid parameters should result in an empty object)
        if (obj.m_numRows != 0 || obj.m_numCols != 0 || obj.m_minBallVal != 0 || obj.m_maxBallVal != 0 || obj.m_helperSize != 0) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols != nullptr || obj.m_trackRows != nullptr || obj.m_helper != nullptr || obj.m_card != nullptr) {
            result = false;
        }

        return result; 
    }

    bool initCardNormal(Bingo & obj) {
        bool result = true;

        if (obj.initCard() != true){
            result = false; 
        }
        
        // set the expected range and starting value
        int range = (obj.m_maxBallVal - obj.m_minBallVal + 1) / 5;
        int start = obj.m_minBallVal;

        // We expect the cells in m_card are initialized correctly
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                int cellValue = obj.m_card[i][j].getVal();
                // We expect the cell value falls within the specified range
                if (cellValue < obj.m_minBallVal || cellValue > obj.m_maxBallVal) {
                    result = false;
                }
                // We expect the column constraints are met
                if (cellValue < start + range * j|| cellValue >= start + range * (j + 1)) {
                    result = false;
                }
            }
        }

        return result; // Return the result
    }

    bool playError(Bingo & obj) {
        bool result = true;
        // check if play returns -1 in the case where draws > BALLS
        vector<int> balls = obj.drawBalls();
        if (obj.play(BALLS + 1, balls) != -1){
            result = false; 
        }

        // check if play returns -1 where vetorSize > BALLS
        balls.push_back(EMPTYCELL);
        if (obj.play(BALLS, balls) != -1){
            result = false; 
        }

        // check if play returns -1 where draws > vectorSize
        balls.pop_back();
        balls.pop_back();
        if (obj.play(BALLS, balls) != -1){
            result = false; 
        }

        // make absolute sure that none of the cells were changed to EMPTYCELL
        for (int i = 0; i < obj.m_numCols; i++) {
            for (int j = 0; j < obj.m_numRows; j++) {
                if (obj.m_card[j][i].getVal() == EMPTYCELL) {
                    result = false;
                }
             }
        }
        
        // making sure that the helper arrays did not get any values
        for (int i = 0; i < obj.m_numCols; i++){
            if (obj.m_trackCols[i] != 0){
                result = false;
            }
        }
        for (int i = 0; i < obj.m_numRows; i++){
            if (obj.m_trackRows[i] != 0){
                result = false;
            }
        }
        return result; // Return the result
    }
    
    bool playEdge(Bingo & obj) {
        bool result = true;
        // sets the card to predetermined values
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                obj.m_card[i][j].setRow(i);
                obj.m_card[i][j].setCol(j);
                obj.m_card[i][j].setVal(i * obj.m_numCols + j + 10);
            }
        }
        // clears out the helper
        for (int i = 0; i < obj.m_helperSize; i++) {
            obj.m_helper[i].setRow(0);
            obj.m_helper[i].setCol(0);
            obj.m_helper[i].setVal(EMPTYCELL);
        }

        // repopulates the helper with entries the card
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                obj.m_helper[obj.m_card[i][j].getVal()] = obj.m_card[i][j];
            }
        }

        // initializes a vector of size 5, with values of the top row
        vector<int> balls = {10, 11, 12, 13, 14}; 
        // I expect that the obj will end in 1 turn and the first row will have 1 emptycell
        if (obj.play(1,balls) != 1 || obj.m_trackRows[0] != 1){
            result = false; 
        }

        return result; // Return the result
    }

    bool playEdge2(Bingo & obj) {
        bool result = true;
        // sets the card to predetermined values
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                obj.m_card[i][j].setRow(i);
                obj.m_card[i][j].setCol(j);
                obj.m_card[i][j].setVal(i * obj.m_numCols + j + 10);
            }
        }
        // clears out the helper
        for (int i = 0; i < obj.m_helperSize; i++) {
            obj.m_helper[i].setRow(0);
            obj.m_helper[i].setCol(0);
            obj.m_helper[i].setVal(EMPTYCELL);
        }

        // repopulates the helper with entries the card
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                obj.m_helper[obj.m_card[i][j].getVal()] = obj.m_card[i][j];
            }
        }

        // initializes a vector of size 5, with values of the top row
        vector<int> balls = {}; 
        for (int i = 10; i <= 84; ++i) {
            balls.push_back(i);
        }
        // I expect that the obj will end in 1 turn and the first row will have 1 emptycell
        if (obj.play(BALLS,balls) != 5 || obj.m_trackRows[0] != 5){
            result = false; 
        }
        return result; // Return the result
    }

    bool playNormal(Bingo & obj) {
        bool result = true;
        // sets the card to predetermined values
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                obj.m_card[i][j].setRow(i);
                obj.m_card[i][j].setCol(j);
                obj.m_card[i][j].setVal(i * obj.m_numCols + j + 10);
            }
        }
        // clears out the helper
        for (int i = 0; i < obj.m_helperSize; i++) {
            obj.m_helper[i].setRow(0);
            obj.m_helper[i].setCol(0);
            obj.m_helper[i].setVal(EMPTYCELL);
        }

        // repopulates the helper with entries the card
        for (int i = 0; i < obj.m_numRows; i++) {
            for (int j = 0; j < obj.m_numCols; j++) {
                obj.m_helper[obj.m_card[i][j].getVal()] = obj.m_card[i][j];
            }
        }

        // initializes a vector of size 5, with values of the top row
        vector<int> balls = {10, 11, 12, 13, 14};
        
        // I expect that the obj will end in 5 turns and the first row will have 5 emptycells
        if (obj.play(5,balls) != 5 || obj.m_trackRows[0] != 5){
            result = false; 
        }
        return result; // Return the result
    }


    bool assignmentEdge(Bingo & obj) {
        bool result = true;

        // We expect the object is empty (invalid parameters should result in an empty object)
        if (obj.m_numRows != 0 || obj.m_numCols != 0 || obj.m_minBallVal != 0 || obj.m_maxBallVal != 0 || obj.m_helperSize != 0) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols != nullptr || obj.m_trackRows != nullptr || obj.m_helper != nullptr || obj.m_card != nullptr) {
            result = false;
        }

        return result; 
    }

    bool assignmentNormal(Bingo & lhs, Bingo & rhs){
        // we expect that lhs object is an exact copy of rhs object 
        bool result = true;
        // we expect that the corresponding cells in lhs and rhs
        //      cards carry the same cell information (exact same copy)
        for (int i = 0; i < rhs.m_numRows; i++){
            for (int j = 0; j< rhs.m_numCols; j++){
                result = result && (lhs.m_card[i][j] == rhs.m_card[i][j]);
            }
        }
        // we expect that the corresponding cells in lhs and rhs
        //      m_helper carry the same cell information (exact same copy)
        for (int i = 0; i <rhs.m_helperSize; i++){
            result = result && (lhs.m_helper[i] == rhs.m_helper[i]);
        }
        // we expect that the corresponding cells in lhs and rhs
        //      m_trackRows carry the same cell information (exact same copy)
        for (int i=0 ; i <rhs.m_numRows; i++){
            result = result && (lhs.m_trackRows[i] == rhs.m_trackRows[i]);
        }
        // we expect that the corresponding cells in lhs and rhs
        //      m_trackCols carry the same cell information (exact same copy)
        for (int i=0; i<rhs.m_numCols; i++){
            result = result && (lhs.m_trackCols[i] == rhs.m_trackCols[i]);
        }
        result = result && (lhs.m_minBallVal == rhs.m_minBallVal);
        result = result && (lhs.m_maxBallVal == rhs.m_maxBallVal);

        // makes sure that the memory addresses are different for everything to make sure we have two distinct objects
        if (&lhs == &rhs){
            result = false;
        }
        if (&lhs.m_card == &rhs.m_card){
            result = false;
        }
        if (&lhs.m_helper == &rhs.m_helper){
            result = false;
        }
        if (&lhs.m_trackRows == &rhs.m_trackRows){

        }
        if (&lhs.m_trackCols == &rhs.m_trackCols){
            result = false;
        }


        return result;
    }
    
    bool drawBallsEdge(Bingo & obj) {
        bool result = true;
        // if draw balls is performed on empty object, should only be one ball of value 0
        vector<int> balls = obj.drawBalls();
        if (balls.size() != 1 || balls.at(0) != 0){
            result = false; 
        }
        return result; 
    }

    bool drawBallsNormal(Bingo & obj) {
        bool result = true;
        vector<int> balls = obj.drawBalls();

        // make sure that vector size is right
        if (balls.size() != BALLS) {
            result = false;
        }

        // make sure that entries are correct
        for (int ball : balls) {
            if (ball < obj.m_minBallVal || ball > obj.m_maxBallVal) {
                result = false;
            }
        }
        return result; 
    }

    bool clearEdge(Bingo & obj) {
        bool result = true;
        obj.clear();
        // We expect the object is empty (invalid parameters should result in an empty object)
        if (obj.m_numRows != 0 || obj.m_numCols != 0 || obj.m_minBallVal != 0 || obj.m_maxBallVal != 0 || obj.m_helperSize != 0) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols != nullptr || obj.m_trackRows != nullptr || obj.m_helper != nullptr || obj.m_card != nullptr) {
            result = false;
        }

        return result; 
    }

    bool clearNormal(Bingo & obj) {
        bool result = true;
        obj.clear();

        // We expect the object is empty (invalid parameters should result in an empty object)
        if (obj.m_numRows != 0 || obj.m_numCols != 0 || obj.m_minBallVal != 0 || obj.m_maxBallVal != 0 || obj.m_helperSize != 0) {
            result = false;
        }

        // Add tests for other member variables
        if (obj.m_trackCols != nullptr || obj.m_trackRows != nullptr || obj.m_helper != nullptr || obj.m_card != nullptr) {
            result = false;
        }

        return result; 
    }
    private:
    
    /**********************************************
    * If we need helper functions to be reused in *
    *   test functions they can be declared here!
    **********************************************/
};
int main(){
    Tester tester;
    // Initializing with invalid pararmeters should result in a empty object
    cout << "Testing with invalid parameters for the constructor for an error case:" << endl; 
    Bingo obj1(-5,-10, MINVAL, MAXVAL);
    if (tester.constructorError(obj1)){
        cout << "Success: Constructor successfully created an empty object given invalid parameters" << endl;
    }
    else{
        cout << "Failure: Constructor failed to create an empty object given invalid parameters" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // Initializing with lowest row parameter should work
    cout << "Testing with min parameters for the constructor for an edge case:" << endl; 
    Bingo obj3(2, 5, MINVAL, MAXVAL);
    if (tester.constructorEdge(obj3)){
        cout << "Success: Constructor successfully created a correct object given valid min parameters" << endl;
    }
    else{
        cout << "Failure: Constructor failed to create a correct object given valid min parameters" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // Initializing with greatest row parameter should work
    cout << "Testing with max parameters for the constructor for an edge case:" << endl; 
    Bingo obj4(15, 5, MINVAL, MAXVAL);
    if (tester.constructorEdge2(obj4)){
        cout << "Success: Constructor successfully created a correct object given valid max parameters" << endl;
    }
    else{
        cout << "Failure: Constructor failed to create a correct object given valid max parameters" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // Initializing with valid parameters should work
    cout << "Testing with valid parameters for the constructor for an normal case:" << endl; 
    Bingo obj2(10, 5, MINVAL, MAXVAL);
    if (tester.constructorNormal(obj2)){
        cout << "Success: Constructor successfully created a correct object given valid parameters" << endl;
    }
    else{
        cout << "Failure: Constructor failed to create a correct object given valid parameters" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // Using invalid parameters for reCreateCard after using clear should result in an empty object
    cout << "Testing with invalid parameters for reCreateCard for an error case:" << endl; 
    obj1.clear();
    if (tester.reCreateError(obj1)){
        cout << "Success: reCreateCard successfully results in an empty object given invalid parameters" << endl;
    }
    else{
        cout << "Failure: reCreateCard failed to result in an empty object given invalid parameters" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // When clear is not called, reCreateCard should not do anything
    cout << "Testing with calling reCreateCard without clear for an error case:" << endl; 
    
    if (tester.reCreateError2(obj2)){
        cout << "Success: reCreateCard successfully did nothing when clear was not called" << endl;
    }
    else{
        cout << "Failure: reCreateCard failed to do nothing when clear was not called" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // When called on min parameters, reCreateCard should work
    cout << "Testing with calling reCreateCard with min parameters for an edge case:" << endl; 
    obj1.clear();
    if (tester.reCreateEdge(obj1)){
        cout << "Success: reCreateCard successfully created an object with min parameters" << endl;
    }
    else{
        cout << "Failure: reCreateCard failed to create an object with min parameters" << endl;
    }

    cout << "________________________________________________________" << endl; 
    // When called on max parameters, reCreateCard should work
    cout << "Testing with calling reCreateCard with max parameters for an edge case:" << endl; 
    obj1.clear();
    if (tester.reCreateEdge2(obj1)){
        cout << "Success: reCreateCard successfully created an object with max parameters" << endl;
    }
    else{
        cout << "Failure: reCreateCard failed to create an object with max parameters" << endl;
    }
    
    cout << "________________________________________________________" << endl; 
    // When called on normal parameters, reCreateCard should work
    cout << "Testing with valid parameters for reCreateCard for normal case:" << endl; 
    obj1.clear();
    if (tester.reCreateNormal(obj1)){
        cout << "Success: reCreateCard successfully created a correct object given valid parameters" << endl;
    }
    else{
        cout << "Failure: reCreateCard failed to create a correct object given valid parameters" << endl;
    }

    cout << "________________________________________________________" << endl;
    // When not initailzied, initCard should not work 
    cout << "Testing with invalid parameters for initCard for an error case:" << endl;
    obj1.clear();
    if (tester.initCardError(obj1)){
        cout << "Success: if initCard is called on an empty object, the object will stay an empty object after the call." << endl;
    }
    else{
        cout << "Failure: if initCard is called on an empty object, the object will not stay an empty object after the call." << endl;
    }

    cout << "________________________________________________________" << endl; 
    // When called on normal parameters, initCard should function as expected
    cout << "Testing with valid parameters for initCard for an normal case:" << endl;
    obj1.clear();
    obj1.reCreateCard(5,5,MINVAL,MAXVAL);
    if (tester.initCardNormal(obj1)){
        cout << "Success: if initCard is called, the object's card entries are valid" << endl;
    }
    else{
        cout << "Failure: if initCard is called, the object's card entries are invalid" << endl;
    }
    

    cout << "________________________________________________________" << endl; 
    cout << "Testing with invalid parameters for play for an error case:" << endl;
    // When invalid parameters and given, an error returning -1 is expected
    if (tester.playError(obj1)){
        cout << "Success: if play is called with invalid parameters, this leads to an error returning -1" << endl;
    }
    else{
        cout << "Failure: if play is called with invalid parameters, the error case is not properly handeled" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing with minimal draw parameters for play for an edge case:" << endl;
    // with minimal draw parameters are given, the game should run as expected
    if (tester.playEdge(obj1)){
        cout << "Success: if play is called with minimal draw parameters, this leads to an expected game" << endl;
    }
    else{
        cout << "Failure: if play is called with minimal draw parameters, the edge case is not properly handeled" << endl;
    }

    obj1.clear();
    obj1.reCreateCard(5,5,MINVAL,MAXVAL);
    
    cout << "________________________________________________________" << endl; 
    cout << "Testing with max draw parameters for play for an edge case:" << endl;
    // with minimal draw parameters are given, the game should run as expected
    if (tester.playEdge2(obj1)){
        cout << "Success: if play is called with max draw parameters, this leads to an expected game" << endl;
    }
    else{
        cout << "Failure: if play is called with max draw parameters, the edge case is not properly handeled" << endl;
    }
    obj1.clear();
    obj1.reCreateCard(5,5,MINVAL,MAXVAL);
    
    cout << "________________________________________________________" << endl; 
    cout << "Testing with valid parameters for play for a normal case:" << endl;
    // when normal parameters are give, the game should run as expected. 
    if (tester.playNormal(obj1)){
        cout << "Success: if play is called with valid manually set parameters, this leads to a expected game" << endl;
    }
    else{
        cout << "Failure: if play is called with valid manually set parameters, this leads to a incorrect game" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing with assignment of an empty object to an object with regular data for an edge case:" << endl;
    // assigning an empty object to one with regular data should have both objects empty
    obj2.clear();
    obj1 = obj2; 

    if (tester.assignmentEdge(obj1)){
        cout << "Success: if an empty object is assigned to a object of regular data, both objects become empty" << endl;
    }
    else{
        cout << "Failure: if an empty object is assigned to a object of regular data, both objects don't become empty" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing with assignment of an regular object to an object with regular data for an normal case:" << endl;
    // assigning a regular object should make both objects have the same values but be distinct in memory
    obj1.reCreateCard(5,5,MINVAL,MAXVAL);
    obj2.reCreateCard(10,5,MINVAL,MAXVAL);
    obj1 = obj2; 
    if (tester.assignmentNormal(obj2,obj1)){
        cout << "Success: Assignment operator test for normal case passed!" << endl;
    }
    else{
        cout << "Failure: Assignment operator test for normal case failed!" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing drawBalls on an empty object for an edge case:" << endl;
    // drawing balls on an empty object should result in one ball of value 0 
    obj1.clear();
    if (tester.drawBallsEdge(obj1)){
        cout << "Success: if drawBalls is called on a empty object, the return vector has just a single entry of 0" << endl;
    }
    else{
        cout << "Failure: if drawBalls is called on a empty object, the return vector does not have a single entry of 0" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing drawBalls on an populated object for a normal case:" << endl;
    obj1.reCreateCard(5,5,MINVAL,MAXVAL);
    // drawing balls as expected should result in a typical vector of regular length
    if (tester.drawBallsNormal(obj1)){
        cout << "Success: if drawBalls is called on a normal object, the return vector is valid" << endl;
    }
    else{
        cout << "Failure: if drawBalls is called on a normal object, the return vector is not valid" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing clear on an empty object for a edge case:" << endl;
    obj1.clear();
    // clearing should reset the object to be empty
    if (tester.clearEdge(obj1)){
        cout << "Success: if clear is called on a empty object, the object will be empty" << endl;
    }
    else{
        cout << "Failure: if clear is called on a empty object, the object will not be empty" << endl;
    }

    cout << "________________________________________________________" << endl; 
    cout << "Testing clear on an populated object for a normal case:" << endl;
    obj1.reCreateCard(5,5,MINVAL,MAXVAL);
    // clearing should reset the object to be empty
    if (tester.clearNormal(obj1)){
        cout << "Success: if clear is called on a normal object, the object will be empty" << endl;
    }
    else{
        cout << "Failure: if clear is called on a normal object, the object will not be empty" << endl;
    }
    return 0;
}