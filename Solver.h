#ifndef SOLVER_H
#define SOLVER_H

#include "Cube.h"


class Solver {
public:
    void whiteEdgesToTop(Cube& cube);
    bool isWhiteCross(Cube& cube);
    void whiteEdgesToBottom(Cube& cube);
    void whiteCornerSolver(Cube& cube);
};

#endif
