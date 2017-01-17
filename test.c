#include <stdio.h>

int main() {
	int a = 1;
	int b = 1;
	int c = 1;
	bool t = (a == b == c) && (a != 1) ;
	if(t) {
		printf("TRUE\n");
	}
	else {
		printf("FALSE\n");
	}
	return 0;
}