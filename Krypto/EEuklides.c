// Extended Euklides' Algorythm, 09.10.2012
// JUST A SKETCH

#include <stdio.h>

int main() {

    int a, b, q, r, nwd = 0;
    int xi1 = 1, xi2 = 0, xi = 1, yi2 = 0, yi1 = 1, yi = 0;
    
    scanf ("%d %d", &a, &b);
    q = a/b;
    r = a % b;
    nwd = b - nwd;
    yi = (q - 1) - yi;
    
    while (r != 0) {
    
                
          
    }
    
    
    while (b != 0) {
          b = getchar();      
    }
    return 0;
}
