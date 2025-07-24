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
                        cout << "Turning yellow face" << endl;
                        cube.move("U");
                    }
                    //white face
                    if (face == 1) {
                        if (row == 0 && col == 1) {
                            cout << "Turning green face" << endl;
                            cube.move("F");
                            cout << "Turning green face" << endl;
                            cube.move("F");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 2 && col == 1) {
                            cout << "Turning blue face" << endl;
                            cube.move("B");
                            cout << "Turning blue face" << endl;
                            cube.move("B");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cout << "Turning orange face" << endl;
                            cube.move("L");
                            cout << "Turning orange face" << endl;
                            cube.move("L");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cout << "Turning red face" << endl;
                            cube.move("R");
                            cout << "Turning red face" << endl;
                            cube.move("R");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //blue face
                    if (face == 2) {
                        if (row == 2 && col == 1) {
                            cout << "Turning green face" << endl;
                            cube.move("F");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cout << "Turning green face" << endl;
                            cube.move("F'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cout << "Turning orange face" << endl;
                            cube.move("L'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cout << "Turning red face" << endl;
                            cube.move("R");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //green face
                    if (face == 3) {
                        if (row == 2 && col == 1) {
                            cout << "Turning blue face" << endl;
                            cube.move("B");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cout << "Turning blue face" << endl;
                            cube.move("B'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cout << "Turning red face" << endl;
                            cube.move("R'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cout << "Turning orange face" << endl;
                            cube.move("L");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //red face
                    if (face == 4) {
                        if (row == 2 && col == 1) {
                            cout << "Turning orange face" << endl;
                            cube.move("L");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cout << "Turning orange face" << endl;
                            cube.move("L'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cout << "Turning blue face" << endl;
                            cube.move("B'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cout << "Turning green face" << endl;
                            cube.move("F");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        }
                        moved = true;
                        break;
                    }
                    //orange face
                    if (face == 5) {
                        if (row == 2 && col == 1) {
                            cout << "Turning red face" << endl;
                            cube.move("R");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 0 && col == 1) {
                            cout << "Turning red face" << endl;
                            cube.move("R'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 0) {
                            cout << "Turning green face" << endl;
                            cube.move("F'");
                            cout << "Turning yellow face" << endl;
                            cube.move("U");
                        } else if (row == 1 && col == 2) {
                            cout << "Turning blue face" << endl;
                            cube.move("B");
                            cout << "Turning yellow face" << endl;
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

void Solver::whiteEdgesToBottom(Cube& cube) {
    
    cout << "Moving edges to white face\n";
    cube.move("F");
    cube.move("F");
    cube.move("B");
    cube.move("B");
    cube.move("R");
    cube.move("R");
    cube.move("L");
    cube.move("L");

    }
    
/*
thoughts for the conrer pieces:(bottom layer)
- 1. we will check the corner pieces on the bottom layer first
- 2. check if the corner piece has a white character on the bottom, if it doesn't move to step 4
- 3. if the adjacent colors match the face they are in leave them be
- 4. if the adjacent colors do not match the face they are in then we will do a face turn for the column its in, 
  then a U turn, then counter clockwise for the column its in, then U' to bring the corner piece up
- 5. after we will turn the top layer till the adjacent colors match 
- 6. then we will do the same algorithm as before and loop (a face turn for the column its in, 
  then a U turn, then counter clockwise for the column its in, then U') until the white is on bottom

Corner pieces part 2: (bottom layer)
- 1. we will check the corner pieces on the top layer
- 2. loop until the adjacent colors of the selected corner peice match the adjacent faces
- 3. then da this loop again until the white character is on the bottom (a face turn for the column its in, 
  then a U turn, then counter clockwise for the column its in, then U')
  
  we just loop through those until all of the white characters are on the bottom then the loop ends
  

void Solver::whiteCornerSolver(Cube& cube) {
    int attempts = 0;
    const int maxAttempts = 150;
    bool moved;

    // updated to match actual cube orientation
    struct Corner {
        int f1, r1, c1; // one facelet
        int f2, r2, c2; // second facelet
        int f3, r3, c3; // third facelet
    };

    // bottom layer corners (white face = 1)
    Corner bottomCorners[4] = {
        {1, 0, 0, 2, 2, 0, 4, 2, 2}, // front-left
        {1, 0, 2, 2, 2, 2, 5, 2, 0}, // front-right
        {1, 2, 0, 3, 0, 2, 4, 2, 0}, // back-left
        {1, 2, 2, 3, 0, 0, 5, 2, 2}  // back-right
    };

    // top layer corners (yellow face = 0)
    Corner topCorners[4] = {
        {0, 2, 0, 2, 0, 0, 4, 0, 2}, // front-left
        {0, 2, 2, 2, 0, 2, 5, 0, 0}, // front-right
        {0, 0, 0, 3, 2, 2, 4, 0, 0}, // back-left
        {0, 0, 2, 3, 2, 0, 5, 0, 2}  // back-right
    };

    do {
        moved = false;

        // Step 1: check bottom corners
        for (Corner& c : bottomCorners) {
            char cw = cube.getColor(c.f1, c.r1, c.c1);
            if (cw != 'w') continue;

            char a1 = cube.getColor(c.f2, c.r2, c.c2);
            char a2 = cube.getColor(c.f3, c.r3, c.c3);
            char c1 = cube.getColor(c.f2, 1, 1);
            char c2 = cube.getColor(c.f3, 1, 1);

            if (a1 != c1 || a2 != c2) {
                // pop corner to top layer
                cube.move("R");
                cube.move("U");
                cube.move("R'");
                cube.move("U'");
                moved = true;
                break;
            }
        }

        if (moved) {
            attempts++;
            continue;
        }

        // Step 2: insert one corner from top layer
        for (Corner& c : topCorners) {
            char c1 = cube.getColor(c.f1, c.r1, c.c1);
            char c2 = cube.getColor(c.f2, c.r2, c.c2);
            char c3 = cube.getColor(c.f3, c.r3, c.c3);
            if (c1 != 'w' && c2 != 'w' && c3 != 'w') continue;

            // rotate U until adjacent faces align with centers
            for (int i = 0; i < 4; ++i) {
                char a1 = cube.getColor(c.f2, c.r2, c.c2);
                char a2 = cube.getColor(c.f3, c.r3, c.c3);
                char ctr1 = cube.getColor(c.f2, 1, 1);
                char ctr2 = cube.getColor(c.f3, 1, 1);
                if (a1 == ctr1 && a2 == ctr2) break;
                cube.move("U");
            }

            // determine insertion direction
            bool insertLeft = (c.f3 == 4); // red on left
            bool insertRight = (c.f3 == 5); // orange on right

            if (insertLeft) {
                cube.move("L'");
                cube.move("U'");
                cube.move("L");
            } else if (insertRight) {
                cube.move("R");
                cube.move("U");
                cube.move("R'");
            } else {
                // fallback — treat it as right insert
                cube.move("R");
                cube.move("U");
                cube.move("R'");
            }

            moved = true;
            break;
        }

        attempts++;
    } while (moved && attempts < maxAttempts);

    if (attempts == maxAttempts) {
        cout << "Warning: whiteCornerSolver hit max attempts.\n";
    } else {
        cout << "White corners solved successfully.\n";
    }
}
*/
void Solver::whiteCornerSolver(Cube& cube) {
    struct Corner {
        int f1, r1, c1; // white sticker
        int f2, r2, c2; // first adjacent color
        int f3, r3, c3; // second adjacent color
    };

    Corner bottomCorners[4] = {
        {1, 0, 0, 2, 2, 0, 4, 2, 2}, // front-left
        {1, 0, 2, 2, 2, 2, 5, 2, 0}, // front-right
        {1, 2, 0, 3, 0, 2, 4, 2, 0}, // back-left
        {1, 2, 2, 3, 0, 0, 5, 2, 2}  // back-right
    };

    Corner topCorners[4] = {
        {0, 2, 0, 2, 0, 0, 4, 0, 2}, // front-left
        {0, 2, 2, 2, 0, 2, 5, 0, 0}, // front-right
        {0, 0, 0, 3, 2, 2, 4, 0, 0}, // back-left
        {0, 0, 2, 3, 2, 0, 5, 0, 2}  // back-right
    };

    int attempts = 0;
    const int maxAttempts = 150;
    bool moved;

    do {
        moved = false;

        // Step 1: pop misaligned white corners from bottom
        for (Corner& c : bottomCorners) {
            char white = cube.getColor(c.f1, c.r1, c.c1);
            if (white != 'w') continue;

            char a1 = cube.getColor(c.f2, c.r2, c.c2);
            char a2 = cube.getColor(c.f3, c.r3, c.c3);
            char c1 = cube.getColor(c.f2, 1, 1); // center of adjacent face
            char c2 = cube.getColor(c.f3, 1, 1);

            if (a1 != c1 || a2 != c2) {
                cout << "Popping incorrect white corner: R U R' U'\n";
                cube.move("R");
                cube.move("U");
                cube.move("R'");
                cube.move("U'");
                moved = true;
                break;
            }
        }

        if (moved) {
            attempts++;
            continue;
        }

        // Step 2: insert top white corners
        for (Corner& c : topCorners) {
            char x = cube.getColor(c.f1, c.r1, c.c1);
            char y = cube.getColor(c.f2, c.r2, c.c2);
            char z = cube.getColor(c.f3, c.r3, c.c3);

            if (x != 'w' && y != 'w' && z != 'w') continue;

            // Rotate U until adjacent stickers match center colors
            for (int i = 0; i < 4; ++i) {
                char a1 = cube.getColor(c.f2, c.r2, c.c2);
                char a2 = cube.getColor(c.f3, c.r3, c.c3);
                char c1 = cube.getColor(c.f2, 1, 1);
                char c2 = cube.getColor(c.f3, 1, 1);
                if (a1 == c1 && a2 == c2) break;
                cube.move("U");
                cout << "Rotating U to align top corner\n";
            }

            // Determine insertion direction
            bool insertLeft = (c.f3 == 4);
            bool insertRight = (c.f3 == 5);

            if (insertLeft) {
                cout << "Inserting top corner on left: L' U' L\n";
                cube.move("L'");
                cube.move("U'");
                cube.move("L");
            } else if (insertRight) {
                cout << "Inserting top corner on right: R U R'\n";
                cube.move("R");
                cube.move("U");
                cube.move("R'");
            } else {
                cout << "Fallback insertion: R U R'\n";
                cube.move("R");
                cube.move("U");
                cube.move("R'");
            }

            moved = true;
            break;
        }

        attempts++;
    } while (moved && attempts < maxAttempts);

    if (attempts >= maxAttempts) {
        cout << "whiteCornerSolver hit max attempts.\n";
    } else {
        cout << "whiteCornerSolver finished in " << attempts << " steps.\n";
    }
}
    
