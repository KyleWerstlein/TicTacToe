/*Kyle Werstlein
9/24/19
Play TicTacToe with another player! */
#include <iostream>
#include <cstring>

using namespace std;

void prtGrid(char grid[3][3]); // functions
char setGrid(char gridSpace);
char changePlayer(char turn);
int getRow(char inputRow);
int getColumn(char inputColumn);
bool checkWin(char grid[3][3], char turn);
bool checkTie(int space, bool playing);
bool checkGrid(char grid[3][3], int row, int column);
bool playPrompt();

int main() {
	cout << "Welcome to Tic Tac Toe!" << endl;
	char grid[3][3]; // variables
	char play[2];
	char turn = 'X';
	int spaceAvalible = 9;
	int oWin = 0;
	int xWin = 0;
	int ties = 0;
	for (int i = 0; i < 3; i++) { // reset grid
		for (int j = 0; j < 3; j++) {
			grid[i][j] = setGrid(grid[i][j]);
		}
	}
	prtGrid(grid);// draw grid
	bool isPlaying = true;
	int row = -1;
	int column = -1;
	while (isPlaying) { // game loop
		cout << "it's " << turn << "'s turn!" << endl;
		cin.get(play, 3);
		cin.get(); // take input
		if((play[0] > 64 && play[0] < 68) || (play[0] > 96 && play[0] < 100)) {
			cout << "test";
			if((play[1] > 48 && play[1] < 52)) {
				row = getRow(play[0]); // convert input into data usable in my functions
		column = getColumn(play[1]); // same as above
		cout << "test0" << endl;
		if (checkGrid(grid, row, column)) { // if move is legal
		  cout << "test" << endl;
			grid[row][column] = turn; // make play on board
			if (!checkWin(grid, turn)) { // someone wins
				prtGrid(grid);
				if (turn == 'X') {
					xWin++;
				}
				else if (turn == 'O') {
					oWin++;
				}
				for (int i = 0; i < 3; i++) { // reset grid
					for (int j = 0; j < 3; j++) {
						grid[i][j] = setGrid(grid[i][j]);
					}
				}
				isPlaying = playPrompt();
			}
			spaceAvalible--; // track empty spaces to detect ties
			if (checkTie(spaceAvalible, checkWin(grid, turn))) { // check tie
				ties++;
				prtGrid(grid);
				for (int i = 0; i < 3; i++) { // reset grid again
					for (int j = 0; j < 3; j++) {
						grid[i][j] = setGrid(grid[i][j]);
					}
				}
				isPlaying = playPrompt();
				turn = 'O';
			}
			if (spaceAvalible == 0) {
				spaceAvalible = 9;
			}
			prtGrid(grid);
			turn = changePlayer(turn); // swap player
			cout << "Ties: " << ties << endl;
			cout << "X Wins: " << xWin << endl;
			cout << "O Wins: " << oWin << endl;
		}
		else {
		  cout << "invalid input._" << endl;
		}
			}
		}
	}
		return 0;
}

bool playPrompt() {
	char prompt[1];
	bool valid = false;
	while (!valid) {
		cout << "Would you like to play again? (y/n)" << endl;
		cin.get(prompt, 1);
		cin.get();
		if (prompt[0] == 'y') {
			cout << "test";
			return true;
		}
		else if (prompt[0] == 'n') {
			cout << "test2";
			return false;
		}
		else {
			cout << "Invalid input." << endl;
			cout << prompt[0] << endl;
		}
	}
}

void prtGrid(char grid[3][3]) {
	char startAscii = '@';
	cout << "  1 2 3" << endl;
	for (int i = 0; i < 3; i++) {
		startAscii++;
		cout << startAscii << " ";
		for (int j = 0; j < 3; j++) {
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
	if (turn == 'X') {
		turn = 'O';
	}
	else {
		turn = 'X';
	}
	return turn;
}

int getRow(char rowInput) { // letters to number to be used as array index
	if (rowInput == 'A' || rowInput == 'a') {
		return 0;
	}
	else if (rowInput == 'B' || rowInput == 'b') {
		return 1;
	}
	else if (rowInput == 'C' || rowInput == 'c') {
		return 2;
	}
	else {
		cout << "Invalid input?." << endl;
		return -1;
	}
}

int getColumn(char columnInput) { // same as above
	if (columnInput == '1') {
		return 0;
	}
	else if (columnInput == '2') {
		return 1;
	}
	else if (columnInput == '3') {
		return 2;
	}
	else {
		cout << "Invalid input!." << endl;
		return -1;
	}
}

bool checkGrid(char grid[3][3], int row, int column) {
	if (grid[row][column] != '#') { // if trying to play on a space that is not empty.
		cout << "Space unavalible." << endl;
		return false;
	}
	else {
		return true;
	}
}

bool checkTie(int space, bool playing) {
	if (space == 0 && playing == true) { // if no one has one and there are 0 empty spaces
		return true;
	}
	else {
		return false;
	}
}

bool checkWin(char grid[3][3], char player) { // check all possible win combinations
	if (grid[0][0] == player && grid[1][0] == player && grid[2][0] == player) { // column 1
		return false;
	}
	else if (grid[0][1] == player && grid[1][1] == player && grid[2][1] == player) { // column 2                          
		return false;
	}
	else if (grid[0][2] == player && grid[1][2] == player && grid[2][2] == player) {  // column 3
		return false;
	}
	else if (grid[0][0] == player && grid[0][1] == player && grid[0][2] == player) { // row 1
		return false;
	}
	else if (grid[1][0] == player && grid[1][1] == player && grid[1][2] == player) { // row 2
		return false;
	}
	else if (grid[2][0] == player && grid[2][1] == player && grid[2][2] == player) { // row 3
		return false;
	}
	else if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) { // diagonal 1
		return false;
	}
	else if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) { // diagonal 2
		return false;
	}
	else {
		return true;
	}
}
