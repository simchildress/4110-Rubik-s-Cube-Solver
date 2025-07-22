/*
#include "Solver.h"

void Solver::whiteEdgesToTop(Cube& cube) {
    bool moved;

    do {
        moved = false;

        for (int face = 0; face < Cube::NUM_FACES; ++face) {
            for (int row = 0; row < Cube::SIZE; ++row) {
                for (int col = 0; col < Cube::SIZE; ++col) {
                    bool isEdge = (row == 1 && col != 1) || (col == 1 && row != 1);
                    if (!isEdge) { continue; }

                    if (cube.getColor(face, row, col) != 'w') { continue; }
                    if (face == 0) { continue; } // already on yellow face

                    // Skip if yellow face already has a white at the target spot
                    if (face == 2 && cube.getColor(0, 2, 1) == 'w') { continue; }
                    if (face == 3 && cube.getColor(0, 0, 1) == 'w') { continue; }
                    if (face == 4 && cube.getColor(0, 1, 0) == 'w') { continue; }
                    if (face == 5 && cube.getColor(0, 1, 2) == 'w') { continue; }
                    if (face == 1) { continue; } // skip white face (bottom) for now

                    // Move edge to top
                    if (face == 2 && row == 2 && col == 1) {
                        cube.move("F");
                        moved = true;
                        break;
                    }
                    if (face == 2 && row == 0 && col == 1) {
                        cube.move("F'");
                        moved = true;
                        break;
                    }
                    if (face == 3 && row == 2 && col == 1) {
                        cube.move("B");
                        moved = true;
                        break;
                    }
                    if (face == 3 && row == 0 && col == 1) {
                        cube.move("B'");
                        moved = true;
                        break;
                    }
                    if (face == 4 && row == 2 && col == 1) {
                        cube.move("L");
                        moved = true;
                        break;
                    }
                    if (face == 4 && row == 0 && col == 1) {
                        cube.move("L'");
                        moved = true;
                        break;
                    }
                    if (face == 5 && row == 2 && col == 1) {
                        cube.move("R");
                        moved = true;
                        break;
                    }
                    if (face == 5 && row == 0 && col == 1) {
                        cube.move("R'");
                        moved = true;
                        break;
                    }
                }
                if (moved) break;
            }
            if (moved) break;
        }
    } while (moved);
}
*/
