#include <iostream>
#include <string>
#include "Cube.h"

using namespace std;


int main() {

Cube myCube;


//makes cube from user input
    myCube.input();
    
//prints the cube they inputed  
    myCube.print();

//Turns Cube then prints (test)
    myCube.move("D");
    myCube.print();

    cout << endl;

    return 0;
}
