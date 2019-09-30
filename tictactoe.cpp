/*Kyle Werstlein
9/24/19
Play TicTacToe with another player! */
#include <iostream>
#include <cstring>

using namespace std;

void prtGrid(char grid[3][3]);
char setGrid(char gridSpace);
char changePlayer(char turn);
bool checkInput(char input[2]);
void updateGrid(char input[2]);

int main() {
  cout << "Welcome to Tic Tac Toe!" << endl;
  char grid[3][3];
  char play[2];
  char turn = 'x';
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      grid[i][j] = setGrid(grid[i][j]);
    }
  }
  prtGrid(grid);
  bool isPlaying = true;
  while(isPlaying) {
    cout << "it's " << turn << "'s turn!";
    cin.get(play, 3);
    cin.get();
    isPlaying = checkInput(play);
  }
  return 0;
}

void prtGrid(char grid[3][3]) {
  char startAscii = '@';
  cout << "  1 2 3" << endl;
  for(int i = 0; i < 3; i++) {
    startAscii++;
    cout << startAscii << " ";
    for(int j = 0; j < 3; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

char setGrid(char gridSpace) {
  gridSpace = '#';
  return gridSpace;
}

char changePlayer(char turn) {
  if(turn == 'x') {
    turn = 'o';
  }
  else {
    turn = 'x';
  }
  return turn;
}

bool checkInput(char input[2]) {
  if((input[0] > 64 && input[0] < 68) || (input[0] > 96 && input[0] < 100)) {
    if(input[1] > 48 && input[1] < 52) {
      updateGrid(input);
      return true;
    }
    else {
      cout << "invalid collumn" << endl;
      return false;
    }
  }
  else {
    cout << "invalid row" << endl;
    return false;
  }
}

void updateGrid(char input[2]) {
  int row = -1;
  int collumn = -1;
  switch (input[0]) {
  case 65: row = 0;
    switch (input[1]) {
    case 1:
      collumn = 0;
      break;
    case 2:
      collumn = 1;
      break;
    case 3:
      collumn = 2;
      break;
    }
    break;
  case 66: row = 1;
    switch (input[1]) {
    case 1:
      column = 0;
      break;
    case 2:
      column = 1;
      break;
    case 3:
      column = 2;
      break;
    }
    break;
  case 67: row = 2;
    switch (input[1]) {
    case 1:
      column = 0;
      break;
    case 2:
      column = 1;
      break;
    case 3:
      column = 2;
      break;
    }
    break;
  }
  return;
}
