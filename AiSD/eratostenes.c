// sito Eratostenesa, 13.10.2012

#include <stdio.h>
#include <math.h>

int main() {
	
	int tests;
	int counter, i;
	int numbers[10001];
	int checked;
	int max, maxSqrt;
	double maxD;
	int remover;
	
	// 'cleaning' the table
	
	for (counter = 0; counter < 10001; counter++) {
		
		numbers[counter] = counter;
		
	}
	
	max = 10000;
		
	maxD = (double) max;

    maxD = sqrt(maxD);
		
	maxSqrt = (int) maxD;
        
    // creating a table in which numbers fit to indexes; instead of 1 is 0 because 1 isn't needed
        
    for (i = 0; i <= max; i++) {
            
            numbers[i] = i;
            
    }
    numbers[1] = 0;
        
    // crossing out according to algorythm
        
    for (remover = 2; remover <= maxSqrt; remover++) {
        
        i = remover+1;
        
        if (numbers[remover] != 0) {
        
           while (i != max) {
            
                 if (numbers[i] % remover == 0) {
                               
                                numbers[i] = 0;
                               
                 }        
                 i++;
            }
        }
        
    }
    
    numbers[max] = 0;
    
    // having a table containing only prime numbers and zeros, checking can be done
    
    scanf ("%d", &tests);
    
    for (counter = 0; counter < tests; counter++) {
        
        scanf ("%d", &checked);
        
        if (numbers[checked] == 0) {
        
           printf ("NIE\n");                     
                             
        }
        else {
             
             printf ("TAK\n");
             
        }
        
	}
	
	return 0;
}
