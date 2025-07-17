#include <iostream>
#include "Cube.h"

using namespace std;


void Cube::input() {

    string faceNames[NUM_FACES] = {"yellow", "white", "blue", "green", "red", "orange"}; // yellow (top) - white (bottom) - blue (front) - green (back) - red (left) - orange (right)

    cout << "Enter Your Rubik's Cube: \n";
    for (int face = 0; face < NUM_FACES; ++face) {
    cout << "\nEnter your colors for the " << faceNames[face] << " face (use 3 letters without spaces per row)\n*Your middle color needs to be the same as the face color*: \n";

    for (int row = 0; row < SIZE; ++row) {
        string input;
        while(true) {
            cout << "Row " << row + 1 << ": ";
            cin >> input;

            if (input.length() == 3) {
                for (int col = 0; col < SIZE; ++col) {
                    cube[face][row][col] = input[col];
                }
                break;
            } 
            else {
                cout << "Please enter 3 characters only per row." << endl;
            }
        }
    }
}

}

void Cube::print() const{

    string faceNames[NUM_FACES] = {"yellow", "white", "blue", "green", "red", "orange"}; // yellow (top) - white (bottom) - blue (front) - green (back) - red (left) - orange (right)

    cout << "Here is your unsolved cube:\n\n";
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
    if(turn == "R") { //rotate the right face
        //with blue in front, the orange face rotates
        char cubeSaver[SIZE][SIZE];
        for(int i = 0; i < SIZE; ++i ) {
            for(int j = 0; j < SIZE; ++j ){
                cubeSaver[i][j] = cube[5][i][j];
                
            }
        }
/*
        
        abc
        def
        ghi

        gda
        heb
        ifc

        taking the row and putting it into column

*/

        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                cube[5][j][2 - i] = cubeSaver[i][j];
            }
        }

        char storeColumn[SIZE]; // store data for yellow
        for (int i = 0; i < SIZE; ++i) {
            storeColumn[i] = cube[0][i][2];
        }

        //yellow to blue
        for (int i = 0; i < SIZE; ++i) {
            cube[0][i][2] = cube[3][2 - i][0];
        }
    }


/*
    
blue (front)
adjacent to: yellow, white, red, orange

green (back)
adjacent to: yellow, white, red, orange

yellow (top)
adjacent to: blue, green, red, orange

white (bottom)
adjacent to: blue, green, red, orange

red (left)
adjacent to: yellow, white, blue, green

orange (right)
adjacent to: yellow, white, blue, green

    */

}