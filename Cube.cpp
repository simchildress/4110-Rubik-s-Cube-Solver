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
          while (!isValidCube()) {
        cout << "\nWARNING! ERROR!\nCube input is invalid. Please re-enter all faces.\n";
        input(); //redo the cube
        return;
    }
}

bool Cube::isValidCube() {
    int colorCount[256] = {0}; // ASCII indexed

    for (int face = 0; face < NUM_FACES; ++face) {
        for (int row = 0; row < SIZE; ++row) {
            for (int col = 0; col < SIZE; ++col) {
                colorCount[(int)cube[face][row][col]]++;
            }
        }
    }

    // Expected colors
    char expectedColors[NUM_FACES] = {'y', 'w', 'b', 'g', 'r', 'o'};

    for (int i = 0; i < NUM_FACES; ++i) {
        if (colorCount[(int)expectedColors[i]] != 9) {
            cout << "Invalid cube: Color '" << expectedColors[i] << "' appears " 
                 << colorCount[(int)expectedColors[i]] << " times instead of 9.\n";
            return false;
        }
    }

    return true;
}

void Cube::print() const {
    string faceNames[NUM_FACES] = {"yellow", "white", "blue", "green", "red", "orange"}; // yellow (top) - white (bottom) - blue (front) - green (back) - red (left) - orange (right)

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
    /* 
    - Lets have the letters for the clockwise turns be: R (right face) | L (left face) | U (upper face/face on top) | D (down face/face on bottom) | F (front face) | B (back face)
    - Then the counter clockwise turns would be: R' | L' | U' | D' | F' | B' 
    - | yellow = 0 | white = 1 | blue = 2 | green = 3 | red = 4 | orange = 5 |
    - thinking we should have white always on the bottom and yellow on top, and then blue facing you
    */
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

    } else if (turn == "R'") { // rotate the right (orange) face counterclockwise
        // store the original orange face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cubeSaver[i][j] = cube[5][i][j]; // orange face
            }
        }
    
        // rotate the orange face 90 degrees counterclockwise
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cube[5][2 - j][i] = cubeSaver[i][j];
            }
        }
    
        // store the right column of the yellow face
        char storeYellowColumn[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            storeYellowColumn[i] = cube[0][i][2]; // yellow face, right column
        }
    
        // yellow (0) right column -> green (3) left column (reversed)
        for (int i = 0; i < SIZE; ++i) {
            cube[0][i][2] = cube[3][2 - i][0];
        }
    
        // green (3) left column (reversed) -> white (1) right column
        for (int i = 0; i < SIZE; ++i) {
            cube[3][2 - i][0] = cube[1][i][2];
        }
    
        // white (1) right column -> blue (2) right column
        for (int i = 0; i < SIZE; ++i) {
            cube[1][i][2] = cube[2][i][2];
        }
    
        // blue (2) right column -> yellow (0) right column
        for (int i = 0; i < SIZE; ++i) {
            cube[2][i][2] = storeYellowColumn[i];
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
        
        // blue (2) bottom row -> orange (5) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[2][2][i] = cube[4][2][i];
        }
        
        // orange (5) bottom row -> green (3) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[4][2][i] = cube[3][2][i];
        }
        
        // green (3) bottom row -> red (4) bottom row
        for (int i = 0; i < SIZE; ++i) {
            cube[3][2][i] = cube[5][2][i];
        }
        
        // red (4) bottom row -> blue (2) bottom row
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

        // blue -> red
        for (int i = 0; i < SIZE; ++i) {
            cube[2][2][i] = cube[5][2][i];
        }

        // red -> green
        for (int i = 0; i < SIZE; ++i) {
            cube[5][2][i] = cube[3][2][i];
        }

        // green -> orange
        for (int i = 0; i < SIZE; ++i) {
            cube[3][2][i] = cube[4][2][i];
        }

        // orange -> blue
        for (int i = 0; i < SIZE; ++i) {
            cube[4][2][i] = storeBlueRow[i];
        }
    }

    else if (turn == "F") { // rotate the front (blue) face clockwise
        // store original blue face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[2][i][j]; // blue face

        // rotate blue face clockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[2][j][2 - i] = cubeSaver[i][j];

        // store bottom row of yellow (top face)
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[0][2][i]; // yellow bottom row

        // yellow bottom row -> left column of orange (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[0][2][i] = cube[4][2 - i][2];

        // left column of red -> top row of white
        for (int i = 0; i < SIZE; ++i)
            cube[4][i][2] = cube[1][0][i];

        // white top row -> right column of orange (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[1][0][i] = cube[5][2 - i][0];

        // right column of orange -> yellow bottom row
        for (int i = 0; i < SIZE; ++i)
            cube[5][i][0] = temp[i];
    } 
    
    else if (turn == "F'") { // rotate the front (blue) face counterclockwise
        // store original blue face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[2][i][j]; // blue face

        // rotate blue face counterclockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[2][2 - j][i] = cubeSaver[i][j];

        // store bottom row of yellow (top face)
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[0][2][i]; // yellow bottom row

        // yellow bottom row -> right column of orange
        for (int i = 0; i < SIZE; ++i)
            cube[0][2][i] = cube[5][i][0];

        // right column of orange -> top row of white (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[5][2 - i][0] = cube[1][0][i];

        // white top row -> left column of red
        for (int i = 0; i < SIZE; ++i)
            cube[1][0][i] = cube[4][i][2];

        // left column of red -> yellow bottom row (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[4][2 - i][2] = temp[i];
    }

    else if (turn == "L") { // rotate the left (red) face clockwise
        // store the original red face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[4][i][j]; // red face

        // rotate red face clockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[4][j][2 - i] = cubeSaver[i][j];

        // store the left column of yellow face
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[0][i][0];

        // yellow left col -> back right col (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[0][i][0] = cube[3][2 - i][2];

        // back right col -> white left col
        for (int i = 0; i < SIZE; ++i)
            cube[3][2 - i][2] = cube[1][i][0];

        // white left col -> front left col
        for (int i = 0; i < SIZE; ++i)
            cube[1][i][0] = cube[2][i][0];

        // front left col -> yellow left col
        for (int i = 0; i < SIZE; ++i)
            cube[2][i][0] = temp[i];
    }

    else if (turn == "L'") { // rotate the left (red) face counterclockwise
        // store the original red face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[4][i][j]; // red face

        // rotate red face counterclockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[4][2 - j][i] = cubeSaver[i][j];

        // store the left column of yellow face
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[0][i][0];

        // yellow left col -> front left col
        for (int i = 0; i < SIZE; ++i)
            cube[0][i][0] = cube[2][i][0];

        // front left col -> white left col
        for (int i = 0; i < SIZE; ++i)
            cube[2][i][0] = cube[1][i][0];

        // white left col -> back right col (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[1][i][0] = cube[3][2 - i][2];

        // back right col -> yellow left col (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[3][2 - i][2] = temp[i];
    }
    else if (turn == "U") { // rotate the yellow (top) face clockwise
        // store yellow face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[0][i][j];
    
        // rotate yellow face clockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[0][j][2 - i] = cubeSaver[i][j];
    
        // store top row of blue
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[2][0][i];
    
        // blue top row -> red top row
        for (int i = 0; i < SIZE; ++i)
            cube[2][0][i] = cube[5][0][i];
    
        // orange -> green
        for (int i = 0; i < SIZE; ++i)
            cube[5][0][i] = cube[3][0][i];
    
        // green -> red
        for (int i = 0; i < SIZE; ++i)
            cube[3][0][i] = cube[4][0][i];
    
        // red -> blue
        for (int i = 0; i < SIZE; ++i)
            cube[4][0][i] = temp[i];
    }
    
    else if (turn == "U'") { // rotate the yellow (top) face counterclockwise
        // store yellow face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[0][i][j];
    
        // rotate yellow face counterclockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[0][2 - j][i] = cubeSaver[i][j];
    
        // store top row of blue
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[2][0][i];
    
        // blue -> red
        for (int i = 0; i < SIZE; ++i)
            cube[2][0][i] = cube[4][0][i];
    
        // red -> green
        for (int i = 0; i < SIZE; ++i)
            cube[4][0][i] = cube[3][0][i];
    
        // green -> orange
        for (int i = 0; i < SIZE; ++i)
            cube[3][0][i] = cube[5][0][i];
    
        // orange -> blue
        for (int i = 0; i < SIZE; ++i)
            cube[5][0][i] = temp[i];
    }
    
    else if (turn == "B") { // rotate the back (green) face clockwise
        // store green face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[3][i][j];
    
        // rotate green face clockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[3][j][2 - i] = cubeSaver[i][j];
    
        // store top row of yellow
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[0][0][i];
    
        // yellow top -> right col of red (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[0][0][i] = cube[5][i][2];
    
        // right col of orange -> bottom row of white
        for (int i = 0; i < SIZE; ++i)
            cube[5][i][2] = cube[1][2][2 - i];
    
        // white bottom -> left col of red (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[1][2][i] = cube[4][i][0];
    
        // left col of red -> yellow top row
        for (int i = 0; i < SIZE; ++i)
            cube[4][i][0] = temp[2 - i];
    }
    
    else if (turn == "B'") { // rotate the back (green) face counterclockwise
        // store green face
        char cubeSaver[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cubeSaver[i][j] = cube[3][i][j];
    
        // rotate green face counterclockwise
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cube[3][2 - j][i] = cubeSaver[i][j];
    
        // store top row of yellow
        char temp[SIZE];
        for (int i = 0; i < SIZE; ++i)
            temp[i] = cube[0][0][i];
    
        // yellow -> left col of red (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[0][0][i] = cube[4][2 - i][0];
    
        // left col of red -> white bottom
        for (int i = 0; i < SIZE; ++i)
            cube[4][i][0] = cube[1][2][i];
    
        // white bottom -> right col of orange (reversed)
        for (int i = 0; i < SIZE; ++i)
            cube[1][2][2 - i] = cube[5][i][2];
    
        // right col of orange -> yellow top
        for (int i = 0; i < SIZE; ++i)
            cube[5][i][2] = temp[i];
    }
}
