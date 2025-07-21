#include <iostream>
#include <string>
#include "Cube.h"

using namespace std;

void Cube::input() {
    string faceNames[NUM_FACES] = {"yellow", "white", "blue", "green", "red", "orange"}; // yellow (top) - white (bottom) - blue (front) - green (back) - red (left) - orange (right)
    char middleColor[NUM_FACES] = {'y', 'w', 'b', 'g', 'r', 'o'};

    cout << "Enter Your Rubik's Cube: \n";
    for (int face = 0; face < NUM_FACES; ++face) {
        cout << "\nEnter your colors for the " << faceNames[face] << " face (use 9 letters with spaces, e.g., 'yyywwwbbb')\n*Your middle color needs to be the same as the face color*: \n";

        string input;
        while(true) {
            cout << faceNames[face] << " face: ";
            cin >> input;

            if (input.length() == 9) {
                int charIndex = 0;
                for (int row = 0; row < SIZE; ++row) {
                    for (int col = 0; col < SIZE; ++col) {
                        cube[face][row][col] = input[charIndex++];
                    }
                }
                
                if (cube[face][1][1] != middleColor[face]) {
                    cout << "\nError: Center of " << faceNames[face] << " face must be '" << middleColor[face] << "'. Try again.\n";
                } else {
                    break;
                }
            } 
            else {
                cout << "Please enter 9 characters only per face." << endl;
            }
        }
    }
}

void Cube::print() const {
    string faceNames[NUM_FACES] = {"yellow", "white", "blue", "green", "red", "orange"}; // yellow (top) - white (bottom) - blue (front) - green (back) - red (left) - orange (right)

    cout << "Here is your original cube:\n\n";
    for (int face = 0; face < NUM_FACES; ++face) {
        cout << faceNames[face] << " face:\n";
        for (int row = 0; row < SIZE; ++row) {
            for (int col = 0; col < SIZE; ++col) {
                cout << cube[face][row][col];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Cube::move(string turn) {
    // yellow = 0 | white = 1 | blue = 2 | green = 3 | red = 4 | orange = 5 |
    /* thinking we should have white always on the bottom and yellow on top, and then blue facing you */
    if(turn == "R") { //rotate the right (orange) face clockwise
        // store the original orange face
        char cubeSaver[SIZE][SIZE];
        for(int i = 0; i < SIZE; ++i ) {
            for(int j = 0; j < SIZE; ++j ){
                cubeSaver[i][j] = cube[5][i][j]; // Orange face
            }
        }

        // rotate the orange face 90 degrees clockwise
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                cube[5][j][2 - i] = cubeSaver[i][j];
            }
        }

        // store the right column of the yellow face
        char storeYellowColumn[SIZE]; 
        for (int i = 0; i < SIZE; ++i) {
            storeYellowColumn[i] = cube[0][i][2]; // Yellow face, right column
        }

        // yellow (0) right column -> blue (2) right column
        for (int i = 0; i < SIZE; ++i) {
            cube[0][i][2] = cube[2][i][2];
        }
        
        // blue (2) right column -> white (1) right column
        for (int i = 0; i < SIZE; ++i) {
            cube[2][i][2] = cube[1][i][2];
        }

        // white (1) right column -> green (3) left column (reversed)
        for (int i = 0; i < SIZE; ++i) {
            cube[1][i][2] = cube[3][2 - i][0];
        }

        // green (3) left column (reversed) -> yellow (0) right column
        for (int i = 0; i < SIZE; ++i) {
            cube[3][2 - i][0] = storeYellowColumn[i];
        }

    } else if (turn == "D") { // rotate the white (bottom) face clockwise
        // store the original white face
        char cubeSaver[SIZE][SIZE];
        for(int i = 0; i < SIZE; ++i ) {
            for(int j = 0; j < SIZE; ++j ){
                cubeSaver[i][j] = cube[1][i][j]; // white face
            }
        }

        // rotate the white face 90 degrees clockwise
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                cube[1][j][2 - i] = cubeSaver[i][j];
            }
        }
        
        // store the bottom row of the blue face
        char storeBlueRow[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            storeBlueRow[i] = cube[2][2][i]; // blue face, bottom row
        }
        
        // blue -> red
        for (int i = 0; i < SIZE; ++i) {
            cube[2][2][i] = cube[4][2][i];
        }
        
        // red -> green
        for (int i = 0; i < SIZE; ++i) {
            cube[4][2][i] = cube[3][2][i];
        }
        
        // green -> orange
        for (int i = 0; i < SIZE; ++i) {
            cube[3][2][i] = cube[5][2][i];
        }
        
        // orange -> blue
        for (int i = 0; i < SIZE; ++i) {
            cube[5][2][i] = storeBlueRow[i];
        }

    } else if (turn == "D'") { // rotate the white (bottom) face counter clockwise
        // store the original white face
        char cubeSaver[SIZE][SIZE];
        for(int i = 0; i < SIZE; ++i ) {
            for(int j = 0; j < SIZE; ++j ){
                cubeSaver[i][j] = cube[1][i][j]; // white face
            }
        }

        // rotate the white face 90 degrees counter clockwise
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
            cube[1][2 - j][i] = cubeSaver[i][j];
            }
        }

        // store the bottom row of the blue face
        char storeBlueRow[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            storeBlueRow[i] = cube[2][2][i]; // blue face, bottom row
        }

        // blue (2) bottom row -> orange (5) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[2][2][i] = cube[5][2][i];
        }

        // orange (5) bottom row -> green (3) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[5][2][i] = cube[3][2][i];
        }

        // green (3) bottom row -> red (4) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[3][2][i] = cube[4][2][i];
        }

        // red (4) bottom row -> blue (2) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[4][2][i] = storeBlueRow[i];
        }
    }
