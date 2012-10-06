#include <stdio.h>

int main() {
	
	int tests, n, licznik, i, first,next;
	int table[100];
	
	scanf ("%i", &tests);

	for (licznik = 0; licznik < tests; licznik++) {
        
        scanf ("%i", &n);
        scanf ("%i", &first);
        table[n-1] = first;
        for (i = 0; i < n-1; i++) {
            
            scanf ("%i", &next);
            table[i] = next;   
        }
        for (i = 0; i < n-1; i++) {
            
            printf ("%i ", table[i]);    
        }
        printf ("%i\n", table[n-1]);
	}

	return 0;
}
