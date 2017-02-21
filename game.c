/*
	- Print a msg if the game ends in a tie.
*/
#include <stdio.h>
#include <stdbool.h>

int arr[3][3];
char def = '.';
int row, col;
char player;
int turn = 0;
bool r1, r2, r3;
bool c1, c2, c3;
bool d1, d2;

// setting the default value of all array elements to '.'
void setDefaultVal() {
	for(int i = 0 ; i < 3 ; i++) {
		for(int j = 0 ; j < 3 ; j++) {
			arr[i][j] = def;
		}
	}
}

// alternating between X and O
char changePlayer() {
	if(turn%2 == 0) {
		return 'X';
	}
	else {
		return 'O';
	}
}

// to get all the required values
void getValues() {
	player = changePlayer();
	again:	printf("[%c's turn]\n", player);
	do {
		printf("Enter row(1-3): ");
		scanf("%d", &row);
		printf("Enter column(1-3): ");
		scanf("%d", &col);
		if(arr[row-1][col-1] == 'X' || arr[row-1][col-1] == 'O') {
			printf("Already occupied!Please enter a new value!\n\n");
			goto again;
		}
	} while(row<1||row>3||col<1||col>3);
	printf("_____________________________\n\n");

	arr[row-1][col-1] = player;
}

// print the grid
void print() {
	printf("\n");
	for(int i = 0 ; i < 3 ; i++){
		printf("\t");
		for(int j = 0 ; j < 3 ; j++){
			printf("  %c", arr[i][j]);
		}
		printf("\n\n");
	}
}

// check the test cases
bool check() {
	// rows
	r1 = (arr[0][0] == arr[0][1]) && (arr[0][0] == arr[0][2]) && (arr[0][0] != def);
	r2 = (arr[1][0] == arr[1][1]) && (arr[1][0] == arr[1][2]) && (arr[1][0] != def);
	r3 = (arr[2][0] == arr[2][1]) && (arr[2][0] == arr[2][2]) && (arr[2][0] != def);
	// columns
	c1 = (arr[0][0] == arr[1][0]) && (arr[0][0] == arr[2][0]) && (arr[0][0] != def);
	c2 = (arr[0][1] == arr[1][1]) && (arr[0][1] == arr[2][1]) && (arr[0][1] != def);
	c3 = (arr[0][2] == arr[1][2]) && (arr[0][2] == arr[2][2]) && (arr[0][2] != def);
	// diagonals
	d1 = (arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]) && (arr[0][0] != def);
	d2 = (arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][0]) && (arr[0][2] != def);

	if(r1||r2||r3||c1||c2||c3||d1||d2) {
		printf("\n\t**** Player %c won! ****", player);
		return true;
	}
	else {
		return false;
	}
}

int main() {

	setDefaultVal();
	print();

	while(turn < 9 && check() == false) {
		check();
		getValues();
		turn++;
		print();
	}
	return 0;
}
