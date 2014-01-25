#include <iostream>
#include "console/console.h"
#include "Game.h"

using namespace std;

int main(){
  Game game = Game();
  int move;
  bool win = false;
  clrscr();
  game.drawGrid();
  bool running = game.isRunning();
  while (running) {
    move = game.getMove();
    game.gridAdd(move);
    running = game.isRunning();
  }
  gotoxy(0,0);
	return 0;
}
