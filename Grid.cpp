#include <iostream>
#include <array>
#include "Grid.h"
#include "console/console.h"

using namespace std;

Grid::Grid(){
  grid[0] = '0';
  grid[1] = '1';
  grid[2] = '2';

  grid[3] = '3';
  grid[4] = '4';
  grid[5] = '5';

  grid[6] = '6';
  grid[7] = '7';
  grid[8] = '8';
}
Grid::~Grid(){}

void Grid::drawGrid(){
  gotoxy(10, 4);
  cout <<" " << grid[0] << "  |" << grid[1] << "  |" << grid[2] << " " << "\n";
  gotoxy(10, 5);
  cout <<"____|___|___" << "\n";
  gotoxy(10, 6);
  cout <<" " << grid[3]  << "  |" << grid[4] << "  |" << grid[5] << "" << "\n";
  gotoxy(10, 7);
  cout <<"____|___|___" << "\n";
  gotoxy(10, 8);
  cout <<" " << grid[6] << "  |" << grid[7]  << "  |" << grid[8] << "" << "\n";
  gotoxy(10, 9);
  cout <<"    |   |" << "\n";
  gotoxy(10, 10);
}

void Grid::gridAdd(char marker, int box){
  grid[box] = marker;
  clrscr();
  drawGrid();
}