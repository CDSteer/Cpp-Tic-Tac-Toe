#ifndef GAME_H
#define GAME_H

class Game{
  private:
    static const char X = 'X';
    static const char O = 'O';
    char grid[9];
    char turn;
    bool on;
    int turnCout;
  public:
    Game();
    ~Game();

    void drawGrid();
    void gridAdd(int);
    bool hasWon();
    bool legalMove(int);

    void changeTurn();
    bool isRunning();
    char getTurn();
    int getMove();
};

#endif // !GAME_H