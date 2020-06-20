#include "Puzzle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>



using namespace std;


Puzzle::Puzzle(std::string fileName){
  std::fstream myFile;
  int line;
  myFile.open(fileName);
  bool first = true;
  int counter = 0;
  int currentAscii;
  int currentRow;
  int currentCol;
  int i = 0;
  
  
  while(myFile >> line)
  {
    if(first){
        pieceCount = line;
        first = false;
        pieces = new Token*[pieceCount];
        continue;
      }
    else{
        if(counter == 0)
        {
          counter++;
          currentAscii = line;
        }
        else if(counter == 1)
        {
          if(rowCount < line)
            rowCount = line;
          counter++;
          currentRow = line;
        }
        else if(counter == 2)
        {
          if(colCount < line)
            colCount = line;
          counter = 0;
          currentCol = line;
          char asciiChar = currentAscii;
          pieces[i] = new Token(asciiChar, currentRow, currentCol);
          i++;
          
        }
        
        
    }
    
  }

  myFile.close();
}  


void Puzzle::printPieces(){
  int i = 0;
  
  for(int r = 0; r < rowCount; r++)
  {
    for(int c = 0; c < colCount; c++)
    {
      cout << pieces[i]->letter << " "; 
      i++;
    }
    cout << endl;
  } 

} // print the list of randomized puzzle pieces


void Puzzle::loadGrid(){
  vector <Token *> v;
  Token *ptr;
  for(int r = 0; r < rowCount; r++)
  {
    for(int c = 0; c < colCount; c++)
    {
      for(int i = 0; i < pieceCount; i++)
      {
        if(r == pieces[i]->row && c == pieces[i]->col)
        {
          ptr = pieces[i];
          v.push_back(ptr);
          continue;
        }
      }
    }
    grid.push_back(v);
    v.clear();
  }
} // allocate the grid and copy pieces pointers to their correct location int the grid;


Puzzle::~Puzzle(){
  for(int i = 0; i < pieceCount; i++)
  {
    delete pieces[i];
  }
} // destructor - when we delete the Puzzle instance, the destructor should clean up all "new" allocations


void Puzzle::printGrid(){
  for(int r = 0; r < rowCount; r++)
  {
    for(int c = 0; c < colCount; c++)
    {
      cout << grid[r][c]->letter << " ";
    }
    cout << endl;
  }

}

