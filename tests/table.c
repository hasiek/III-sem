#include <stdio.h>

int main() {
	
	char tkpk[4];
	int i;
	
	fgets (tkpk, sizeof tkpk, stdin);
	for (i = 0; i < 4; i++) {
		printf ("%c", tkpk[i]);
	}
	return 0;
}
