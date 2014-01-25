#include <iostream>
#include <array>
#include "Game.h"
#include "../console/console.h"

using namespace std;

Game::Game(){
  grid[0] = '1';
  grid[1] = '2';
  grid[2] = '3';

  grid[3] = '4';
  grid[4] = '5';
  grid[5] = '6';

  grid[6] = '7';
  grid[7] = '8';
  grid[8] = '9';

  turn = X;
  on = true;
  turnCout = 0;
}
Game::~Game(){}

void Game::drawGrid(){
  gotoxy(5, 4);
  cout <<" " << grid[0] << "  |" << grid[1] << "  |" << grid[2] << " " << "\n";
  gotoxy(5, 5);
  cout <<"____|___|___" << "\n";
  gotoxy(5, 6);
  cout <<" " << grid[3]  << "  |" << grid[4] << "  |" << grid[5] << "" << "\n";
  gotoxy(5, 7);
  cout <<"____|___|___" << "\n";
  gotoxy(5, 8);
  cout <<" " << grid[6] << "  |" << grid[7]  << "  |" << grid[8] << "" << "\n";
  gotoxy(5, 9);
  cout <<"    |   |" << "\n";
  gotoxy(5, 10);
}

void Game::gridAdd(int box){
  if (legalMove(box)){
    turnCout++;
    if (turnCout >= 9) {
      on = false;
      cout << "Draw!!";
    }
    grid[box-1] = turn;
    clrscr();
    drawGrid();
    if (turnCout >= 3 ) {
      bool win = hasWon();
      if (win) {
        on = false;
        cout << getTurn() << " Wins!!";}
    }
    if (on == true) changeTurn();
  } else {
    gotoxy(5,11);
    cout << "Box Taken!!";
    clearx(10, 0);
    //run turn again
  }
}

bool Game::hasWon(){
  if (grid[0] == turn && grid[1] == turn && grid[2] == turn) return true;
  if (grid[0] == turn && grid[3] == turn && grid[6] == turn) return true;
  if (grid[0] == turn && grid[4] == turn && grid[8] == turn) return true;
  if (grid[8] == turn && grid[5] == turn && grid[2] == turn) return true;
  if (grid[8] == turn && grid[7] == turn && grid[6] == turn) return true;
  if (grid[3] == turn && grid[4] == turn && grid[5] == turn) return true;
  if (grid[1] == turn && grid[4] == turn && grid[7] == turn) return true;
  if (grid[2] == turn && grid[4] == turn && grid[6] == turn) return true;
  else return false;
}

bool Game::legalMove(int box){
  if (grid[box-1] == X || grid[box-1] == O) return false;
  return true;
}

void Game::changeTurn(){
  if (turn == X) turn = O;
  else turn = X;
}

bool Game::isRunning(){
  return on;
}

char Game::getTurn(){
  return turn;
}

int Game::getMove(){
  int input;
  bool error = true;
  while (error){
    try{
      gotoxy(5,10);
      cout << turn << ": ";
      cin >> input;
      if (cin.fail()) throw input;
      if (input <= 0) throw input;
      if (input > 9) throw input;
      error = false;
    } catch (...) {
      gotoxy(5,11);
      cout << "Enter a number from the grid!!" << "\n";
      clearx(10, 0);
      cin.clear();
      cin.get();
      error = true;
    }
  }
  return input;
}