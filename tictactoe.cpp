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
void updateGrid(char * row, char * collumn);
int getRow(char inputRow);
int getColumn(char inputColumn);

int main() {
  cout << "Welcome to Tic Tac Toe!" << endl;
  char grid[3][3];
  char play[2];
  char turn = 'X';
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
    cout << "it's " << turn << "'s turn!";
    cin.get(play, 3);
    cin.get();
    row = getRow(play[0]);
    column = getColumn(play[1]);
    grid[row][column] = turn;
    if(turn == 'X') {
      turn = 'O';
    }
    else {
      turn = 'X';
    }
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
	cout << grid[i][j] << " ";
      }
      cout << endl;
    }
    prtGrid(grid);
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

bool checkInput(char input[2], char * gridPtr) {
  if((input[0] > 64 && input[0] < 68) || (input[0] > 96 && input[0] < 100)) {
    if(input[1] > 48 && input[1] < 52) {
      //changeRow(input[0]);
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
}

char updateGrid(int row, int column, char turn) {
  
}
