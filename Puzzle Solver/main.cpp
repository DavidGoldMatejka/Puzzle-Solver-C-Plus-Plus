#include <iostream>
#include "Puzzle.h"

using namespace std;

 int main() {

  cout << "Building a Jigsaw Puzzle...." << endl;
  Puzzle * p = new Puzzle("puzzle_input_basic.txt"); // load the scrambled pieces into a dynamic array
  p->printPieces(); // print all the pieces in the puzzle from the dynamic array
  p->loadGrid(); // initialize the grid and then load it with all the Token pointers 
  p->printGrid(); //  print the final puzzle (it should look like something)
  delete p; // delete the Puzzle instance, effectively calling the destructor

  cout << "Done!" << endl;
  return 0;
  }