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