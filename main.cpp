#include <iostream>
#include <string>
#include "Cube.h"
#include "Solver.h"

using namespace std;


int main() {

Cube myCube;


//makes cube from user input
    myCube.input();
    
    cout << "Validating Cube.....\n\n";
    
    cout << "Your Cube is Valid\n\n"; 
    //input will continously run until the cube is valid. So if we see the above cout then we know the cube is valid)
    
    
    cout << "Here is your original cube:\n\n";    
//prints the cube they inputed  
    myCube.print();


    cout << "Bringing White Edges to the Top:\n\n";
//Turns Cube then prints (test)
    Solver solver; // Create Solver
    solver.whiteEdgesToTop(myCube); 
    cout << "Bringing White Edges to the white face:\n\n";
    myCube.print();
    solver.whiteEdgesToBottom(myCube);
    myCube.print();
    cout << "White cross solved. Solving white face Corners:\n\n";
    solver.whiteCornerSolver(myCube);
    myCube.print();

/*
    myCube.move("U");
    myCube.print();
*/

    cout << "Here is your partially solved cube:\n\n";
    myCube.print();
    
    cout << endl;

    return 0;
}
