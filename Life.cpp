#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include "Life.h"

Life::Life(){
  rows = 10;
  cols = 10;
  board.resize(rows, vector<int>(cols, 0));
}

void Life::resize_board(int x, int y){
  rows = x;
  cols = y;
  board.resize(rows);
  for (int i = 0; i < rows; i++){
    board[i].resize(cols, 0);
  }
}
void Life::set_cell(int x, int y, int value){
  board[x][y] = value % 2;
}

void Life::next_generation(){
  vector<vector<int>> new_board(rows, vector<int>(cols, 0));
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      new_board[i][j] = next_state(i, j);
    }
  }
  board = new_board;
}

void Life::reset_board(){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      board[i][j] = 0;
    }
  }
}

void Life::print_board(){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      cout << '[';
      if(board[i][j] == 0){
        cout << " " << ']';
      }
      else{
        cout << "X]";
      }
    }
    cout << endl;
  }
}

int Life::next_state(int r, int c){
  int alive = count_neighbors(r, c);
  if (alive < 2 || alive > 3){
      return 0;
  }
  else if(alive == 3){
      return 1;
  }
  else{
    return board[r][c];
  }
}

int Life::count_neighbors(int r, int c){
  int count = 0;
  for (int i = r -1 ; i <= r + 1; i++){
    for(int j = c - 1; j <= c + 1; j++){
      if (i >= 0 && i < rows && j >= 0 && j < cols && !(i == r && j == c)){
        count += board[i][j];
      }
    }
  }
  return count;
}

void Life::set_random(){
  srand ( time(NULL) );
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      board[i][j] = rand() % 2;
    }
  }
}

void Life::simulatewithStep(int generations){
  system("clear");
  print_board();
  sleep(1);
  if (generations == -1)
    while(true){
      system("clear");
      next_generation();
      print_board();
      cout << "Press Enter to continue...";
      cin.get();
    }
  else{
    for (int i = 0; i < generations; i++){
      system("clear");
      next_generation();
      print_board();
      cout << "Press Enter to continue...";
      cin.get();
    }
  }
}

void Life::simulate(int generations){
  system("clear");
  print_board();
  sleep(1);
  if (generations == -1)
    while(true){
      system("clear");
      next_generation();
      print_board();
      sleep(1);
    }
  else{
    for (int i = 0; i < generations; i++){
      system("clear");
      next_generation();
      print_board();
      sleep(1);
    }
  }
}

