#include <iostream>
#include "console/console.h"
#include "Grid.h"

using namespace std;

int numInput(){
  int input;
  bool error = true;
  while (error){
    try{
      cin >> input;
      if (cin.fail()) throw input;
      if (input < 0) throw input;
      if (input >= 9) throw input;
      error = false;
    } catch (...) {
      cout << "Enter a number from the grid!!" << "\n";
      cin.clear();
      cin.get();
      error = true;
    }
  }
  return input;
}

int main(){
  char turn = 'X';
  clrscr();
  Grid grid = Grid();
  grid.drawGrid();
  int num;
  cout << "X: ";
  num = numInput();
  grid.gridAdd(turn, num);

  turn = 'O';
  cout << "O: ";
  num = numInput();
  grid.gridAdd(turn, num);
	return 0;
}
