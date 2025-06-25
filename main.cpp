# include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "Life.h"
using namespace std;

int main() { 
  Life game;
  cout << "Welcome to the Game of Life simuilation thought up by John Horton Conway in 1970. This game involves simulating the population of cells throughout many generations following these rules:" << endl;
  cout << "1: Any live cell with fewer than two live neighbours dies, as if by underpopulation." << endl;
  cout << "2: Any live cell with two or three live neighbours lives on to the next generation." << endl;
  cout << "3: Any live cell with more than three live neighbours dies, as if by overpopulation." << endl;
  cout << "4: Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
  cout << "Press Enter to continue...";
  cin.get();
  while(true){
    cout << "Type a command or type help for a list of commands." << endl;
    string command;
    cin >> command;
    if (command == "help"){
      cout << "The commands are: " << endl;
      cout << "help: prints this message" << endl;
      cout << "quit: exits the program" << endl;
      cout << "reset: resets the board to all 0s" << endl;
      cout << "print: prints the board" << endl;
      cout << "next: advances the board to the next generation" << endl;
      cout << "set [row] [col] [int]: sets the cell at the given coordinates to the given value" << endl;
      cout << "resize [row] [col]: resizes the board to the given dimensions" << endl;
      cout << "random: fills the board with random values" << endl;
      cout << "simulateWithStep [int]: simulates the board with user input for the given number of generations (-1) for infinite generations" << endl;
      cout << "simulate [int]: simulates the board for the given number of generations (-1) for infinite generations" << endl;
      cout << "clear: clears the screen" << endl;
      cout << "preset [int]: loads a preset board containing a unique machine (1-16)" << endl;
    }
    else if(command == "quit"){
      break;
    }
    else if(command == "reset"){
      game.reset_board();
    }
    else if(command == "print"){
      game.print_board();
    }
    else if(command == "next"){
      game.next_generation();
    }
    else if(command == "set"){
      int row, col, value;
      cin >> row >> col >> value;
      game.set_cell(row, col, value);
    }
    else if(command == "resize"){
      int row, col;
      cin >> row >> col;
      game.resize_board(row, col);
    }
    else if(command == "random"){
      game.set_random();
    }
    else if(command == "simulateWithStep"){
      int generations;
      cin >> generations;
      game.simulatewithStep(generations);
    }
    else if(command == "simulate"){
      int generations;
      cin >> generations;
      game.simulate(generations);
    }
    else if(command == "clear"){
      system("clear");
    }
    else if(command == "preset"){
      int preset;
      cin >> preset;
      game.preset(preset);
    }
    else{
      cout << "Invalid command" << endl;
    }
  }
}
