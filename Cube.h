#ifndef CUBE_H
#define CUBE_H

#include <string>

class Cube {
    public:
        static const int SIZE = 3;
        static const int NUM_FACES = 6;

        void input();
        void print() const; //read only


    private:
        char cube[NUM_FACES][SIZE][SIZE]; //face color - row - collumn
};

#endif