#include <stdio.h>

int main() {
	
	char ptable[12];
	int pesel[12];
	int i, check, tests, counter;
	
	scanf ("%d", &tests);
	
	for (counter = 0; counter < tests; counter++) {
	
		fgets(ptable,sizeof ptable, stdin); // a number saved as a table of char
	
		// changing char to int =- 48 (ASCII value for 0)
	
		for (i = 0; i < 11; i++) {
		
			pesel[i] = ptable[i] - 48;
		
		} // a number saved as a table of int
	
		check = pesel[0]*1 + pesel[1]*3 + pesel[2]*7 + pesel[3]*9 + pesel[4]*1 + pesel[5]*3 + pesel[6]*7 + pesel[7]*9 + pesel[8]*1 + pesel[9]*3 + pesel[10]*1;
	
		if (check > 0 && check % 10 == 0) {
		
			printf ("D\n");
		}
		else {
		
			printf ("N\n");
		}
	}
	
	return 0;
}
