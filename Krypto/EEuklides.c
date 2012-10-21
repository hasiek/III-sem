// Rozszerzony Algorytm Euklidesa, Kryptografia - laboratorium 1
// Katarzyna Huszcza, 21.10.2012

#include <stdio.h>

int main() {
	
	int r, q, a, b, nwd;
	int x, x1, x2, y, y1, y2;
	int aRead, bRead;
	
	scanf ("%d %d", &aRead, &bRead);
	
	// Sprawdzenie, czy a > b, jeśli nie, zamiana a z b przy użyciu pustej zmiennej
	
	if (bRead > aRead) {
	
	nwd = bRead;
	bRead = aRead;
	aRead = nwd;
	
	}
	
	// Przypisanie sczytanych wartości a i b do zmiennych roboczych, aby zachować wartości początkowe
	
	a = aRead;
	b = bRead;
	
	q = a / b;
	r = a % b;
	nwd = b;
	
	x2 = 1;
	x1 = 0;
	y2 = 0;
	y1 = 1;
	x = 1;
	y = y2 - (q-1) * y1;
	
	while (r != 0) {
		
		// Algorytm Euklidesa
		
		a = b;
		b = r;
		
		// Przechowywanie wsp. kombinacji liniowej - x2 sprzed dwóch iteracji, x1 sprzed jednej, x obecny
		 
		x = x2 - q*x1;
		x2 = x1;
		x1 = x;
		 
		y = y2 - q*y1;
		y2 = y1;
		y1 = y; 
		
		// Algorytm Euklidesa    
		 
		nwd = r;
		q = a / b;
		r = a % b;
	
	}
	
	if (y < 0) {
		
		printf("NWD(%d, %d) = %d, kombinacja liniowa: %d * %d + (%d) * %d\n", aRead, bRead, nwd, x, aRead, y, bRead);
		
	}
	else {
		
		printf("NWD(%d, %d) = %d, kombinacja liniowa: %d * %d + %d * %d\n", aRead, bRead, nwd, x, aRead, y, bRead);
		
	}
	
	return 0;
}