void Life::preset(int num){
  if(num == 1){
    resize_board(4, 4);
    reset_board();
    set_cell(1, 1, 1);
    set_cell(1, 2, 1);
    set_cell(2, 1, 1);
    set_cell(2, 2, 1);
    cout << "Loaded Preset 1: Block" << endl;
    return;
  }
  else if(num == 2){
    resize_board(5, 6);
    reset_board();
    set_cell(1,2,1);
    set_cell(1,3,1);
    set_cell(2,1,1);
    set_cell(2,4,1);
    set_cell(3,2,1);
    set_cell(3,3,1);
    cout << "Loaded Preset 2: Bee Hive" << endl;
    return;
  }
  else if(num == 3){
    resize_board(6, 6);
    reset_board();
    set_cell(1,2,1);
    set_cell(1,3,1);
    set_cell(2,1,1);
    set_cell(2,4,1);
    set_cell(3,2,1);
    set_cell(3,4,1);
    set_cell(4,3,1);
    cout << "Loaded Preset 3: Loaf" << endl;
  }
  else if(num == 4){
    resize_board(5,5);
    reset_board();
    set_cell(1,1,1);
    set_cell(1,2,1);
    set_cell(2,1,1);
    set_cell(2,3,1);
    set_cell(3,2,1);
    cout << "Loaded Preset 4: Boat" << endl;
    return;
  }
  else if(num == 5){
    resize_board(5, 5);
    reset_board();
    set_cell(1, 2, 1);
    set_cell(2, 1, 1);
    set_cell(2, 3, 1);
    set_cell(3, 2, 1);
    cout << "Loaded Preset 5: Tub" << endl;
    return;
  }
  else if (num == 6){
    resize_board(5, 5);
    reset_board();
    set_cell(1, 2, 1);
    set_cell(2, 2, 1);
    set_cell(3, 2, 1);
    cout << "Loaded Preset 6: Blinker" << endl;
    return;
  }
  else if(num == 7){
    resize_board(6, 6);
    reset_board();
    set_cell(1, 3, 1);
    set_cell(2, 1, 1);
    set_cell(2, 4, 1);
    set_cell(3, 1, 1);
    set_cell(3, 4, 1);
    set_cell(4, 2, 1);
    cout << "Loaded Preset 7: Toad" << endl;
    return;
  }
  else if(num == 8){
    resize_board(6, 6);
    reset_board();
    set_cell(1,1,1);
    set_cell(1,2,1);
    set_cell(2,1,1);
    set_cell(2,2,1);
    set_cell(3,3,1);
    set_cell(3,4,1);
    set_cell(4,3,1);
    set_cell(4,4,1);
    cout << "Loaded Preset 8: Beacon" << endl;
    return;
  }
    else if(num == 9){
      resize_board(17, 17);
      reset_board();
      set_cell(2,4,1);
      set_cell(2,5,1);
      set_cell(2,6,1);
      set_cell(2,10,1);
      set_cell(2,11,1);
      set_cell(2,12,1);
      set_cell(4,2,1);
      set_cell(4,7,1);
      set_cell(4,9,1);
      set_cell(4,14,1);
      set_cell(5,2,1);
      set_cell(5,7,1);
      set_cell(5,9,1);
      set_cell(5,14,1);
      set_cell(6,2,1);
      set_cell(6,7,1);
      set_cell(6,9,1);
      set_cell(6,14,1);
      set_cell(7,4,1);
      set_cell(7,5,1);
      set_cell(7,6,1);
      set_cell(7,10,1);
      set_cell(7,11,1);
      set_cell(7,12,1);
      set_cell(9,4,1);
      set_cell(9,5,1);
      set_cell(9,6,1);
      set_cell(9,10,1);
      set_cell(9,11,1);
      set_cell(9,12,1);
      set_cell(10,2,1);
      set_cell(10,7,1);
      set_cell(10,9,1);
      set_cell(10,14,1);
      set_cell(11,2,1);
      set_cell(11,7,1);
      set_cell(11,9,1);
      set_cell(11,14,1);
      set_cell(12,2,1);
      set_cell(12,7,1);
      set_cell(12,9,1);
      set_cell(12,14,1);
      set_cell(14, 4,1);
      set_cell(14,5,1);
      set_cell(14,6,1);
      set_cell(14,10,1);
      set_cell(14,11,1);
      set_cell(14,12,1);
      cout << "Loaded Preset 9: Pulsar" << endl;
      return;
    }
    else if(num == 10){
      resize_board(18,11);
      reset_board();
      set_cell(4,4,1);
      set_cell(4,5,1);
      set_cell(4,6,1);
      set_cell(5,3,1);
      set_cell(5,7,1);
      set_cell(6,2,1);
      set_cell(6,8,1);
      set_cell(8,1,1);
      set_cell(8,9,1);
      set_cell(9,1,1);
      set_cell(9,9,1);
      set_cell(11,2,1);
      set_cell(11,8,1);
      set_cell(12,3,1);
      set_cell(12,7,1);
      set_cell(13,4,1);
      set_cell(13,5,1);
      set_cell(13,6,1);
      cout << "Loaded Preset 10: Penta-decathlon" << endl;
      return;
    }
    else if(num == 11){
      resize_board(7, 7);
      reset_board();
      set_cell(0,2,1);
      set_cell(1,0,1);
      set_cell(1,2,1);
      set_cell(2,1,1);
      set_cell(2,2,1);
      cout << "Loaded Preset 11: Glider" << endl;
      return;
    }
    else if(num == 12){
      resize_board(8, 35);
      reset_board();
      set_cell(2,3,1);
      set_cell(2,4,1);
      set_cell(2,5,1);
      set_cell(2,6,1);
      set_cell(3,2,1);
      set_cell(3,6,1);
      set_cell(4,6,1);
      set_cell(5,2,1);
      set_cell(5,5,1);
      cout << "Loaded Preset 12: Lightweight spaceship (LWSS)" << endl;
      return;
    }
    else if(num == 13){
      resize_board(9, 35);
      reset_board();
      set_cell(1,4,1);
      set_cell(2,2,1);
      set_cell(2,6,1);
      set_cell(3,7,1);
      set_cell(4,2,1);
      set_cell(4,7,1);
      set_cell(5,3,1);
      set_cell(5,4,1);
      set_cell(5,5,1);
      set_cell(5,6,1);
      set_cell(5,7,1);
      cout << "Loaded Preset 13: Middleweight spaceship (MWSS)" << endl;
      return;
    }
    else if(num == 14){
      resize_board(9, 35);
      reset_board();
      set_cell(1,4,1);
      set_cell(1,5,1);
      set_cell(2,2,1);
      set_cell(2,7,1);
      set_cell(3,8,1);
      set_cell(4,2,1);
      set_cell(4,8,1);
      set_cell(5,3,1);
      set_cell(5,4,1);
      set_cell(5,5,1);
      set_cell(5,6,1);
      set_cell(5,7,1);
      set_cell(5,8,1);
      cout << "Loaded Preset 14: Heavyweight spaceship (HWSS)" << endl;
      return;
    }
    else if(num == 15){
      resize_board(9,9);
      reset_board();
      set_cell(3,4,1);
      set_cell(3,5,1);
      set_cell(4,3,1);
      set_cell(4,4,1);
      set_cell(5,4,1);
      cout << "Loaded Preset 15: The R-pentomino" << endl;
      return;
    }
    else if(num == 16){
      resize_board(25, 39);
      reset_board();
      set_cell(5,1,1);
      set_cell(5,2,1);
      set_cell(6,1,1);
      set_cell(6,2,1);
      set_cell(3,13,1);
      set_cell(3,14,1);
      set_cell(4,12,1);
      set_cell(4,16,1);
      set_cell(5,11,1);
      set_cell(5,17,1);
      set_cell(6,11,1);
      set_cell(6,15,1);
      set_cell(6,17,1);
      set_cell(6,18,1);
      set_cell(7,11,1);
      set_cell(7,17,1);
      set_cell(8,12,1);
      set_cell(8,16,1);
      set_cell(9,13,1);
      set_cell(9,14,1);
      set_cell(1,25,1);
      set_cell(2,23,1);
      set_cell(2,25,1);
      set_cell(3,21,1);
      set_cell(3,22,1);
      set_cell(4,21,1);
      set_cell(4,22,1);
      set_cell(5,21,1);
      set_cell(5,22,1);
      set_cell(6,23,1);
      set_cell(6,25,1);
      set_cell(7,25,1);
      set_cell(3,36,1);
      set_cell(3,37,1);
      set_cell(4,36,1);
      set_cell(4,37,1);
      cout << "Loaded Preset 16: The Gosper Glider Gun" << endl;
      return;
    }
    else{
      cout << "Not a Valid Preset Number" << endl;
    return;
  }
}