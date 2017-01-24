#include <stdio.h>

int main() {
	int a;
	do {
		printf("Enter val:\n");
		scanf("%d", &a);
	} while(a<3);
	return 0;
}