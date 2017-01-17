/*
TODO:
1. It's a tie msg
2. Putting constrains on input
4. Checking if the location is already occupied
*/
#include <stdio.h>

int arr[3][3];
int def = 0;
int row, col;
int player;
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
int changePlayer() {
	if(turn%2 == 0) {
		return 1;
	}
	else {
		return 2;
	}
}

// to get all the required values
void getValues() {
	//printf("\nEnter player- X/O: ");
	//scanf(" %c", &player);
	player = changePlayer();
	printf("[%d's turn]\n", player);
	printf("Enter row: ");
	scanf("%d", &row);
	printf("Enter column: ");
	scanf("%d", &col);
	printf("_____________________________\n\n");

	arr[row][col] = player;
}

// print the array
void print() {
	printf("\n");
	for(int i = 0 ; i < 3 ; i++){
		printf("\t");
		for(int j = 0 ; j < 3 ; j++){
			printf("  %d", arr[i][j]);
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

	if(r1 || r2 || r3 || c1 || c2 || c3 || d1 || d2) { 
		printf("\n\t**** Player %d won! ****", player);
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