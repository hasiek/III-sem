// Gauss-Jordan's Elimination implementation
// 13.10.2012

#include <stdio.h>

int main() {
	
	float macierz[4][4];
	float wektor[4];
	float temp;
	int i,j,k;
	int n = 4;
	
	macierz[0][0] = 1.0;
	macierz[0][1] = 5.0;
	macierz[0][2] = 9.0;
	macierz[0][3] = 6.0;
	macierz[1][0] = 7.0;
	macierz[1][1] = 1.0;
	macierz[1][2] = 3.0;
	macierz[1][3] = 9.0;
	macierz[2][0] = 12.0;
	macierz[2][1] = 5.0;
	macierz[2][2] = 7.0;
	macierz[2][3] = 4.0;
	macierz[3][0] = 10.0;
	macierz[3][1] = 2.0;
	macierz[3][2] = 8.0;
	macierz[3][3] = 6.0;
	
	for (k = 0; k < n; k++) {
		
		for (i = 0; i < n; i++) {
			
			temp = macierz[k][i]/macierz[k][k];
			temp = temp * macierz[i][k];
			//macierz[i][k] = macierz[i][k] - temp; - wrong; HOW TO OMMIT THE K-TH ROW?
		
		}
	}
	
	/*for (i = 0; i < n; i++) {
		
		for (j = 0; j < n; j++) {
			
			printf ("%f ", macierz[i][j]);
			
		}
		printf ("\n");
	} */
	
	
	return 0;
}
