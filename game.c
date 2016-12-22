#include <stdio.h>

int arr[3][3];
int row, col;
int player;
int turn = 0;
bool flag = false;

/*
void setDefaultVal() {
	for(int i = 0 ; i < 3 ; i++) {
		for(int j = 0 ; j < 3 ; j++) {
			arr[i][j] = 0;
		}
	}
}
*/

void getVal() {
	printf("\nEnter player- 1/2: ");
	scanf("%d", &player);

	printf("Enter co-ordinates: ");
	scanf("%d%d", &row, &col);
	printf("\n\n");

	arr[row][col] = player;
}

void print() {
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			printf("\t%d ",arr[i][j]);
		}
		printf("\n\n");
	}
}

bool check() {
	if( (arr[0][0] == arr[0][1]) && ((arr[0][0] && arr[0][1]) != 0 )) { // test cases
		printf("\n\t**** Player %d won! ****", player);
		return true;
	}
	else {
		return false;
	}
}

int main() {

	print();

	while(turn < 10 && check() == false) {
		check();
		getVal();
		print();
		turn++;	
		//printf("Turn:%d\n\n", turn);
	}

	return 0;
}



