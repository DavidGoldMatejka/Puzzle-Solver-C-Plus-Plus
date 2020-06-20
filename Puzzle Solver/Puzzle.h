#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>
#include "Token.h"

class Puzzle{

  public:


    Puzzle(std::string fileName);  // constructor: load the puzzle pieces into the dynamic pieces array
    void printPieces(); // print the list of randomized puzzle pieces
    void loadGrid(); // allocate the grid and copy pieces pointers to their correct location int the grid;
    ~Puzzle(); // destructor - when we delete the Puzzle instance, the destructor should clean up all "new" allocations
    void printGrid(); // print the entire puzzle, using the grid data member 

  private:
    int pieceCount; // number of pieces in the entire puzzle
    int rowCount; // number of rows in the puzzle
    int colCount; // number of columns in the puzzle
    Token **pieces; // dynamic array of pointers to tokens!  tokens will be dynamically allocated
    std::vector< std::vector < Token * >> grid; // vector of vector of Token pointers!

      // note: we must keep this at the end of the class!
};

#endif