// Collatz's problem, 09.10.2012

#include <stdio.h>

int main() {
	
	int tests;
	int counter;
	int s;
	int index = 0;
	
	scanf ("%d", &tests);
	
	for (counter = 0; counter < tests; counter++) {
		
		index = 0;
		scanf ("%d", &s); // first element of a sequence given
		
		// following elements of a sequence are defined differently for even and odd numbers
		// counting, how many elements stand before the element which equals 1
		
		while (s != 1) {
			
			if (s % 2 != 0) {
				
				s = 3*s+1;
				index++;
				
			}
			else {
				
				s = s/2;
				index++;
				
			}
		}
		
		// printing this number
		 
		printf ("%d\n", index);
	}

	return 0;
}
