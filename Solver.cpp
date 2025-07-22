#include "Solver.h"
#include "Cube.h"
#include <iostream>
using namespace std;

void Solver::whiteEdgesToTop(Cube& cube) {
    bool moved;

    do {
        moved = false;

        for (int face = 0; face < Cube::NUM_FACES; ++face) {
            for (int row = 0; row < Cube::SIZE; ++row) {
                for (int col = 0; col < Cube::SIZE; ++col) {
                    bool isEdge = (row == 1 && col != 1) || (col == 1 && row != 1);
                    if (!isEdge) {
                        continue;
                    }

                    if (cube.getColor(face, row, col) != 'w') {
                        continue;
                    }

                    if (face == 0) {
                        continue;
                    }
                    
                    // determine where this white edge should go on the yellow face
                    string targetPos = "";
                    if (face == 2 && row == 2 && col == 1) {
                        targetPos = "021"; // from blue bottom edge to yellow bottom edge
                    } else if (face == 3 && row == 0 && col == 1) {
                        targetPos = "001"; // from green top edge to yellow top edge
                    } else if (face == 4 && row == 1 && col == 0) {
                        targetPos = "010"; // from red left edge to yellow left edge
                    } else if (face == 5 && row == 1 && col == 2) {
                        targetPos = "012"; // from orange right edge to yellow right edge
                    } else if (face == 1) {
                        if (row == 0 && col == 1) {
                            targetPos = "021"; // white top edge goes to yellow bottom
                        }
                        if (row == 2 && col == 1) {
                            targetPos = "001"; // white bottom edge goes to yellow top
                        }
                        if (row == 1 && col == 0) {
                            targetPos = "010"; // white left edge goes to yellow left
                        }
                        if (row == 1 && col == 2) {
                            targetPos = "012"; // white right edge goes to yellow right
                        }
                    }
                  
                    // if the target yellow edge is already white, rotate U face until it's not
                    while (targetPos != "" && cube.getColor(0, targetPos[0]-'0', targetPos[2]-'0') == 'w') {
                        cube.move("U");
                    }
                    //white face
                    if (face == 1) {
                        if (row == 0 && col == 1) {
                            cube.move("F");
                            cube.move("F");
                            cube.move("U");
                        } else if (row == 2 && col == 1) {
                            cube.move("B");
                            cube.move("B");
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cube.move("L");
                            cube.move("L");
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cube.move("R");
                            cube.move("R");
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //blue face
                    if (face == 2) {
                        if (row == 2 && col == 1) {
                            cube.move("F");
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cube.move("F'");
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cube.move("L'");
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cube.move("R");
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //green face
                    if (face == 3) {
                        if (row == 2 && col == 1) {
                            cube.move("B");
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cube.move("B'");
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cube.move("R'");
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cube.move("L");
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //red face
                    if (face == 4) {
                        if (row == 2 && col == 1) {
                            cube.move("L");
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cube.move("L'");
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cube.move("B'");
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cube.move("F");
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //orange face
                    if (face == 5) {
                        if (row == 2 && col == 1) {
                            cube.move("R");
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cube.move("R'");
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cube.move("F'");
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cube.move("B");
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                }
                if (moved) {
                    break;
                }
            }
            if (moved) {
                break;
            }
        }
    } while (moved);
}

void Solver::whiteEdgesToBottom(Cube& cube) {}
    
