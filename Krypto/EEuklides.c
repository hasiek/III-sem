#include <stdio.h>

int main() {
	
	int r, q, a, b, nwd;
	int x, x1, x2, y, y1, y2;
	int aRead, bRead;
	
	aRead = 1547;
	bRead = 560;
	
	if (bRead > aRead) {
	
	nwd = bRead;
	bRead = aRead;
	aRead = nwd;
	
	}
	
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
		
		a = b;
		b = r;
		 
		x = x2 - q*x1;
		x2 = x1;
		x1 = x;
		 
		y = y2 - q*y1;
		y2 = y1;
		y1 = y;     
		 
		nwd = r;
		q = a / b;
		r = a % b;
	
	}
	
	printf("NWD(%d, %d) = %d, kombinacja liniowa: %d * %d + %d * %d\n", aRead, bRead, nwd, x, aRead, y, bRead);
 
	if (nwd == 1) {
		
		printf("%d * %d mod %d = 1", bRead, y, aRead);
	
	}
		
	return 0;
}
