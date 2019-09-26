/*Kyle Werstlein
9/24/19
Play TicTacToe with another player! */
#include <iostream>
#include <cstring>

using namespace std;

void prtGrid(char grid[3][3]);
char setGrid(char gridSpace);

int main() {
  char grid[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      grid[i][j] = setGrid(grid[i][j]);
    }
  }
  prtGrid(grid);
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
