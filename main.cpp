#include <iostream>
#include <string>
#include "Cube.h"

using namespace std;


int main() {

Cube myCube;


//makes cube from user input
    myCube.input();
    
/*
char turn = "R";
myCube.move();

cout << "Turning the right face of your cube (orange face)\n";

*/
    //before move
    myCube.print();
    cout<<endl;
    //after move
    myCube.move
//prints the cube they inputed    
    myCube.print();

    cout << endl;

    return 0;
}
