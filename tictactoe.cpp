/*Kyle Werstlein
9/24/19
Play TicTacToe with another player! */
#include <iostream>
#include <cstring>

using namespace std;

void prtGrid(char grid[3][3]);
char setGrid(char gridSpace);
char changePlayer(char turn);
int getRow(char inputRow);
int getColumn(char inputColumn);
bool checkWin(char grid[3][3], char turn);
bool checkTie(int space, bool playing);
bool checkGrid(char grid[3][3], int row, int column);

int main() {
  cout << "Welcome to Tic Tac Toe!" << endl;
  char grid[3][3];
  char play[2];
  char turn = 'X';
  int spaceAvalible = 9;
  int oWin = 0;
  int xWin = 0;
  int ties = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      grid[i][j] = setGrid(grid[i][j]);
    }
  } 
  prtGrid(grid);
  bool isPlaying = true;
  while(isPlaying) {
    int row = -1;
    int column = -1;
    cout << "it's " << turn << "'s turn!" << endl;
    cin.get(play, 3);
    cin.get();
    row = getRow(play[0]);
    column = getColumn(play[1]);
    if(checkGrid(grid, row, column)) {
      grid[row][column] = turn;
      isPlaying = checkWin(grid, turn);
      if(!checkWin(grid, turn)) {
	if(turn == 'X') {
	  xWin++;
	}
	else if(turn == 'O') {
	  oWin++;
	}
      }
      turn = changePlayer(turn);
      spaceAvalible--;
      if(checkTie(spaceAvalible, checkWin(grid, turn)) {
	  ties++;
	}
    }
    prtGrid(grid);
  }
  cout << "Game Over" << endl;
  cout << "Ties: " << ties;
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
  if(turn == 'X') {
    turn = 'O';
  }
  else {
    turn = 'X';
  }
  return turn;
}

int getRow(char rowInput) {
  if(rowInput == 'A' || rowInput == 'a') {
    return 0;
  }
  else if (rowInput == 'B' || rowInput == 'b') {
    return 1;
  }
  else if (rowInput == 'C' || rowInput == 'c') {
    return 2;
  }
  else {
    cout << "Invalid input." << endl;
  }
}

int getColumn(char columnInput) {
  if(columnInput == '1') {
    return 0;
  }
  else if(columnInput == '2') {
    return 1;
  }
  else if(columnInput == '3') {
    return 2;
  }
  else {
    cout << "Invalid input." << endl;
  }
}

bool checkGrid(char grid[3][3], int row, int column) {
  if(grid[row][column] != '#') {
    cout << "Space unavalible." << endl;
    return false;
  }
  else {
    return true;
  }
}

bool checkTie(int space, bool playing) {
  if(space == 0 && playing = true;) {
    return true;
  }
  else {
    return false;
  }
}

bool checkWin(char grid[3][3], char player) {
  cout << "Player: " << player << endl;
  if(grid[0][0] == player && grid[1][0] == player && grid[2][0] == player) { // column 1
    return false;
  }
  else if(grid[0][1] == player && grid[1][1] == player && grid[2][1] == player) { // column 2                          
    return false;
  }
  else if(grid[0][2] == player && grid[1][2] == player && grid[2][2] == player) {  // column 3
    return false;
  }
  else if(grid[0][0] == player && grid[0][1] == player && grid[0][2] == player) { // row 1
    return false;                                                                                                         }
  else if(grid[1][0] == player && grid[1][1] == player && grid[1][2] == player) { // row 2
    return false;                                                                                                         }
  else if(grid[2][0] == player && grid[2][1] == player && grid[2][2] == player) { // row 3
    return false;                                                                                                         }
  else if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) { // diagonal 1
    return false;                                                                                                         }
  else if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) { // diagonal 2
    return false;                                                                                                         }
  else {
    return true;
  }
}
