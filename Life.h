#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <vector>
using namespace std;

class Life{
  public:
    Life();
    void resize_board(int x, int y);
    void set_cell(int x, int y, int value);
    void next_generation();
    void reset_board();
    void print_board();
    void set_random();
    void simulatewithStep(int generations);
    void simulate(int generations);
    void preset(int num);
  private:
    int rows;
    int cols;
    vector<vector<int>> board;
    int next_state(int r, int c);
    int count_neighbors(int r, int c);

};


#endif