// Gauss-Jordan's Elimination implementation
// 14.10.2012

#include <stdio.h>

int main() {
	
	float macierz[3][4];
	float wektor[3];
	float temp[4];
	int i,j,k;
	int n = 4;
	
	macierz[0][0] = 1.0;
	macierz[0][1] = 2.0;
	macierz[0][2] = 3.0;
	macierz[0][3] = 14.0;
	macierz[1][0] = 4.0;
	macierz[1][1] = 3.0;
	macierz[1][2] = -1.0;
	macierz[1][3] = 7.0;
	macierz[2][0] = 1.0;
	macierz[2][1] = -1.0;
	macierz[2][2] = 1.0;
	macierz[2][3] = 2.0;
	
	for (k = 0; k < n-1; k++) {
		
		for (i = 0; i < n; i++) {
			
			// temp holds k-th equation
			
			for (j = 0; j < n; j++) {
				
				temp[j] = macierz[k][j];
				
			}
			
			// temp divided by macierz[k][k]
			
			for (j = 0; j < n; j++) {
				
				temp[j] = temp[j] / macierz[k][k];
				
			}
			
			// temp multiplied by macierz[i][k]
			
			for (j = 0; j < n; j++) {
				
				temp[j] = temp[j] * macierz[i][k];
				
			}
			
			for (j = 0; j < n; j++) {
				
				if (i != k) {
					
					macierz[i][j] = macierz[i][j] - temp[j];
				}
				
			}
		}
		
	}
	
	
	for (i = 0; i < n-1; i++) {
		
		wektor[i] = macierz[i][n-1] / macierz[i][i];
		printf ("%f\n", wektor[i]);
	}
	
	
	return 0;
}
