#ifndef GRID_H
#define GRID_H

class Grid{
    char grid[9];
  public:
    Grid();
    ~Grid();
    void drawGrid();
    void gridAdd(char, int);
};

#endif // !GRID_H