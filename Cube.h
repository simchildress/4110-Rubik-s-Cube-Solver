#ifndef CUBE_H
#define CUBE_H

#include <string>

using namespace std;

class Cube {
    public:
        static const int SIZE = 3;
        static const int NUM_FACES = 6;

        void input();
        void print() const; //read only
        void move(string turn);//turns the cube
        bool isValidCube();//checks if characters show 9 times for each face color


    private:
        char cube[NUM_FACES][SIZE][SIZE]; //face color - row - collumn
};

#endif
