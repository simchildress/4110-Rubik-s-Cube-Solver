#include <iostream>
#include <string>
#include "Cube.h"

using namespace std;


int main() {

Cube myCube;


//makes cube from user input
    myCube.input();

    cout << "Here is your original cube:\n\n";  
//prints the cube they inputed  
    myCube.print();

    cout << "Here is your new cube:\n\n";
//Turns Cube then prints (test)
    myCube.move("D");
    myCube.print();

    cout << endl;

    return 0;
}
